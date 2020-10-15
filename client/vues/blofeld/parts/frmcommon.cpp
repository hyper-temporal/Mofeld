#include "frmcommon.h"


frmCommon::frmCommon(const BlofeldReplica *synth, Instrument *instru, QWidget *parent)
    :ctrlComposite(parent, QBoxLayout::LeftToRight )
{

    ctrlSection * section6 = new ctrlSection("AMP",parent,QBoxLayout::LeftToRight);

    section6->addCtrl(new frmSynthCtrl_rotary( parent , synth, instru->editParametre(89)));
    section6->addCtrl(new frmSynthCtrl_rotary( parent , synth, instru->editParametre(90)));
    section6->addCtrl(new frmSynthCtrl_combobox( parent , synth, instru->editParametre(91)));
    section6->addCtrl(new frmSynthCtrl_rotary( parent , synth, instru->editParametre(92),-64));
    addCtrl(section6);


    ctrlSection * section0 = new ctrlSection("PITCH",parent,QBoxLayout::LeftToRight);
    section0->addCtrl(new frmSynthCtrl_combobox( parent , synth, instru->editParametre(39)));
    section0->addCtrl(new frmSynthCtrl_rotary( parent , synth, instru->editParametre(40),-64));
    addCtrl(section0);


    ctrlSection * section3 = new ctrlSection("VOICE",parent,QBoxLayout::LeftToRight);
    ctrlComposite * sub3 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    sub3->addCtrl(new frmSynthCtrl_combobox( parent , synth, instru->editParametre(44)));
    sub3->addCtrl(new frmSynthCtrl_combobox( parent , synth, instru->editParametre(45)));
    section3->addCtrl(sub3);
    section3->addCtrl(new frmSynthCtrl_rotary( parent , synth, instru->editParametre(46)));
    addCtrl(section3);

    ctrlSection * section2 = new ctrlSection("GLIDE",parent,QBoxLayout::LeftToRight);
    ctrlComposite * sub2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    sub2->addCtrl(new frmSynthCtrl_combobox( parent , synth, instru->editParametre(41)));
    sub2->addCtrl(new frmSynthCtrl_combobox( parent , synth, instru->editParametre(42)));
    section2->addCtrl(sub2);
    section2->addCtrl(new frmSynthCtrl_rotary( parent , synth, instru->editParametre(43)));
    addCtrl(section2);

    ctrlSection * section4 = new ctrlSection("RING",parent,QBoxLayout::LeftToRight);
    section4->addCtrl(new frmSynthCtrl_rotary( parent , synth, instru->editParametre(56)));
    section4->addCtrl(new frmSynthCtrl_rotary( parent , synth, instru->editParametre(57)));
    addCtrl(section4);

    ctrlSection * section5 = new ctrlSection("NOISE",parent,QBoxLayout::LeftToRight);
    section5->addCtrl(new frmSynthCtrl_rotary( parent , synth, instru->editParametre(53)));
    section5->addCtrl(new frmSynthCtrl_rotary( parent , synth, instru->editParametre(54)));
    section5->addCtrl(new frmSynthCtrl_rotary( parent , synth, instru->editParametre(55),-64));
    addCtrl(section5);


//    AfterConstructor();
}
