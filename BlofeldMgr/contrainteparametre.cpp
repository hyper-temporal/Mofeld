#include "contrainteparametre.h"

#include "parametre.h"
#include "defs.h"

void Contrainte::restrict2Value(int v){
    _min=v;
    _max=v;
}

void Contrainte::updateMin(int v){
    if (v <= 0){
        _min = 0;
    }
    else if(v>=_max){
        _min=_max;
    }else {
        _min=v;
    }
}

void Contrainte::updateMax(int v){
    if (v >= 127){
        _max = 127;
    }
    else if(v<_min){
        _max=_min;
    }else {
        _max=v;
    }
}


int Contrainte::check(int v)
{
    if( v < _min ){
        return _min;
    }
    else if(v > _max ){
        return _max;
    }
    else{
        return v;
    }
}

Contrainte::Contrainte(int min ,int max)
    :_min(min),_max(max)
{
    if(min<=max){
        _min= min;
        _max= max;
    }else{
        _min=max;
        _max=min;
    }
}
Contrainte::Contrainte(const Contrainte *c){
    _min = c->_min;
    _max = c->_max;
}


int Contrainte::getSmallestMin(const Contrainte * co,const Contrainte * cn) const
{
    int min1 = co->getMinValue();
    int min2 = cn->getMinValue();
    if(min1<min2) return min1;
    else return min2;
}
int Contrainte::getSmallestMax(const Contrainte * co,const Contrainte * cn)const
{
    int max1 = co->getMaxValue();
    int max2 = cn->getMaxValue();
    if(max1<max2) return max1;
    else return max2;
}
int Contrainte::getTallestMin(const Contrainte * co,const Contrainte * cn)const
{
    int min1 = co->getMinValue();
    int min2 = cn->getMinValue();
    if(min1>min2) return min1;
    else return min2;
}
int Contrainte::getTallestMax(const Contrainte * co,const Contrainte * cn)const
{
    int max1 = co->getMaxValue();
    int max2 = cn->getMaxValue();
    if(max1>max2) return max1;
    else return max2;
}


Contrainte * Contrainte::getNewRestricted(const Contrainte * cn)const
{
    int min = getTallestMin(this,cn);
    int max = getSmallestMax(this,cn);
    return new Contrainte(min,max);
}

Contrainte * Contrainte::getNewExtended(const Contrainte * cn)const
{
    int min = getSmallestMin(this,cn);
    int max = getTallestMax(this,cn);
    return new Contrainte(min,max);
}

Contrainte * Contrainte::getNewKeepMins(const Contrainte * cn)const
{
    int min = getSmallestMin(this,cn);
    int max = getTallestMin(this,cn);
    return new Contrainte(min,max);
}

Contrainte * Contrainte::getNewKeepMaxs(const Contrainte * cn)const
{
    int min = getSmallestMax(this,cn);
    int max = getTallestMax(this,cn);
    return new Contrainte(min,max);
}



