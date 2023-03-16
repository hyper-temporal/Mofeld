#ifndef FRMOSC_H
#define FRMOSC_H

#include "ctrlcomposite.h"

class frmOsc123:
        public ctrlSection
{
public:
    frmOsc123(TargetProvider *synth,int oscnum,QString n, QWidget *parent);
};


class frmOscillators:
        public ctrlComposite
{
public:
    frmOscillators(TargetProvider *synth, QWidget * parent);
};
#endif // FRMOSC_H
