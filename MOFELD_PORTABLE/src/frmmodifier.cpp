#include "frmmodifier.h"
#include "blofeldreplica.h"
#include "frmsynthctrl_rotary.h"
#include "frmsynthctrl_combobox.h"

frmModifier::frmModifier(TargetProvider *synth, int modNum, QString nom, QWidget *parent)
    :ctrlSection( nom ,parent, QBoxLayout::LeftToRight )
{
    int offset = 4*modNum;

    ctrlComposite * fcp1 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fcp1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (185+offset),VAccessor::accessInstrument));
    fcp1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (186+offset),VAccessor::accessInstrument));

    ctrlComposite * fcp2 = new ctrlComposite(parent,QBoxLayout::LeftToRight);
    fcp2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, (187+offset),VAccessor::accessInstrument));
    fcp2->addCtrl(new frmSynthCtrl_rotary( parent ,synth, (188+offset),VAccessor::accessInstrument,-64));

    addCtrl(fcp1);
    addCtrl(fcp2);
}
