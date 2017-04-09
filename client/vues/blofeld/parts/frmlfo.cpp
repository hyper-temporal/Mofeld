#include "frmlfo.h"


frmLFO::frmLFO(const BlofeldReplica *synth,  Instrument *instru, int lfonum, QString n, QWidget *parent)
    :ctrlSection(n,parent, QBoxLayout::LeftToRight )
{
    int pshapeid,
        pspeedid,
        pphaseid,
        pfadeid,
        pdelayid,
        pktrkid,
        psyncid,
        pclkid;

    if(lfonum <3)
    {
        int offset = lfonum*8;

        pshapeid=125+offset;
        pspeedid=126+offset;
        psyncid=127+offset;
        pclkid=128+offset;
        pphaseid=129+offset;
        pdelayid=130+offset;
        pfadeid=131+offset;
        pktrkid=132+offset;
    }
    else{
        throw("le lfo est mal précisé");
    }
    ctrlComposite * fsc1 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(pshapeid)));
    fsc1->addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(pspeedid)));

    ctrlComposite * fsc2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(pphaseid)));
    ctrlComposite * fsc3 = new ctrlComposite(parent,QBoxLayout::LeftToRight);
    fsc3->addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(pfadeid),-64));
    fsc3->addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(pdelayid)));
    fsc2->addCtrl(fsc3);

    ctrlComposite * fsc4 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc4->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(pktrkid)));
    ctrlComposite * fsc5 = new ctrlComposite(parent,QBoxLayout::LeftToRight);
    fsc5->addCtrl(new frmSynthCtrl_button( parent ,synth, instru->editParametre(psyncid)));
    fsc5->addCtrl(new frmSynthCtrl_button( parent ,synth, instru->editParametre(pclkid)));
    fsc4->addCtrl(fsc5);

    addCtrl(fsc1);
    addCtrl(fsc2);
    addCtrl(fsc4);
//    AfterConstructor();
}

