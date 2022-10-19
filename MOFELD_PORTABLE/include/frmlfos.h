#ifndef FRMLFOS_H
#define FRMLFOS_H


#include "frmlfo.h"

class frmLFOs:
        public ctrlComposite
{
public:
    frmLFOs(const BlofeldReplica *synth,Instrument *instru, QWidget *parent);
};

#endif // FRMLFOS_H
