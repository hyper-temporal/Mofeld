#ifndef ARPEGGIO_H
#define ARPEGGIO_H

#include "ctrlcomposite.h"
#include "arpeggioslice.h"
#include "arpegiocommon.h"

class Arpeggio
        :public ctrlComposite
{
public:
    Arpeggio(const BlofeldReplica *synth,Instrument *instru, QWidget *parent);
};

#endif // ARPEGGIO_H
