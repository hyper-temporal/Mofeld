#ifndef FRMENVELOPPES_H
#define FRMENVELOPPES_H

#include "client/vues/blofeld/parts/frmenveloppe.h"
#include "client/vues/blofeld/parts/frmlfo.h"


class frmEnveloppes:
        public ctrlComposite
{
    QVector<CtrlParamLeaf*> _ctrls;
public:
    frmEnveloppes(const BlofeldReplica *synth,Instrument * instru,QWidget * parent);
 };

#endif // FRMENVELOPPES_H
