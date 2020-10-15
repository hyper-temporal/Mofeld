#include "frmfilter.h"

frmFilter::frmFilter(const BlofeldReplica *synth, Instrument *instru,int filternum, QString n, QWidget *parent)
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

    addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(typ)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(cuto)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(res)));
    addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(keyt)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(envam),-64));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(enveloc),-64));

    ctrlComposite * fsc = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(curve)));
    fsc->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(fmsrc)));

    addCtrl(fsc);

    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(driv)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fmam)));


    ctrlComposite * fsc2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(modsrc)));
    fsc2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(pansrc)));
    addCtrl(fsc2);

    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(modam),-64));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(panamo),-64));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(pan)));
//    AfterConstructor();
}




