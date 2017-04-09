#ifndef MDRAWERFREQUENCY_H
#define MDRAWERFREQUENCY_H


#include "mdrawer.h"
#include "sliceofrequency.h"

class MDrawerFrequency
        :public MDrawer
{


public:

    MDrawerFrequency(SignalReal *s,QWidget * parent =0);
    void setDrawModePhase();
    void setDrawModeMAgnitude();

private:
    double getSampleValue(int p);
    double getSampleValue(const QPoint &p);
    DrawerSlice * createSlice(int i,QWidget *p);
    void refresh();

};
#endif // MDRAWERFREQUENCY_H
