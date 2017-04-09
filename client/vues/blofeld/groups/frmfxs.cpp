#include "frmfxs.h"


frmFXs::frmFXs(const BlofeldReplica *synth, Instrument *instru,QWidget * parent)
    :ctrlComposite(parent, QBoxLayout::TopToBottom )
{
    addCtrl(new frmFilter(synth,instru,0,"FILTER1",parent));
    addCtrl(new frmSynthCtrl_button( parent ,synth, instru->editParametre(88)));
    addCtrl(new frmFilter(synth,instru,1,"FILTER2",parent));
    frmFX1 = new frmFX(synth,instru,0,"FX 01",parent);
    frmFX2 = new frmFX(synth,instru,1,"FX 02",parent);

    addCtrl(frmFX1);
    addCtrl(frmFX2);

    setLayout();
}

void frmFXs::updateForm(  int fxNum , int fxType)
{
    ctrlComponent * c;
    if(fxNum == 0){
        c=    _ctrls.at(3);
    }else if(fxNum == 1){
        c=    _ctrls.at(4);
    }else return;

    frmFX * ctrl = dynamic_cast<frmFX *>(c);
    if(ctrl!=NULL){

        ctrl->setFX(fxNum,fxType);
    }
}
