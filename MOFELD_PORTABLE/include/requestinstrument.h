#ifndef REQUESTINSTRUMENT_H
#define REQUESTINSTRUMENT_H


#include "blofable.h"

class RequestInstrument: public Blofable
{

protected:

    void setAdressContent();
    void setDataContent();
    void setChecksum(){}
public:
    RequestInstrument();
    //en plus de la methode heritée
    std::vector<uchar> * getMessage(int macid,int chid);
    std::vector<uchar> * getMessage(int macid,int bankid, int pgmid);
    std::vector<uchar> * getAllSounds(int macid);
};

#endif // REQUESTINSTRUMENT_H
