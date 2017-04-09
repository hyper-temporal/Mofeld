#ifndef IREALSIGNAL_H
#define IREALSIGNAL_H

#include <math.h>

class IRealSignal
{
protected:
    int _size;

public:
    IRealSignal(int size);
    void setSize(int size);
};

#endif // IREALSIGNAL_H
