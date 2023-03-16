#include "frmenveloppes.h"

frmEnveloppes::frmEnveloppes(
        TargetProvider *synth,
        QWidget *parent)
    :ctrlComposite(parent, QBoxLayout::TopToBottom )
{

    ctrlComposite * enveloppes1= new ctrlComposite(parent,QBoxLayout::LeftToRight);
    enveloppes1->addCtrl(new frmEnveloppe(synth,0,"ENV1",parent));
    enveloppes1->addCtrl(new frmEnveloppe(synth,1,"ENV2",parent));
//    enveloppes1->addCtrl(new frmEnveloppe(instru,2,accessor,"ENV3",parent));
//    enveloppes1->addCtrl(new frmEnveloppe(instru,3,accessor,"ENV4",parent));

    ctrlComposite * enveloppes2= new ctrlComposite(parent,QBoxLayout::LeftToRight);
    enveloppes2->addCtrl(new frmEnveloppe(synth,2,"ENV3",parent));
    enveloppes2->addCtrl(new frmEnveloppe(synth,3,"ENV4",parent));

    ctrlComposite * eLFOS= new ctrlComposite(parent,QBoxLayout::LeftToRight);
    eLFOS->addCtrl(new frmLFO(synth,0,"LFO1",parent));
    eLFOS->addCtrl(new frmLFO(synth,1,"LFO2",parent));
    eLFOS->addCtrl(new frmLFO(synth,2,"LFO3",parent));

    addCtrl(enveloppes1);
    addCtrl(enveloppes2);
    addCtrl(eLFOS);

    setLayout();
}


