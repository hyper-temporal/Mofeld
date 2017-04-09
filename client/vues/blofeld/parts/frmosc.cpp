#include "frmosc.h"

frmOsc123::frmOsc123(const BlofeldReplica *synth,Instrument * instru, int oscnum,QString n, QWidget *parent)
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
    fc0->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(shap),QBoxLayout::LeftToRight));
    fc0->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(oct),QBoxLayout::LeftToRight));
    fc0->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(semi),QBoxLayout::LeftToRight));
    addCtrl(fc0);

    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(det),-64));

    ctrlComposite * fc = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fc->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(fmsrc)));
    fc->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(pwmsrc)));
    addCtrl(fc);

    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(pwm)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(pwmamo),-64));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fmamo)));

    ctrlComposite * fc1 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(keyt),QBoxLayout::LeftToRight));
    fc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(bend),QBoxLayout::LeftToRight));
    fc1->addCtrl(new frmSynthCtrl_button( parent ,synth, instru->editParametre(limit),true,QBoxLayout::LeftToRight));
    addCtrl(fc1);

    ctrlComposite * fc2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fc2->addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(brill)));
    addCtrl(fc2);

    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(lev)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(bal),-64));

}

frmOscillators::frmOscillators(const BlofeldReplica *synth,Instrument *instru, QWidget *parent)
    :ctrlComposite(parent, QBoxLayout::TopToBottom )
{
    addCtrl( new frmCommon(synth, instru,parent));
    addCtrl( new frmOsc123(synth, instru,0,"OSC1",parent));
    addCtrl( new frmOsc123(synth,instru,1,"OSC2",parent));
    addCtrl( new frmOsc123(synth,instru,2,"OSC3",parent));
}
