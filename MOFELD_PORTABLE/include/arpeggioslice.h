#ifndef ARPEGGIOSLICE_H
#define ARPEGGIOSLICE_H

#include "ctrlcomposite.h"
class BlofeldReplica;
class Instrument;

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
