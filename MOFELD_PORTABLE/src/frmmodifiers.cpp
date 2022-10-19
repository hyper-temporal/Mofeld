#include "frmmodifiers.h"

frmModifiers::frmModifiers(const BlofeldReplica *synth,Instrument *instru,QWidget *parent)
    :ctrlComposite(parent, QBoxLayout::TopToBottom )
{
    ctrlComposite * gen;

    for(int cnt1=0;cnt1<2;cnt1++)
    {
        gen = new ctrlComposite(parent,QBoxLayout::LeftToRight);
        for(int cnt2=0;cnt2<2;cnt2++)
        {
            int offset=cnt1*2+cnt2;
            int cnt =cnt1+cnt2;
            QString s = QString("MODIFIER %2d").arg(cnt+1);
            gen->addCtrl( new frmModifier(synth,instru,offset,s,parent));
        }
        addCtrl(gen);
    }

    setLayout();

}
