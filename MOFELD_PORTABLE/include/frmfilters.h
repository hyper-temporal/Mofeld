#ifndef FRMFILTERS_H
#define FRMFILTERS_H

#include "frmfilter.h"

class frmFilters:
        public ctrlComposite
{
public:
    frmFilters(TargetProvider *synth, QWidget * parent);
};

#endif // FRMFILTERS_H
