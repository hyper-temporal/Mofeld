#include "frmsynthctrl_rotary.h"


frmSynthCtrl_rotary::frmSynthCtrl_rotary(QWidget * parent,
        TargetProvider* tp,
        int pnum, VAccessor accessor,
        int offset, QBoxLayout::Direction d
        )
    :CtrlParamLeaf(parent,new QDial(parent),pnum, d ,tp, accessor),_offset(offset)
{
    InitData();
}



void frmSynthCtrl_rotary::InitData()
{
    ((QDial*)_controle)->setRange(0,127);
    _sbValeur.setRange(0+_offset,127+_offset);
}

void frmSynthCtrl_rotary::setLayout()
{
    QBoxLayout * layout = new QBoxLayout(_direction);
    layout->setSizeConstraint(QLayout::SetMinimumSize);
    layout->addWidget(_controle,0,Qt::AlignHCenter );
    layout->addWidget(&_lbTitre,0,Qt::AlignHCenter );
    layout->addWidget(&_sbValeur,0,Qt::AlignHCenter );

    CompactLayout(layout);
    QWidget::setLayout(layout);
}

void frmSynthCtrl_rotary::show(){
    _sbValeur.show();
    CtrlParamLeaf::show();
}

void frmSynthCtrl_rotary::hide(){
    _sbValeur.hide();
    CtrlParamLeaf::hide();
}


void frmSynthCtrl_rotary::reconnecter(){
    connect( _controle, SIGNAL(valueChanged(int)),
             this, SLOT(ValueChanged(int)));

    connect(&_sbValeur, SIGNAL(valueChanged(int)),
              this, SLOT(ValueChangedOffset(int)));
}

void frmSynthCtrl_rotary::deconnecter(){
    disconnect(&_sbValeur, SIGNAL(valueChanged(int)),0,0);
    disconnect(_controle, SIGNAL(valueChanged(int)),0,0);
}



void frmSynthCtrl_rotary::directConnect(){
    connect( _controle, SIGNAL(valueChanged(int)),
             this, SLOT(ValueChangedDirect(int)));

    connect(&_sbValeur, SIGNAL(valueChanged(int)),
              this, SLOT(ValueChangedOffsetDirect(int)));
}




void frmSynthCtrl_rotary::UpdatedValueDirect(int value)
{
    try {
        ((QDial*)_controle)->setValue(value);
        _sbValeur.setValue(value+_offset);
    } catch (...) {
    }
}


void frmSynthCtrl_rotary::ValueChanged(int v){

    try {
        emit(UpdateParametre( _paramId, v ));
    } catch (...) {

    }
}

void frmSynthCtrl_rotary::ValueChangedOffset(int value)
{
    CtrlParamLeaf::ValueChanged(value -  _offset);
}
void frmSynthCtrl_rotary::ValueChangedOffsetDirect(int value)
{
    CtrlParamLeaf::ValueChangedDirect(value -  _offset);
}
