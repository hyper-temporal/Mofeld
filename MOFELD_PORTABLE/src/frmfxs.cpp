#include "frmfxs.h"
#include "frmsynthctrl_latchbutton.h"


frmFXs::frmFXs(TargetProvider *synth, QWidget * parent)
    :ctrlComposite(parent, QBoxLayout::TopToBottom )
{
    addCtrl(new frmFilter(synth,0,"FILTER1",parent));
    addCtrl(new frmSynthCtrl_button( parent ,synth, (88),VAccessor::accessInstrument));
    addCtrl(new frmFilter(synth,1,"FILTER2",parent));
    frmFX1 = new frmFX(synth,0,"FX 01",parent);
    frmFX2 = new frmFX(synth,1,"FX 02",parent);

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
