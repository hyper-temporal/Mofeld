#include "frmgenerators.h"

#include "frmosc.h"


frmGenerators::frmGenerators(TargetProvider *synth, QWidget *parent)
    :ctrlComposite(parent, QBoxLayout::LeftToRight )
{
    addCtrl(new frmOscillators(synth,parent));
    setLayout();
}
