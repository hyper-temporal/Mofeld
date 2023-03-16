#include "arpeggio.h"
#include "arpeggioslice.h"
#include "arpegiocommon.h"

Arpeggio::Arpeggio( TargetProvider *synth, QWidget *parent)
    :ctrlComposite(parent, QBoxLayout::TopToBottom )
{
    ctrlComposite * ccH1 = new ctrlComposite(parent,QBoxLayout::LeftToRight);

    for(int i(0);i<8;i++){
        QString s = QString("%1").arg(i+1);
        ccH1->addCtrl(new ArpeggioSlice(synth,i,s,parent));
    }
    ctrlComposite * ccH2 = new ctrlComposite(parent,QBoxLayout::LeftToRight);
    for(int i(8);i<16;i++){
        QString s= QString("%1").arg(i+1);
        ccH2->addCtrl(new ArpeggioSlice(synth,i,s,parent));
    }
    addCtrl(ccH1);
    addCtrl(ccH2);
    addCtrl(new ArpegioCommon(synth,"",parent));

    setLayout();
}
