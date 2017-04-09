#ifndef FRMFX1_H
#define FRMFX1_H

#include "client/Common/ctrlcomposite.h"
#include "client/vues/blofeld/parts/frmfx.h"
#include "client/vues/blofeld/parts/frmfilter.h"
class frmFXs:
        public ctrlComposite
{
    frmFX *frmFX1,*frmFX2;
public:
    frmFXs(const BlofeldReplica *synth,Instrument *instru,QWidget * parent);
    void updateForm( int fxNum, int fxType);
};

#endif // FRMFX1_H
