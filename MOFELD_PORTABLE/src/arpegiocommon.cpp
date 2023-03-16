#include "arpegiocommon.h"


#include "frmsynthctrl_combobox.h"
#include "frmsynthctrl_latchbutton.h"
#include "frmsynthctrl_rotary.h"


ArpegioCommon::ArpegioCommon(
        TargetProvider *synth,
        QString n,
        QWidget *parent)
    :ctrlSection(n,parent, QBoxLayout::LeftToRight)
{
    addCtrl(new frmSynthCtrl_combobox( parent, synth, (260),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_rotary( parent, synth, (257),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_button( parent, synth, (258),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, (249),VAccessor::accessInstrument));


    ctrlComposite * fsc1 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (255),VAccessor::accessInstrument));
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (254),VAccessor::accessInstrument));
    addCtrl(fsc1);


    ctrlComposite * fsc2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (253),VAccessor::accessInstrument));
    fsc2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (256),VAccessor::accessInstrument));
    addCtrl(fsc2);

    ctrlComposite * fsc3 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc3->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (251),VAccessor::accessInstrument));
    fsc3->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (252),VAccessor::accessInstrument));
    addCtrl(fsc3);

    ctrlComposite * fsc4 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc4->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (259),VAccessor::accessInstrument));
    fsc4->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (250),VAccessor::accessInstrument));
    addCtrl(fsc4);

}
