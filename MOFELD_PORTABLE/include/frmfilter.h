#ifndef FRMFILTER_H
#define FRMFILTER_H

#include "ctrlcomposite.h"
class Instrument;

class frmFilter:
        public ctrlSection
{
public:
    frmFilter(const BlofeldReplica *synth,Instrument *instru,int filternum,QString n,QWidget * parent);
};




#endif // FRMFILTER_H
