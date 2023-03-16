#include "ctrlvalueleaf.h"
#include "valuemgr.h"
#include "parametre.h"

CtrlValueLeaf::CtrlValueLeaf(QWidget * parent,
        QWidget *enfant,
        int pid,
        QBoxLayout::Direction direction,
        TargetProvider* tp,
        VAccessor accessor
        )
    :ctrlleaf(parent,enfant,direction),
        _pid(pid),
        _accessor(accessor),
        _target(tp)
{
    init();
}

void CtrlValueLeaf::init(void)
{
    if(_target->getTarget() == nullptr
    || _target->getTarget()->vaccessor(_pid,_accessor) == nullptr)
    {
        _lbTitre.setText("not set");
    }
    else{
        _lbTitre.setText(*_target->getTarget()->vaccessor(_pid,_accessor)->getName());
    }
}

void CtrlValueLeaf::ValueChanged(int p){

    try {
        _target->getTarget()->vaccessor(_pid,_accessor)
                ->setValue(
                    _target->getTarget()->vaccessor(_pid,_accessor)
                    ->getValueOfElement(p));
        UpdatedValueDirect(
                    _target->getTarget()->vaccessor(_pid,_accessor)->getValue());
    } catch (...){
    }
}


void CtrlValueLeaf::ValueChanged(bool p)
{
    try {
        _target->getTarget()->vaccessor(_pid,_accessor)
                ->setValue(
                    _target->getTarget()->vaccessor(_pid,_accessor)
                    ->getValueOfElement((int)p));
        UpdatedValue(p);
    } catch (...) {
    }
}

void CtrlValueLeaf::show(){
    _lbTitre.show();
    _controle->show();
}

void CtrlValueLeaf::hide(){
    _lbTitre.hide();
    _controle->hide();
}

