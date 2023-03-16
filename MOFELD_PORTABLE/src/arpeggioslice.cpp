#include "arpeggioslice.h"

#include "frmsynthctrl_combobox.h"
#include "instrument.h"


ArpeggioSlice::ArpeggioSlice(TargetProvider *synth,
        int slicenum,
        QString n,
        QWidget *parent)
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
    addCtrl(new frmSynthCtrl_combobox( parent ,synth, (261+offset1),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_combobox( parent ,synth, (262+offset1),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, (263+offset1),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, (309+offset2),VAccessor::accessInstrument));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, (310+offset2),VAccessor::accessInstrument));

}
