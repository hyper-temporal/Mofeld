#include "frmmatrixslice.h"

#include "frmsynthctrl_rotary.h"
#include "frmsynthctrl_combobox.h"

frmMatrixSlice::frmMatrixSlice(
        TargetProvider *synth,
        int slicenum,
        QString n,
        QWidget *parent)
    :ctrlSection(n,parent, QBoxLayout::LeftToRight )
{
    int offset;
    if(slicenum<16){
        offset = slicenum *3;
    }
    else{
        throw ("bad matrix slice number");
    }
    ctrlComposite * fsc1 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (201+offset),VAccessor::accessInstrument));
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (202+offset),VAccessor::accessInstrument));

    ctrlComposite * fsc2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc2->addCtrl(new frmSynthCtrl_rotary( parent, synth, (203+offset),VAccessor::accessInstrument,-64));

    addCtrl(fsc1);
    addCtrl(fsc2);
//    AfterConstructor();


}
