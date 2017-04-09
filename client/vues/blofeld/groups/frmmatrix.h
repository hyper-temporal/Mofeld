#ifndef FRMMATRIX_H
#define FRMMATRIX_H


#include "client/vues/blofeld/parts/frmmatrixslice.h"
#include "client/vues/blofeld/parts/frmmodifier.h"


class frmMatrix:
        public ctrlComposite
{
public:
    frmMatrix(const BlofeldReplica *synth,Instrument *instru, QWidget *parent);
};


#endif // FRMMATRIX_H
