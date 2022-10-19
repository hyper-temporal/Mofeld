#include "valuemgr.h"

int ValueMgr::createMask(int bitness){
    if((uint)bitness > sizeof(int)*8)throw("specification du registre invalide");
    int mask = (0b1<<bitness)-1;
    return mask;
}

void ValueMgr::setValue(int v){
    _value = v & _mask;
}

int ValueMgr::getValue()const{
    return _value;
}

int ValueMgr::getValue(int v)const{
    return v & _mask;

}

int ValueMgr:: getNewValue(int v)const
{
    return getNewValue(v,0,127);
}

int ValueMgr:: getNewValue(int v,int min, int max)const
{
    int result(v);
    int range=  max-min;
    if(range>0 && range<128){
        result = min +(std::rand()% (range+1));}
    return result ;
}

