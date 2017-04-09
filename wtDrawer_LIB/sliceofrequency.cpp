#include "sliceofrequency.h"

SliceOFrequency::SliceOFrequency(const double * m, const double *p, QWidget *parent)
    :DrawerSlice(parent),_phase(p),_magnitude(m)
{}


void SliceOFrequency::paintDomain(QPainter &painter){
    paintFDomain(painter);
}

void SliceOFrequency::paintFDomain(QPainter &painter)
{

    painter.setBrush(QBrush(QColor(0,0,0)));
    painter.drawLine(QPoint(0,height()),QPoint(width(),height()));
    painter.drawLine(QPoint(0,0),QPoint(width(),0));

    int RedComp, GreenComp,BlueComp;

    double phase = *_phase;

    if(phase<-0.5)
    {
        RedComp= REDAT2+ 2*((phase+0.5))*(REDAT2-REDAT1);
        GreenComp= GREENAT2+ 2*((phase+0.5))*(GREENAT2-GREENAT1);
        BlueComp= BLUEAT2+ 2*((phase+0.5))*(BLUEAT2-BLUEAT1);
    }
    else if(phase<0)
    {
        RedComp= REDAT3- (2*phase)*(REDAT2-REDAT3);
        GreenComp= GREENAT3- (2*phase)*(GREENAT2-GREENAT3);
        BlueComp= BLUEAT3- (2*phase)*(BLUEAT2-BLUEAT3);
    }
    else if(phase<0.5)
    {
        RedComp= REDAT3 + (2*phase)*(REDAT4-REDAT3);
        GreenComp= GREENAT3 + (2*phase)*(GREENAT4-GREENAT3);
        BlueComp= BLUEAT3 + (2*phase)*(BLUEAT4-BLUEAT3);
    }
    else
    {
        RedComp= REDAT4+ 2*((phase-0.5))*(REDAT1-REDAT4);
        GreenComp= GREENAT4+ 2*((phase-0.5))*(GREENAT1-GREENAT4);
        BlueComp= BLUEAT4+ 2*((phase-0.5))*(BLUEAT1-BLUEAT4);
    }

    double mag = *_magnitude;
    int hauteurBarre =  height() - mag  * height()   ;
//ONDE PLEINE
    painter.fillRect(0,hauteurBarre,
                     width(),height()-hauteurBarre ,
                     QBrush(QColor(RedComp,GreenComp,BlueComp)));

    painter.setBrush(QBrush(QColor(0,0,0)));
    painter.drawLine(QPoint(0,height()),QPoint(0,hauteurBarre));
    painter.drawLine(QPoint(0,hauteurBarre),QPoint(width(),hauteurBarre));
    painter.drawLine(QPoint(width(),hauteurBarre),QPoint(width(),height()));

}


