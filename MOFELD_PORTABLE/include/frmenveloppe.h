#ifndef FRMENVELOPPE_H
#define FRMENVELOPPE_H

#include "ctrlcomposite.h"
class BlofeldReplica;
class Instrument;

class frmEnveloppe :
        public ctrlSection
{
public:
    frmEnveloppe(
            TargetProvider *synth,
            int envnum,
            QString n,
            QWidget *parent);
};

#endif // FRMENVELOPPE_H
