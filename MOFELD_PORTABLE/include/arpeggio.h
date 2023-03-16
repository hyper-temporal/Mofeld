#ifndef ARPEGGIO_H
#define ARPEGGIO_H

#include "ctrlcomposite.h"

class Arpeggio
        :public ctrlComposite
{
public:
    Arpeggio(TargetProvider *synth, QWidget *parent);
};

#endif // ARPEGGIO_H
