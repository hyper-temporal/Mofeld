#include "frmlfos.h"

frmLFOs::frmLFOs(TargetProvider *synth,QWidget * parent)
    :ctrlComposite(parent, QBoxLayout::TopToBottom )
{

    addCtrl(new frmLFO(synth,0,"LFO1",parent));
    addCtrl(new frmLFO(synth,1,"LFO2",parent));
    addCtrl(new frmLFO(synth,2,"LFO3",parent));

    setLayout();
}
