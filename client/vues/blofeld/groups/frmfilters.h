#ifndef FRMFILTERS_H
#define FRMFILTERS_H

#include "client/vues/blofeld/parts/frmfilter.h"

class frmFilters:
        public ctrlComposite
{
public:
    frmFilters(const BlofeldReplica *synth,Instrument *instru,QWidget * parent);
};

#endif // FRMFILTERS_H
