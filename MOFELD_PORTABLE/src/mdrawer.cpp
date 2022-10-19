#include "mdrawer.h"
#include <QMouseEvent>
#include <cmath>
#include <QDebug>

using namespace std;

MDrawer::MDrawer( SignalReal *m, QWidget *p)
    :QWidget(p),_model(m)
{

    QHBoxLayout *fly =new QHBoxLayout;
    fly->setSpacing(0);
    fly->setContentsMargins(0,0,0,0);
    setLayout(fly);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    _locked= *(new QVector<bool>(_model->countSamples()));
    foreach(int i,_locked){
        *(&i)=false;
    }

    installEventFilter(p);
}


void MDrawer::setSignal(SignalReal *m)
{
    _model=m;
    update();
}


void MDrawer::mousePressEvent(QMouseEvent *me)
{
    QPoint p = mapFromGlobal(QCursor::pos());
    emit startFollow(getSampleNumber(me),getSampleValue(p));

}

void MDrawer::mouseMoveEvent(QMouseEvent *me){
    QPoint p = mapFromGlobal(QCursor::pos());
    emit follow( getSampleNumber(me),getSampleValue(p));
}

void MDrawer::mouseReleaseEvent(QMouseEvent *me){
    QPoint p = mapFromGlobal(QCursor::pos());
    emit stopFollow( getSampleNumber(me),getSampleValue(p));
}


double MDrawer::getSampleValue(const QPoint &p)
{
    double fvalue ;
        if( p.y() > height()) fvalue = 0.0;
        else if( p.y() < 0)fvalue= 1.0;
        else return  fvalue =(1.0 - (double)p.y()/height());
        return fvalue;
}

//double MDrawer::getSampleValue(const QPoint &p)
//{
//    double ret;

//    if(height()<2) return 0.0;
//    if(p.y()<0){
//        return 1.0;
//    }
//    else if(p.y()>height())
//    {
//        return -1.0;
//    }
//    else
//    {
//        int offset = height()/2;
//        int sansOffset;

//        if(p.y()==offset)
//        {
//            return 0.0;
//        }
//        else if(p.y() > offset)
//        {
//            sansOffset = offset -p.y();
//        }else{
//            sansOffset = - (p.y()- offset);
//        }
//        ret = (double)2*sansOffset/height();
//    }
//    if(ret<-1.0){
//        ret= -1.0;
//    }
//    else if(ret>1.0)
//    {
//        ret= 1.0;
//    }
//    else if(ret < 0.001 && ret>-0.001)return 0.0;
//    return transposeValue( ret );
//}

int MDrawer::getSampleNumber(QMouseEvent *me)
{
    int SamplesCount = getSampleCount();
    if(me->x() < 0  ) {
        return 0;
    }
    else if( me->x() >=width() ){
        return SamplesCount-1;
    }

    double sliceWidth = (double)width()/SamplesCount;

    if(sliceWidth==0)return 0;
    else{
        int ret = SamplesCount *(double)me->x()/width();
        if(ret>SamplesCount-1)return SamplesCount-1;
        if(ret < 0 )return 0;
        return ret;
    }
}
QColor
ColBacklite(230 ,240,245),
ColBorder(150,190,230);

void MDrawer::paintEvent(QPaintEvent * pe)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QPen(ColBorder));
    painter.drawRect(QRect(0,0,width(),height()));
    painter.fillRect(QRect(0,0,width()-1,height()-1),ColBacklite);
    painter.setPen(QPen(QColor("#000000")));
    paintDomain(painter);
}


