#ifndef BLOFELDMULTISLICE_H
#define BLOFELDMULTISLICE_H

#include "client/Common/ctrlcomposite.h"

class BlofeldMultiSlice
        :public ctrlSection
{
public:
    BlofeldMultiSlice(const BlofeldReplica *synth,const DumpMulti * multimess, int sclicenum,QString n, QWidget *parent);
};

#endif // BLOFELDMULTISLICE_H
