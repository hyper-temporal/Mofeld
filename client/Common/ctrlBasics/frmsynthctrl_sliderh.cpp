#include "frmsynthctrl_sliderh.h"



frmSynthCtrl_Slider::frmSynthCtrl_Slider(   QWidget * parent,
                                            const BlofeldReplica *synth,
                                            Parametre *param,
                                            Qt::Orientation o,
                                            QBoxLayout::Direction d
                                            )
    :CtrlParamLeaf(parent ,new QSlider(o,parent),synth,param,d)
{
    InitData();
}


void frmSynthCtrl_Slider::InitData()
{
    ((QSlider*)_controle)->setRange(0,127);
    _sbValeur.setRange(0,127);
}


void frmSynthCtrl_Slider::directConnect(){
    connect( _controle, SIGNAL(valueChanged(int)),
             this, SLOT(ValueChangedDirect(int)));

    connect(&_sbValeur, SIGNAL(valueChanged(int)),
              this, SLOT(ValueChangedOffsetDirect(int)));
}



void frmSynthCtrl_Slider::reconnecter(){
    connect( _controle, SIGNAL(valueChanged(int)),
             this, SLOT(ValueChanged(int)));

    connect(&_sbValeur, SIGNAL(valueChanged(int)),
                    this, SLOT(ValueChanged(int)));
}

void frmSynthCtrl_Slider::deconnecter(){
    disconnect(_controle, SIGNAL(valueChanged(int)),0,0);
    disconnect(&_sbValeur, SIGNAL(valueChanged(int)),0,0);
}


void frmSynthCtrl_Slider::setLayout()
{
    QBoxLayout * layout = new QBoxLayout(_direction);
    layout->setSizeConstraint(QLayout::SetMinimumSize);
    layout->addWidget(&_lbTitre,0,Qt::AlignCenter );
    layout->addWidget(_controle,0,Qt::AlignCenter );
    layout->addWidget(&_sbValeur,0 ,Qt::AlignCenter);
    CompactLayout(layout);
    QWidget::setLayout(layout);
}

void frmSynthCtrl_Slider::show(){
    _sbValeur.show();
    CtrlParamLeaf::show();
}

void frmSynthCtrl_Slider::hide(){
    _sbValeur.hide();
    CtrlParamLeaf::hide();
}

void frmSynthCtrl_Slider::ValueChanged(int p){

    try {
//TODO: le parametre appartient a l'instance identifiée d'une structure de donnée
        emit(UpdateParametre( _paramId,p));
    } catch (...) {
    }
}

void frmSynthCtrl_Slider::UpdatedValueDirect(int value){
    ((QDial*)_controle)->setValue(value);
    _sbValeur.setValue(value);
}

