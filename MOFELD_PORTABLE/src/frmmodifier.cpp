#include "frmmodifier.h"
#include "blofeldreplica.h"
#include "frmsynthctrl_rotary.h"
#include "frmsynthctrl_combobox.h"

frmModifier::frmModifier(const BlofeldReplica *synth,Instrument *instru,int modNum, QString nom, QWidget *parent)
    :ctrlSection( nom ,parent, QBoxLayout::LeftToRight )
{
    int offset = 4*modNum;

    ctrlComposite * fcp1 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fcp1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(185+offset)));
    fcp1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(186+offset)));

    ctrlComposite * fcp2 = new ctrlComposite(parent,QBoxLayout::LeftToRight);
    fcp2->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(187+offset)));
    fcp2->addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(188+offset),-64));

    addCtrl(fcp1);
    addCtrl(fcp2);
}
