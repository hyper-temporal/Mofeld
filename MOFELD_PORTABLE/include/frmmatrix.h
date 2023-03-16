#ifndef FRMMATRIX_H
#define FRMMATRIX_H


#include "frmmatrixslice.h"
#include "frmmodifier.h"


class frmMatrix:
        public ctrlComposite
{
public:
    frmMatrix(TargetProvider *synth, QWidget *parent);
};


#endif // FRMMATRIX_H
