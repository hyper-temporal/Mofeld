#include "ctrlvalueleaf.h"

CtrlValueLeaf::CtrlValueLeaf(
        QWidget * parent,
        QWidget *enfant,
        const BlofeldReplica *synth,
        ValueMgr *value,
        QBoxLayout::Direction direction)
    :ctrlleaf(parent,enfant,direction),
        _valueMgr(value),
        _synth(synth)
{
    init();
}

void CtrlValueLeaf::init(void)
{
    if(_valueMgr==NULL)
    {
        _lbTitre.setText("not set");
    }
    else{
        _lbTitre.setText(*_valueMgr->getName());
    }
}

void CtrlValueLeaf::ValueChanged(int p){

    try {
        _valueMgr->setValue(_valueMgr->getValueOfElement(p));
        UpdatedValueDirect(_valueMgr->getValue());
    } catch (...){
    }
}


void CtrlValueLeaf::ValueChanged(bool p)
{
    try {
        _valueMgr->setValue(_valueMgr->getValueOfElement((int)p));
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

