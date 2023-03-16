#include "frmsynthctrl_latchbutton.h"

frmSynthCtrl_button::frmSynthCtrl_button(QWidget * parent,
        TargetProvider *_synth,
        int pnum, VAccessor accessor,
        bool toggleIfTrue, QBoxLayout::Direction d)
    :CtrlParamLeaf(
         parent,
         new QPushButton(parent),
         pnum,
         d,
         _synth,accessor )
    ,_toggleIfTrue(toggleIfTrue)
{
    InitData();
}


void frmSynthCtrl_button::InitData()
{
    auto tgt = _target->getTarget();
    if( tgt == nullptr)
        return;
    QPushButton * pb = dynamic_cast<QPushButton *>(_controle);
    if(pb!=NULL){
        pb->setCheckable(_toggleIfTrue);
//        pb->setText(_valueMgr->getNameOfElement(_valueMgr->getValue()));
        pb->setText(*tgt->vaccessor(_pid,_accessor)->getName());
    }
//    setLayout(getLayout());
}

void frmSynthCtrl_button::directConnect(){
    QObject::connect( _controle, SIGNAL(clicked(bool)),
                      this, SLOT(ValueChangedDirect(bool)));
}



void frmSynthCtrl_button::reconnecter(){
    QObject::connect( _controle, SIGNAL(clicked(bool)),
                      this, SLOT(ValueChanged(bool)));
}

void frmSynthCtrl_button::deconnecter(){
    QObject::disconnect(_controle, SIGNAL(clicked(bool)),0,0);
}
void frmSynthCtrl_button::setLayout(){
    QBoxLayout * layout = new QBoxLayout(_direction);
    layout->setSizeConstraint(QLayout::SetMinimumSize);
    layout->addWidget(_controle,0,Qt::AlignCenter );
//    layout->addWidget(&_lbTitre,0 ,Qt::AlignCenter );
//    layout->addWidget(&_lbValeur,0 ,Qt::AlignCenter );
    CompactLayout(layout);
    QWidget::setLayout(layout);
//    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
}

void frmSynthCtrl_button::UpdatedValueDirect(int value)
{
    ((QPushButton*)_controle)->setChecked(value>0);
}

void frmSynthCtrl_button::show(){
//    _lbTitre.show();
    _controle->show();
}

void frmSynthCtrl_button::hide(){
//    _lbTitre.hide();
    _controle->hide();
}
