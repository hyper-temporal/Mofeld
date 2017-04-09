#include "sliceotime.h"

SliceOTime::SliceOTime(const double *v, QWidget *p)
    :DrawerSlice(p), _amplitude(v)
{}

void SliceOTime::paintDomain(QPainter &painter){
    paintTDomain(painter);
}

void SliceOTime::paintTDomain(QPainter &painter)
{
    painter.setBrush(QBrush(QColor(0,0,0)));
    painter.drawLine(QPoint(0,height()),QPoint(width(),height()));
    painter.drawLine(QPoint(0,0),QPoint(width(),0));

    double centre ,longueur;

    double _sampleValue= *_amplitude;
    centre = height()/2.0;
    longueur = _sampleValue *centre;

    painter.setBrush(QBrush(QColor(0,0,0)));
    painter.drawLine(QPoint(0,height()/2),QPoint(width(),height()/2));
//ONDE PLEINE
    if(_sampleValue>0){
        painter.translate(0,centre-longueur);
        painter.fillRect(0,0,
                         width(),longueur,
                         QBrush(QColor(150,100,100)));
    }else{
        painter.translate(0,centre);
        painter.fillRect(0,0,
                         width(),-longueur,
                         QBrush(QColor(100,150,150)));
    }

}

