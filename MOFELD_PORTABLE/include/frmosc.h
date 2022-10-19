#ifndef FRMOSC_H
#define FRMOSC_H

#include "ctrlcomposite.h"
#include "frmcommon.h"

class frmOsc123:
        public ctrlSection
{
public:
    frmOsc123(const BlofeldReplica *synth,Instrument *instru,int oscnum,QString n, QWidget *parent);
};


class frmOscillators:
        public ctrlComposite
{
public:
    frmOscillators(const BlofeldReplica *synth,Instrument *instru, QWidget * parent);
};
#endif // FRMOSC_H
