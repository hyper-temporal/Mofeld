#ifndef BLOFELDMULTISLICE_H
#define BLOFELDMULTISLICE_H

#include "ctrlcomposite.h"

class BlofeldReplica;
class DumpMulti;

class BlofeldMultiSlice
        :public ctrlSection
{
public:
    BlofeldMultiSlice(
            const BlofeldReplica *synth,
            const DumpMulti * multimess,
            int sclicenum,
            QString n,
            QWidget *parent);
};

#endif // BLOFELDMULTISLICE_H
