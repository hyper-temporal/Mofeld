#include "frmenveloppe.h"


frmEnveloppe::frmEnveloppe(const BlofeldReplica *synth, Instrument *instru, int envnum, QString n, QWidget *parent)
    :ctrlSection(n,parent, QBoxLayout::LeftToRight )
{

    int
            envmod,
            envtrigg,
            envatt,
            envattLev,
            envdec,
            envsust,
            envdec2,
            envsust2,
            envrel;
    if(envnum<4)
    {
        int offset =  envnum * 9;

        envmod= 149 + offset ;
        envtrigg=150 + offset;
        envatt=151+ offset;
        envattLev=152+ offset;
        envdec=153+ offset;
        envsust=154+ offset;
        envdec2=155+ offset;
        envsust2=156+ offset;
        envrel=157+ offset;
    }
    else{
        throw("l'enveloppe est mal précisée");
    }

    ctrlComposite * fsc1 = new ctrlComposite(parent,QBoxLayout::TopToBottom);
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(envtrigg)));
    fsc1->addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(envmod)));


    ctrlComposite * fsc2 = new ctrlSection("ADSR1",parent,QBoxLayout::LeftToRight);
    fsc2->addCtrl(new frmSynthCtrl_Slider( parent, synth, instru->editParametre(envatt)));
    fsc2->addCtrl(new frmSynthCtrl_Slider( parent, synth, instru->editParametre(envdec)));
    fsc2->addCtrl(new frmSynthCtrl_Slider( parent, synth, instru->editParametre(envsust)));
    fsc2->addCtrl(new frmSynthCtrl_Slider( parent, synth, instru->editParametre(envrel)));

    ctrlSection * fsc3 = new ctrlSection("ADSR2",parent,QBoxLayout::LeftToRight);
    fsc3->addCtrl(new frmSynthCtrl_Slider( parent, synth, instru->editParametre(envattLev)));
    fsc3->addCtrl(new frmSynthCtrl_Slider( parent, synth, instru->editParametre(envdec2)));
    fsc3->addCtrl(new frmSynthCtrl_Slider( parent, synth, instru->editParametre(envsust2)));


    ctrlComposite * fsc4 = new ctrlComposite(parent,QBoxLayout::LeftToRight);
    fsc4->addCtrl(fsc2);
    fsc4->addCtrl(fsc3);

    addCtrl(fsc1);
    addCtrl(fsc4);

}
