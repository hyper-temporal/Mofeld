#ifndef FRMGENERATORS_H
#define FRMGENERATORS_H

#include "client/vues/blofeld/parts/frmosc.h"


class frmGenerators:
        public ctrlComposite
{
public:
    frmGenerators(const BlofeldReplica *synth,Instrument * instru,QWidget * parent);
};

#endif // FRMGENERATORS_H
