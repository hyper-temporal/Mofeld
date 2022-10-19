#include "mdrawerfrequency.h"
#include <QMouseEvent>
#include "stdlib.h"
#include <QDebug>

using namespace std;


MDrawerFrequency::MDrawerFrequency(SignalReal *s,QWidget *p )
    :MDrawer(s,p)
{
    _mode = DM_MAGNI;
}

//double MDrawerFrequency::getSampleValue(const QPoint &p)
//{
//    if( p.y() > height()) return 0.0;
//    else if( p.y() < 0)return 1.0;
//    else return  1.0 - (double)p.y()/height();
//}
#define _USE_MATH_DEFINES
#include <math.h>

void MDrawerFrequency::paintDomain(QPainter &painter)
{

    QVector<double>   vph =_model->getLanckosz(_model->getValuesPh(),width());
    auto vMg = _model->getValuesMg();

    int hauteur,hauteur1;
    double vm,vm1,vp;


    for(int i(0);i<width()-1;i++)
    {
        auto inx = (int)(vMg->count()* i/width());
        //CORRECTIONS d'oFFSET et scaling
        vm =  vMg->at(inx);
        vp =  vph.at(i)/(2*M_PI);
        //de bas en haut...
        hauteur=height()-height()*vm;
//couleur phase
        QColor c = scaleColor(_clr_White,getColorPhase(vp),getPhaseBrightness(vp));

        painter.setPen(QPen(c));
        painter.drawLine(QPoint(i, hauteur),
                         QPoint(i, height()));
        painter.setPen(QPen(_clr_Top));
        painter.drawPoint(i, hauteur);

    }
}
