#ifndef FRMLFOS_H
#define FRMLFOS_H


#include "frmlfo.h"

class frmLFOs:
        public ctrlComposite
{
public:
    frmLFOs(TargetProvider *synth, QWidget *parent);
};

#endif // FRMLFOS_H
