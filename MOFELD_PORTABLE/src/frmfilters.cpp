#include "frmfilters.h"
#include "frmsynthctrl_latchbutton.h"

frmFilters::frmFilters(TargetProvider *synth,QWidget * parent)
    :ctrlComposite(parent, QBoxLayout::LeftToRight )
{
    ctrlComposite * fsc = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc->addCtrl(new frmFilter(synth,0,"FILTER1",parent));
    fsc->addCtrl(new frmSynthCtrl_button( parent ,synth, (88),VAccessor::accessInstrument));
    fsc->addCtrl(new frmFilter(synth,1,"FILTER2",parent));
    addCtrl(fsc);

    setLayout();
}
