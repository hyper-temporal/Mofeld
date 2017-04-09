#ifndef SLICEOFREQUENCY_H
#define SLICEOFREQUENCY_H

#include "mdrawerfrequency.h"

class SliceOFrequency
        :public DrawerSlice
{

    const double *_phase,*_magnitude;
protected:
    void paintDomain(QPainter &painter);
public:
    SliceOFrequency(const double*,const double*, QWidget *parent=0);
    void updateVue();
    void setModel(const double* vm,const double*vp){
        _magnitude=vm; _phase=vp;
    }

private:
    void paintFDomain(QPainter &painter);

};

#endif // SLICEOFREQUENCY_H
