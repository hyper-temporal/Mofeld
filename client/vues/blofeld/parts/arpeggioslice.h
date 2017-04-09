#ifndef ARPEGGIOSLICE_H
#define ARPEGGIOSLICE_H

#include "client/Common/ctrlcomposite.h"

class ArpeggioSlice
:
        public ctrlSection
{
public:
    ArpeggioSlice(const BlofeldReplica *synth,
                  Instrument * instru,
                  int slicenum,
                  QString n,
                  QWidget * parent);
};
#endif // ARPEGGIOSLICE_H
