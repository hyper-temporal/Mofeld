#ifndef FRMMODIFIER_H
#define FRMMODIFIER_H

#include "ctrlcomposite.h"

class Instrument;
class frmModifier:
        public ctrlSection
{
public:
    frmModifier(TargetProvider *synth,int modNum, QString nom,QWidget *parent);
};

#endif // FRMMODIFIER_H
