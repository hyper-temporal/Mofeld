#include "frmlfo.h"
#include "instrument.h"

#include "frmsynthctrl_combobox.h"
#include "frmsynthctrl_latchbutton.h"
#include "frmsynthctrl_rotary.h"
#include "frmsynthctrl_sliderh.h"

#include "arrangement.h"

frmLFO::frmLFO(
        TargetProvider *synth,
        int lfonum,
        QString n,
        QWidget *parent)
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
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (pshapeid),VAccessor::accessInstrument));
    fsc1->addCtrl(new frmSynthCtrl_rotary( parent ,synth, (pspeedid),VAccessor::accessInstrument));

    ctrlComposite * fsc2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (pphaseid),VAccessor::accessInstrument));
    ctrlComposite * fsc3 = new ctrlComposite(parent,QBoxLayout::LeftToRight);
    fsc3->addCtrl(new frmSynthCtrl_rotary( parent ,synth, (pfadeid),VAccessor::accessInstrument,-64));
    fsc3->addCtrl(new frmSynthCtrl_rotary( parent ,synth, (pdelayid),VAccessor::accessInstrument));
    fsc2->addCtrl(fsc3);

    ctrlComposite * fsc4 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc4->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (pktrkid),VAccessor::accessInstrument));
    ctrlComposite * fsc5 = new ctrlComposite(parent,QBoxLayout::LeftToRight);
    fsc5->addCtrl(new frmSynthCtrl_button( parent ,synth, (psyncid),VAccessor::accessInstrument));
    fsc5->addCtrl(new frmSynthCtrl_button( parent ,synth, (pclkid),VAccessor::accessInstrument));
    fsc4->addCtrl(fsc5);

    addCtrl(fsc1);
    addCtrl(fsc2);
    addCtrl(fsc4);
//    AfterConstructor();
}

