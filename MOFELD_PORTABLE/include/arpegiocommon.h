#ifndef ARPEGIOCOMMON_H
#define ARPEGIOCOMMON_H

#include "ctrlcomposite.h"


class Instrument;

class ArpegioCommon
:
        public ctrlSection
{
public:
    ArpegioCommon( TargetProvider *synth,
                  QString n,
                  QWidget * parent);
};

#endif // ARPEGIOCOMMON_H
