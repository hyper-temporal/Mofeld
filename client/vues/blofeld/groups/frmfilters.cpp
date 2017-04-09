#include "frmfilters.h"

frmFilters::frmFilters(const BlofeldReplica *synth,Instrument *instru,QWidget * parent)
    :ctrlComposite(parent, QBoxLayout::LeftToRight )
{
    ctrlComposite * fsc = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc->addCtrl(new frmFilter(synth,instru,0,"FILTER1",parent));
    fsc->addCtrl(new frmSynthCtrl_button( parent ,synth, instru->editParametre(88)));
    fsc->addCtrl(new frmFilter(synth,instru,1,"FILTER2",parent));
    addCtrl(fsc);

    setLayout();
}
