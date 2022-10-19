#include "arpeggioslice.h"

#include "frmsynthctrl_combobox.h"
#include "instrument.h"


ArpeggioSlice::ArpeggioSlice(const BlofeldReplica *synth, Instrument *instru,int slicenum, QString n, QWidget *parent)
    :ctrlSection(n,parent, QBoxLayout::TopToBottom )
{
    int offset1,offset2;
    if(slicenum<16){
        offset1 = slicenum *3;
        offset2 = slicenum *2;
    }
    else{
        throw ("bad matrix slice number");
    }
    addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(261+offset1)));
    addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(262+offset1)));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, instru->editParametre(263+offset1)));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, instru->editParametre(309+offset2)));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, instru->editParametre(310+offset2)));

}
