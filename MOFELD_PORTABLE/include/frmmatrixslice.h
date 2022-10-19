#ifndef FRMMATRIXSLICE_H
#define FRMMATRIXSLICE_H


#include "ctrlcomposite.h"
class Instrument;

class frmMatrixSlice
:
        public ctrlSection
{
public:
    frmMatrixSlice(const BlofeldReplica *synth, Instrument * instru, int slicenum, QString n,QWidget * parent);
};

#endif // FRMMATRIXSLICE_H
