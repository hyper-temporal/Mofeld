#include "valuerange.h"

ValueRange::ValueRange(QString s,int b, int min , int max , int v )
    :ValueMgr(s,b,v) ,_min( min),_max(max)
{
    if(_min>_max){
        const int t(_min);
        _min = _max;
        _max = t;
    }
}


void ValueRange::setValue(int v){
    if(v >= _min && v<=_max){
        ValueMgr::setValue(v);
    }
}
int ValueRange::getValue(){
    return ValueMgr::getValue();
}

int ValueRange::getValue(int v){
    if(v < _min )
        return _min;
    else if(v > _max )
        return _max;
    else return v;
}
int ValueRange::getNewValue(int v){
    return ValueMgr::getNewValue(v,_min,_max);
}

int ValueRange::getNewValue(int v,int min, int max){
    if(min<_min)min=_min;
    if(max>_max)max=_max;
    return ValueMgr::getNewValue(v,min,max);
}
