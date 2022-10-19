#ifndef FRMLFO_H
#define FRMLFO_H

#include "ctrlcomposite.h"

class Instrument;

class frmLFO:
        public ctrlSection
{
public:
    frmLFO(const BlofeldReplica *synth, Instrument *instru , int lfonum, QString n, QWidget *parent);
};



#endif // FRMLFO_H
