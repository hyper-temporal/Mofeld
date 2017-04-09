#ifndef SLICEOTIME_H
#define SLICEOTIME_H
#include "wavedrawerslice.h"

class SliceOTime
        :public DrawerSlice
{
    const double *_amplitude;

public:
    SliceOTime(const double *v,QWidget *p);

    void paintDomain(QPainter &painter);
    void paintTDomain(QPainter &painter) ;
    void setModel(const double *v){
        _amplitude=v;
    }
};

#endif // SLICEOTIME_H
