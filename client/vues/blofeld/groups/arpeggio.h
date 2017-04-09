#ifndef ARPEGGIO_H
#define ARPEGGIO_H

#include "client/Common/ctrlcomposite.h"
#include "client/vues/blofeld/parts/arpeggioslice.h"
#include "client/vues/blofeld/parts/arpegiocommon.h"

class Arpeggio
        :public ctrlComposite
{
public:
    Arpeggio(const BlofeldReplica *synth,Instrument *instru, QWidget *parent);
};

#endif // ARPEGGIO_H
