#ifndef MESSAGEBLOFELD_H
#define MESSAGEBLOFELD_H

#include "sysexable.h"


//ce sera plutot synthable : getStructure + setStructure
class Blofable
        :public Sysexable
{
public:
    Blofable(const int s,const int type);
    QString getStructureName();
    QString getInstrument(int adresse);
    int getDevice();
    void setDevice(const int d);
    std::vector<uchar> * getMessage(int macid);
protected:
private:
    //gerer par marque...
    void setManufacturer();
    //gerer par model...
    void setDeviceModel();
    //gerer par device...
    void setDevice();
    void setType(const int t);
};



#endif // MESSAGEBLOFELD_H
