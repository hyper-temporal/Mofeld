#ifndef FRMMODIFIER_H
#define FRMMODIFIER_H

#include "client/Common/ctrlcomposite.h"

class frmModifier:
        public ctrlSection
{
public:
    frmModifier(const BlofeldReplica *synth, Instrument * instru,int modNum, QString nom,QWidget *parent);
};

#endif // FRMMODIFIER_H
