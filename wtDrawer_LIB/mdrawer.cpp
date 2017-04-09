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
}

void MDrawer::UpdateAll(){
    foreach(DrawerSlice *s,_slices){
        s->update();
    }

}
void MDrawer::UpdateOne(int id)
{
    _slices.at(id)->update();
}

void MDrawer::setSignal(SignalReal *m)
{
    _model=m;
    refresh();
    UpdateAll();
}


void MDrawer::mousePressEvent(QMouseEvent *me){
    QPoint p = mapFromGlobal(QCursor::pos());
    emit startFollow(getSampleNumber(me),getSampleValue(p));

}

void MDrawer::mouseMoveEvent(QMouseEvent *me){
    requestValue(me);
}

void MDrawer::mouseReleaseEvent(QMouseEvent *me){
    QPoint p = mapFromGlobal(QCursor::pos());
    emit stopFollow( getSampleNumber(me),getSampleValue(p));
}

void MDrawer::requestValue(QMouseEvent *me)
{
    QPoint p = mapFromGlobal(QCursor::pos());
    emit sendValue( getSampleNumber(me),getSampleValue(p));
}

int MDrawer::getSampleNumber(QMouseEvent *me)
{

    if(_slices.count()<1) throw("pas de slice");
    if(me->x() < 0  ) {
        return 0;
    }
    else if( me->x() >width() ){
        return _slices.count()-1;
    }

    double sliceWidth = (double)width()/_slices.count();

    if(sliceWidth==0)return 0;
    else{
        int ret = _slices.count() *(double)me->x()/width();
        if(ret>_slices.count()-1)return _slices.count()-1;
        if(ret < 0 )return 0;
        return ret;
    }


}


