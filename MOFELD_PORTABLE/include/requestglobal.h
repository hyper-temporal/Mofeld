#ifndef REQUESTGLOBAL_H
#define REQUESTGLOBAL_H

#include "blofable.h"

class RequestGlobal:public Blofable
{

protected:
    void setAdressContent(){}
    virtual void setDataContent(){}
    virtual void setChecksum(){}
public:
    RequestGlobal():Blofable(9,0x4){}

};

#endif // REQUESTGLOBAL_H
