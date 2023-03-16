#ifndef FRMMATRIXSLICE_H
#define FRMMATRIXSLICE_H


#include "ctrlcomposite.h"

class frmMatrixSlice
:
        public ctrlSection
{
public:
    frmMatrixSlice(TargetProvider *synth, int slicenum, QString n,QWidget * parent);
};

#endif // FRMMATRIXSLICE_H
