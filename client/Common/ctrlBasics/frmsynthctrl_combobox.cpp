#include "frmsynthctrl_combobox.h"

frmSynthCtrl_combobox::frmSynthCtrl_combobox(
        QWidget * parent,
        const BlofeldReplica *_synth,
        Parametre *param,
        QBoxLayout::Direction d
        )
    :CtrlParamLeaf(parent, new QComboBox(parent), _synth,param,d)
{
    InitData();
}



void frmSynthCtrl_combobox::InitData()
{
    QComboBox *cbb = (QComboBox*)_controle;
    const ValueEnum * ve = dynamic_cast<const ValueEnum*>(_valueMgr);
    if(ve != NULL){
        foreach(SynthEnumElement * see, ve->getType()->getElements())
        {
            cbb->addItem(see->LaChaine,see->Lentier);
        }
    }

    QStandardItem *_itm_ctrl;


}

void frmSynthCtrl_combobox::directConnect(){
    QWidget::connect( _controle, SIGNAL(currentIndexChanged(int)),
                      this, SLOT(ValueChangedDirect(int)));
}

void frmSynthCtrl_combobox::reconnecter(){
    QWidget::connect( _controle, SIGNAL(currentIndexChanged(int)),
                      this, SLOT(ValueChanged(int)));
}
void frmSynthCtrl_combobox::deconnecter(){
    QWidget::disconnect(_controle, SIGNAL(currentIndexChanged(int)),0,0);
}

void frmSynthCtrl_combobox::setLayout()
{
    QBoxLayout * layout = new QBoxLayout(_direction);
    layout->setSizeConstraint(QLayout::SetMinimumSize);
    layout->addWidget(&_lbTitre,0);
    layout->addWidget(_controle,0);
    CompactLayout(layout);
    QWidget::setLayout(layout);
}



void frmSynthCtrl_combobox::UpdatedValueDirect(int value)
{
    int ind = ((QComboBox*)_controle)->findData(value);
    if(ind == -1 )return;
    ((QComboBox*)_controle)->setCurrentIndex(ind);
}


