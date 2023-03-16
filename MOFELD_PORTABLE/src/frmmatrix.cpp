#include "frmmatrix.h"



frmMatrix::frmMatrix(TargetProvider *synth, QWidget *parent)
    :ctrlComposite(parent, QBoxLayout::TopToBottom )
{
    ctrlComposite *gen;
    for(int m(0);m<4;m++)
    {
        gen = new ctrlComposite(parent,QBoxLayout::LeftToRight);
        for(int i(0);i<4;i++)
        {
            QString s=QString("MODULATOR %0d").arg(m*4+i+1);
            gen->addCtrl(new frmMatrixSlice(synth,m*4+i,s,parent));
        }
        QString s=QString("MODIFIER %2d").arg(m+1);
        gen->addCtrl(new frmModifier(synth,m,s,parent));
        addCtrl(gen);
    }
    setLayout();
}
