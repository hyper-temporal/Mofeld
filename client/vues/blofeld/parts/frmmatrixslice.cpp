#include "frmmatrixslice.h"


frmMatrixSlice::frmMatrixSlice(const BlofeldReplica *synth, Instrument *instru,int slicenum, QString n, QWidget *parent)
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
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(201+offset)));
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(202+offset)));

    ctrlComposite * fsc2 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc2->addCtrl(new frmSynthCtrl_rotary( parent, synth, instru->editParametre(203+offset),-64));

    addCtrl(fsc1);
    addCtrl(fsc2);
//    AfterConstructor();


}
