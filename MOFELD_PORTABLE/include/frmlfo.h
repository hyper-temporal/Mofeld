#ifndef FRMLFO_H
#define FRMLFO_H

#include "ctrlcomposite.h"

class Instrument;

class frmLFO:
        public ctrlSection
{
public:
    frmLFO(TargetProvider *synth, int lfonum, QString n, QWidget *parent);
};



#endif // FRMLFO_H
