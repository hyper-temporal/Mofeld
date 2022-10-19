#ifndef REQUESTWAVE_H
#define REQUESTWAVE_H

#include "blofable.h"


class RequestWave: public Blofable
{
public:
    RequestWave(uchar);
    std::vector<uchar> * getMessage(int macid,int tid, int wid);
private:

    void setAdressContent();
    void setDataContent();
    void setChecksum();
};

#endif // REQUESTWAVE_H
