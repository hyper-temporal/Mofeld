#ifndef FRMCOMMON_H
#define FRMCOMMON_H

#include "client/Common/ctrlcomposite.h"

class frmCommon:
    public ctrlComposite
{
public:
    frmCommon(const BlofeldReplica *synth,Instrument *instru, QWidget * parent);
};

#endif // FRMCOMMON_H
