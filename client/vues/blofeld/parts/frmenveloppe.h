#ifndef FRMENVELOPPE_H
#define FRMENVELOPPE_H

#include "client/Common/ctrlcomposite.h"

class frmEnveloppe :
        public ctrlSection
{
public:
    frmEnveloppe(const BlofeldReplica *synth,Instrument *instru,int envnum,QString n, QWidget *parent);
};

#endif // FRMENVELOPPE_H
