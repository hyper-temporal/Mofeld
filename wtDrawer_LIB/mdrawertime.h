#ifndef MDRAWERTIME_H
#define MDRAWERTIME_H


#include "mdrawer.h"

class MDrawerTime
        :public MDrawer
{
public:
    MDrawerTime(SignalReal *m,QWidget * parent =0);
private:

    double getSampleValue(int pos);
    double getSampleValue(const QPoint &p);
    DrawerSlice * createSlice(int i,QWidget *p);
    void refresh();

};

#endif // MDRAWERTIME_H
