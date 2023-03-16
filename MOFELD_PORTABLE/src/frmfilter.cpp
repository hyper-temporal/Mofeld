#include "frmfilter.h"
#include "frmsynthctrl_rotary.h"
#include "frmsynthctrl_combobox.h"

frmFilter::frmFilter(
        TargetProvider *synth,
        int filternum,
        QString n,
        QWidget *parent)
    :ctrlSection(n, parent, QBoxLayout::LeftToRight )
{
    int offset;
    int typ,cuto,res,driv,curve,keyt,envam,enveloc,modsrc,modam,fmsrc,fmam,pan,pansrc,panamo;

    if(filternum<2){
      offset = filternum * 15;

      typ = 58 +offset;
      cuto=59 +offset;
      res=60 +offset;
      driv=61 +offset;
      curve=62 +offset;
      keyt=63 +offset;
      envam=64 +offset;
      enveloc=65 +offset;
      modsrc=66 +offset;
      modam=67 +offset;
      fmsrc=68 +offset;
      fmam=69 +offset;
      pan=70 +offset;
      pansrc=71 +offset;
      panamo=72 +offset;
    }
    else{
        throw ("bad filter number");
    }

    addCtrl(new frmSynthCtrl_combobox( parent ,synth, (typ),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (cuto),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (res),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_combobox( parent ,synth, (keyt),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (envam),VAccessor::accessInstrument,-64));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (enveloc),VAccessor::accessInstrument,-64));

    ctrlComposite * fsc = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (curve),VAccessor::accessInstrument));
    fsc->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (fmsrc),VAccessor::accessInstrument));

    addCtrl(fsc);

    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (driv),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (fmam),VAccessor::accessInstrument));


    ctrlComposite * fsc2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (modsrc),VAccessor::accessInstrument));
    fsc2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (pansrc),VAccessor::accessInstrument));
    addCtrl(fsc2);

    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (modam),VAccessor::accessInstrument,-64));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (panamo),VAccessor::accessInstrument,-64));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, (pan),VAccessor::accessInstrument));
//    AfterConstructor();
}




