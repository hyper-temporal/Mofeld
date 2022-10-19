#ifndef FRMENVELOPPES_H
#define FRMENVELOPPES_H

#include "frmenveloppe.h"
#include "frmlfo.h"


class frmEnveloppes:
        public ctrlComposite
{
    QVector<CtrlParamLeaf*> _ctrls;
public:
    frmEnveloppes(const BlofeldReplica *synth,Instrument * instru,QWidget * parent);
 };

#endif // FRMENVELOPPES_H
