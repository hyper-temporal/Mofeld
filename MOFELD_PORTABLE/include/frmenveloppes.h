#ifndef FRMENVELOPPES_H
#define FRMENVELOPPES_H

#include "frmenveloppe.h"
#include "frmlfo.h"


class frmEnveloppes:
        public ctrlComposite
{
    QVector<CtrlParamLeaf*> _ctrls;
public:
    frmEnveloppes(TargetProvider *synth,
                  QWidget * parent);
 };

#endif // FRMENVELOPPES_H
