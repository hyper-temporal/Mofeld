#ifndef FRMGENERATORS_H
#define FRMGENERATORS_H

#include "ctrlcomposite.h"


class frmGenerators:
        public ctrlComposite
{
public:
    frmGenerators(TargetProvider *synth,QWidget * parent);
};

#endif // FRMGENERATORS_H
