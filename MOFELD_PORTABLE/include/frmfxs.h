#ifndef FRMFX1_H
#define FRMFX1_H

#include "ctrlcomposite.h"
#include "frmfx.h"
#include "frmfilter.h"
class frmFXs:
        public ctrlComposite
{
    frmFX *frmFX1,*frmFX2;
public:
    frmFXs(const BlofeldReplica *synth,Instrument *instru,QWidget * parent);
    void updateForm( int fxNum, int fxType);
};

#endif // FRMFX1_H
