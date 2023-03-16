#include "frmcommon.h"

#include "blofeldreplica.h"
#include "frmsynthctrl_rotary.h"
#include "frmsynthctrl_combobox.h"

frmCommon::frmCommon(TargetProvider *synth, QWidget *parent)
    :ctrlComposite(parent, QBoxLayout::LeftToRight )
{

    ctrlSection * section6 = new ctrlSection("AMP",parent,QBoxLayout::LeftToRight);

    section6->addCtrl(new frmSynthCtrl_rotary( parent , synth, (89), VAccessor::accessInstrument));
    section6->addCtrl(new frmSynthCtrl_rotary( parent , synth, (90),VAccessor::accessInstrument));
    section6->addCtrl(new frmSynthCtrl_combobox( parent , synth, (91),VAccessor::accessInstrument));
    section6->addCtrl(new frmSynthCtrl_rotary( parent , synth, (92),VAccessor::accessInstrument,-64));
    addCtrl(section6);


    ctrlSection * section0 = new ctrlSection("PITCH",parent,QBoxLayout::LeftToRight);
    section0->addCtrl(new frmSynthCtrl_combobox( parent , synth, (39),VAccessor::accessInstrument));
    section0->addCtrl(new frmSynthCtrl_rotary( parent , synth, (40),VAccessor::accessInstrument,-64));
    addCtrl(section0);


    ctrlSection * section3 = new ctrlSection("VOICE",parent,QBoxLayout::LeftToRight);
    ctrlComposite * sub3 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    sub3->addCtrl(new frmSynthCtrl_combobox( parent , synth, (44),VAccessor::accessInstrument));
    sub3->addCtrl(new frmSynthCtrl_combobox( parent , synth, (45),VAccessor::accessInstrument));
    section3->addCtrl(sub3);
    section3->addCtrl(new frmSynthCtrl_rotary( parent , synth, (46),VAccessor::accessInstrument));
    addCtrl(section3);

    ctrlSection * section2 = new ctrlSection("GLIDE",parent,QBoxLayout::LeftToRight);
    ctrlComposite * sub2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    sub2->addCtrl(new frmSynthCtrl_combobox( parent , synth, (41),VAccessor::accessInstrument));
    sub2->addCtrl(new frmSynthCtrl_combobox( parent , synth, (42),VAccessor::accessInstrument));
    section2->addCtrl(sub2);
    section2->addCtrl(new frmSynthCtrl_rotary( parent , synth, (43),VAccessor::accessInstrument));
    addCtrl(section2);

    ctrlSection * section4 = new ctrlSection("RING",parent,QBoxLayout::LeftToRight);
    section4->addCtrl(new frmSynthCtrl_rotary( parent , synth, (56),VAccessor::accessInstrument));
    section4->addCtrl(new frmSynthCtrl_rotary( parent , synth, (57),VAccessor::accessInstrument));
    addCtrl(section4);

    ctrlSection * section5 = new ctrlSection("NOISE",parent,QBoxLayout::LeftToRight);
    section5->addCtrl(new frmSynthCtrl_rotary( parent , synth, (53),VAccessor::accessInstrument));
    section5->addCtrl(new frmSynthCtrl_rotary( parent , synth, (54),VAccessor::accessInstrument));
    section5->addCtrl(new frmSynthCtrl_rotary( parent , synth, (55),VAccessor::accessInstrument,-64));
    addCtrl(section5);


//    AfterConstructor();
}
