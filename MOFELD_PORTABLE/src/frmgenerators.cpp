#include "frmgenerators.h"

frmGenerators::frmGenerators(const BlofeldReplica *synth,Instrument *instru, QWidget *parent)
    :ctrlComposite(parent, QBoxLayout::LeftToRight )
{
    addCtrl(new frmOscillators(synth,instru,parent));
    setLayout();
}
