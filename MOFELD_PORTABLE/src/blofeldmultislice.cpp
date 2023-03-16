#include "blofeldmultislice.h"
#include "frmsynthctrl_combobox.h"
#include "frmsynthctrl_latchbutton.h"
#include "frmsynthctrl_rotary.h"
#include "dumpmulti.h"


BlofeldMultiSlice::BlofeldMultiSlice(
        TargetProvider *synth,
        const DumpMulti *multimess,
        int sclicenum,
        QString n,
        QWidget *parent)
    :ctrlSection(n, parent, QBoxLayout::TopToBottom )
{
    int offffset = 18;
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

    int offset = offffset  + sclicenum*21;
    pBanknum        = offset + 0;
    pPgmNum         = offset + 1;
    pVol            = offset + 2;
    ppan            = offset + 3;
    pTRANSPOSE      = offset + 4;
    pDETUN          = offset + 5;
    pCHANNEL        = offset + 6;
    pLowNote        = offset + 7;
    pHighNote       = offset + 8;
    plowVel         = offset + 9;
    phighVel        = offset + 10;
    pStatus         = offset + 11;
    pMIDI           = offset + 12;
    pUSB            = offset + 13;
    pLOCAL          = offset + 14;
    ppitchBend      = offset + 15;
    pmodwhell       = offset + 16;
    ppressure       = offset + 17;
    psustain        = offset + 18;
    pedits          = offset + 19;
    pPGMCH          = offset + 20;

    addCtrl(new frmSynthCtrl_button( parent, synth, (pStatus),VAccessor::accessMulti));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, (pBanknum),VAccessor::accessMulti));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, (pPgmNum),VAccessor::accessMulti));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, (pCHANNEL),VAccessor::accessMulti));

    ctrlComposite * block1 = new ctrlComposite(parent, QBoxLayout::LeftToRight );
    block1->addCtrl(new frmSynthCtrl_rotary( parent, synth, (pVol),VAccessor::accessMulti));
    block1->addCtrl(new frmSynthCtrl_rotary( parent, synth, (ppan),VAccessor::accessMulti,-64));
    addCtrl(block1);
    addCtrl(new frmSynthCtrl_combobox( parent, synth, (pTRANSPOSE),VAccessor::accessMulti));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, (pDETUN),VAccessor::accessMulti));
    ctrlComposite * block3 = new ctrlComposite(parent, QBoxLayout::TopToBottom );
    block3->addCtrl(new frmSynthCtrl_combobox( parent, synth, (plowVel),VAccessor::accessMulti));
    block3->addCtrl(new frmSynthCtrl_combobox( parent, synth, (phighVel),VAccessor::accessMulti));
    addCtrl(block3);


    addCtrl(new frmSynthCtrl_combobox( parent, synth, (pLowNote),VAccessor::accessMulti));
    addCtrl(new frmSynthCtrl_combobox( parent, synth, (pHighNote),VAccessor::accessMulti));

    ctrlComposite * block_btn1 = new ctrlComposite(parent, QBoxLayout::LeftToRight );
    block_btn1->addCtrl(new frmSynthCtrl_button( parent, synth, (pLOCAL),VAccessor::accessMulti,true,QBoxLayout::TopToBottom));
    block_btn1->addCtrl(new frmSynthCtrl_button( parent, synth, (pUSB),VAccessor::accessMulti,true,QBoxLayout::TopToBottom));
    block_btn1->addCtrl(new frmSynthCtrl_button( parent, synth, (pMIDI),VAccessor::accessMulti,true,QBoxLayout::TopToBottom));
    addCtrl(block_btn1);
    ctrlComposite * block_btn2 = new ctrlComposite(parent, QBoxLayout::LeftToRight );
    block_btn2->addCtrl(new frmSynthCtrl_button( parent, synth, (pPGMCH),VAccessor::accessMulti,true,QBoxLayout::TopToBottom));
    block_btn2->addCtrl(new frmSynthCtrl_button( parent, synth, (psustain),VAccessor::accessMulti,true,QBoxLayout::TopToBottom));
    block_btn2->addCtrl(new frmSynthCtrl_button( parent, synth, (pedits),VAccessor::accessMulti,true,QBoxLayout::TopToBottom));
    addCtrl(block_btn2);
    ctrlComposite * block_btn3 = new ctrlComposite(parent, QBoxLayout::LeftToRight );
    block_btn3->addCtrl(new frmSynthCtrl_button( parent, synth, (ppressure),VAccessor::accessMulti,true,QBoxLayout::TopToBottom));
    block_btn3->addCtrl(new frmSynthCtrl_button( parent, synth, (pmodwhell),VAccessor::accessMulti,true,QBoxLayout::TopToBottom));
    block_btn3->addCtrl(new frmSynthCtrl_button( parent, synth, (ppitchBend),VAccessor::accessMulti,true,QBoxLayout::LeftToRight));
    addCtrl(block_btn3);



}
