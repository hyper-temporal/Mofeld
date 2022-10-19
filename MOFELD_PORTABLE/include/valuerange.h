#ifndef VALUERANGE_H
#define VALUERANGE_H

#include "valuemgr.h"

class ValueRange
        :public ValueMgr
{
    int _min,_max;
 public:
    ValueRange(QString s, int bitness, int min, int max,int v=0);
    ValueRange(const ValueRange &other)
        :ValueMgr(other),_min(other._min),_max(other._max){}
    void setValue(int v);
    int getValue();
    int getValue(int v);
    int getNewValue(int v);
    int getNewValue(int v,int min, int max);

};


#endif // VALUERANGE_H
