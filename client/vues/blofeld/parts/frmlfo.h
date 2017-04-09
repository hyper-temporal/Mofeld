#ifndef FRMLFO_H
#define FRMLFO_H

#include "client/Common/ctrlcomposite.h"

class frmLFO:
        public ctrlSection
{
public:
    frmLFO(const BlofeldReplica *synth, Instrument *instru , int lfonum, QString n, QWidget *parent);
};



#endif // FRMLFO_H
