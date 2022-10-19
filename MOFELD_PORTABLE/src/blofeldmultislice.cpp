#include "blofeldmultislice.h"
#include "frmsynthctrl_combobox.h"
#include "frmsynthctrl_latchbutton.h"
#include "frmsynthctrl_rotary.h"
#include "dumpmulti.h"


BlofeldMultiSlice::BlofeldMultiSlice(const BlofeldReplica *synth,const DumpMulti *multimess, int sclicenum,QString n, QWidget *parent)
    :ctrlSection(n, parent, QBoxLayout::TopToBottom )
{
    int
        pBanknum,
        pPgmNum,
        pVol,
        ppan,
        pTRANSPOSE,
        pDETUN,
        pCHANNEL,
        pLowNote,
        pHighNote,
        plowVel,
        phighVel,
        pStatus,
        pMIDI,
        pUSB,
        pLOCAL,
        ppitchBend,
        pmodwhell,
        ppressure,
        psustain,
        pedits,
        pPGMCH;

    if(sclicenum <16)
    {
        int offset = sclicenum*21;

        int i=25;

        pBanknum=offset+i++;
        pPgmNum=offset+i++;
        pVol=offset+i++;
        ppan=offset+i++;
        pTRANSPOSE=offset+i++;
        pDETUN=offset+i++;
        pCHANNEL=offset+i++;
        pLowNote=offset+i++;
        pHighNote=offset+i++;
        plowVel=offset+i++;
        phighVel=offset+i++;
        pStatus=offset+i++;
        pMIDI=offset+i++;
        pUSB=offset+i++;
        pLOCAL=offset+i++;
        ppitchBend=offset+i++;
        pmodwhell=offset+i++;
        ppressure=offset+i++;
        psustain=offset+i++;
        pedits=offset+i++;
        pPGMCH=offset+i++;
    }
    else{
        throw("la tranche de multi est mal défini");
    }

    addCtrl(new frmSynthCtrl_button( parent, synth, multimess->getParametre(pStatus)));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, multimess->getParametre(pBanknum)));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, multimess->getParametre(pPgmNum)));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, multimess->getParametre(pCHANNEL)));

    ctrlComposite * block1 = new ctrlComposite(parent, QBoxLayout::LeftToRight );
    block1->addCtrl(new frmSynthCtrl_rotary( parent, synth, multimess->getParametre(pVol)));
    block1->addCtrl(new frmSynthCtrl_rotary( parent, synth, multimess->getParametre(ppan),-64));
    addCtrl(block1);
    addCtrl(new frmSynthCtrl_combobox( parent, synth, multimess->getParametre(pTRANSPOSE)));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, multimess->getParametre(pDETUN)));
    ctrlComposite * block3 = new ctrlComposite(parent, QBoxLayout::TopToBottom );
    block3->addCtrl(new frmSynthCtrl_combobox( parent, synth, multimess->getParametre(plowVel)));
    block3->addCtrl(new frmSynthCtrl_combobox( parent, synth, multimess->getParametre(phighVel)));
    addCtrl(block3);


    addCtrl(new frmSynthCtrl_combobox( parent, synth, multimess->getParametre(pLowNote)));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, multimess->getParametre(pHighNote)));

    ctrlComposite * block_btn1 = new ctrlComposite(parent, QBoxLayout::LeftToRight );
    block_btn1->addCtrl(new frmSynthCtrl_button( parent, synth, multimess->getParametre(pLOCAL),true,QBoxLayout::TopToBottom));
    block_btn1->addCtrl(new frmSynthCtrl_button( parent, synth, multimess->getParametre(pUSB),true,QBoxLayout::TopToBottom));
    block_btn1->addCtrl(new frmSynthCtrl_button( parent, synth, multimess->getParametre(pMIDI),true,QBoxLayout::TopToBottom));
    addCtrl(block_btn1);
    ctrlComposite * block_btn2 = new ctrlComposite(parent, QBoxLayout::LeftToRight );
    block_btn2->addCtrl(new frmSynthCtrl_button( parent, synth, multimess->getParametre(pPGMCH),true,QBoxLayout::TopToBottom));
    block_btn2->addCtrl(new frmSynthCtrl_button( parent, synth, multimess->getParametre(psustain),true,QBoxLayout::TopToBottom));
    block_btn2->addCtrl(new frmSynthCtrl_button( parent, synth, multimess->getParametre(pedits),true,QBoxLayout::TopToBottom));
    addCtrl(block_btn2);
    ctrlComposite * block_btn3 = new ctrlComposite(parent, QBoxLayout::LeftToRight );
    block_btn3->addCtrl(new frmSynthCtrl_button( parent, synth, multimess->getParametre(ppressure),true,QBoxLayout::TopToBottom));
    block_btn3->addCtrl(new frmSynthCtrl_button( parent, synth, multimess->getParametre(pmodwhell),true,QBoxLayout::TopToBottom));
    block_btn3->addCtrl(new frmSynthCtrl_button( parent, synth, multimess->getParametre(ppitchBend),true,QBoxLayout::LeftToRight));
    addCtrl(block_btn3);



}
