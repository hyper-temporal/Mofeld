#include "frmosc.h"

#include "frmsynthctrl_rotary.h"
#include "frmsynthctrl_combobox.h"
#include "frmsynthctrl_latchbutton.h"
#include "frmcommon.h"

frmOsc123::frmOsc123(TargetProvider *synth, int oscnum,QString n, QWidget *parent)
    :ctrlSection(n,parent, QBoxLayout::LeftToRight )
{
    int
            oct,
            semi,
            det,
            bend,
            keyt,
            fmsrc,
            fmamo,
            shap,
            pwm,
            pwmsrc,
            pwmamo,
            limit,
            brill,
            lev,bal
            ;

    if(oscnum<3)
    {
        int offset =  oscnum * 13;

        oct=0 + offset;
        semi=1+ offset;
        det=2+ offset;
        bend=3+ offset;
        keyt=4+ offset;
        fmsrc=5+ offset;
        fmamo=6+ offset;
        shap=7+ offset;
        pwm=8+ offset;
        pwmsrc=9+ offset;
        pwmamo=10+ offset;
        limit=11+ offset;
        brill=12+ offset;
        lev=47+ oscnum*2;
        bal=48+ oscnum*2;
    }
    else{
        throw("l'enveloppe est mal précisée");
    }

    ctrlComposite * fc0 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fc0->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (shap), VAccessor::accessInstrument,QBoxLayout::LeftToRight));
    fc0->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (oct), VAccessor::accessInstrument,QBoxLayout::LeftToRight));
    fc0->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (semi), VAccessor::accessInstrument,QBoxLayout::LeftToRight));
    addCtrl(fc0);

    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (det),VAccessor::accessInstrument, -64));

    ctrlComposite * fc = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fc->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (fmsrc),VAccessor::accessInstrument));
    fc->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (pwmsrc),VAccessor::accessInstrument));
    addCtrl(fc);

    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (pwm),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (pwmamo),VAccessor::accessInstrument,-64));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (fmamo),VAccessor::accessInstrument));

    ctrlComposite * fc1 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (keyt), VAccessor::accessInstrument,QBoxLayout::LeftToRight));
    fc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (bend), VAccessor::accessInstrument,QBoxLayout::LeftToRight));
    fc1->addCtrl(new frmSynthCtrl_button( parent ,synth, (limit), VAccessor::accessInstrument,true,QBoxLayout::LeftToRight));
    addCtrl(fc1);

    ctrlComposite * fc2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fc2->addCtrl(new frmSynthCtrl_rotary( parent ,synth, (brill),VAccessor::accessInstrument));
    addCtrl(fc2);

    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (lev),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (bal),VAccessor::accessInstrument,-64));

}

frmOscillators::frmOscillators(TargetProvider *synth, QWidget *parent)
    :ctrlComposite(parent, QBoxLayout::TopToBottom )
{
    addCtrl( new frmCommon(synth,parent));
    addCtrl( new frmOsc123(synth,0,"OSC1",parent));
    addCtrl( new frmOsc123(synth,1,"OSC2",parent));
    addCtrl( new frmOsc123(synth,2,"OSC3",parent));
}
