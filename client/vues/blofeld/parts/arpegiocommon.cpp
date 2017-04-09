#include "arpegiocommon.h"


ArpegioCommon::ArpegioCommon(const BlofeldReplica *synth,Instrument *instru, QString n, QWidget *parent)
    :ctrlSection(n,parent, QBoxLayout::LeftToRight)
{
    addCtrl(new frmSynthCtrl_combobox( parent, synth, instru->editParametre(260)));
    addCtrl(new frmSynthCtrl_rotary( parent, synth, instru->editParametre(257)));
    addCtrl(new frmSynthCtrl_button( parent, synth, instru->editParametre(258)));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, instru->editParametre(249)));


    ctrlComposite * fsc1 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(255)));
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(254)));
    addCtrl(fsc1);


    ctrlComposite * fsc2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(253)));
    fsc2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(256)));
    addCtrl(fsc2);

    ctrlComposite * fsc3 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc3->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(251)));
    fsc3->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(252)));
    addCtrl(fsc3);

    ctrlComposite * fsc4 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc4->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(259)));
    fsc4->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(250)));
    addCtrl(fsc4);

}
