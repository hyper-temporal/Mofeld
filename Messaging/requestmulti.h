#ifndef UNKNOWNREQUEST_H
#define UNKNOWNREQUEST_H

#include "blofable.h"

class RequestMulti:public Blofable
{
    void setAdressContent();
    void setDataContent();
    void setChecksum();
public:
    RequestMulti();
    std::vector<uchar> * getMessage(int macid, int ad2);
};

#endif // UNKNOWNREQUEST_H
