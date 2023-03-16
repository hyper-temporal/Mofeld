#ifndef FRMCOMMON_H
#define FRMCOMMON_H

#include "ctrlcomposite.h"
class BlofeldReplica;
class Instrument;

class frmCommon:
    public ctrlComposite
{
public:
    frmCommon(TargetProvider *synth, QWidget * parent);
};

#endif // FRMCOMMON_H
