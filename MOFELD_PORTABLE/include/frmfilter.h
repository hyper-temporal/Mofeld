#ifndef FRMFILTER_H
#define FRMFILTER_H

#include "ctrlcomposite.h"
class Instrument;

class frmFilter:
        public ctrlSection
{
public:
    frmFilter(TargetProvider *synth,int filternum,QString n,QWidget * parent);
};




#endif // FRMFILTER_H
