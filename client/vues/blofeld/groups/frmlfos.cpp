#include "frmlfos.h"

frmLFOs::frmLFOs(const BlofeldReplica *synth, Instrument *instru,QWidget * parent)
    :ctrlComposite(parent, QBoxLayout::TopToBottom )
{

    addCtrl(new frmLFO(synth,instru,0,"LFO1",parent));
    addCtrl(new frmLFO(synth,instru,1,"LFO2",parent));
    addCtrl(new frmLFO(synth,instru,2,"LFO3",parent));

    setLayout();
}
