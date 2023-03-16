#ifndef ARPEGGIOSLICE_H
#define ARPEGGIOSLICE_H

#include "ctrlcomposite.h"
class TargetProvider;
class Instrument;

class ArpeggioSlice
:
        public ctrlSection
{
public:
    ArpeggioSlice( TargetProvider *synth,
                   int slicenum,
                  QString n,
                  QWidget * parent);
};
#endif // ARPEGGIOSLICE_H
