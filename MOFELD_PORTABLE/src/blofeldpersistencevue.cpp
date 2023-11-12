#include "blofeldpersistencevue.h"

BlofeldPersistenceVue::BlofeldPersistenceVue(TargetProvider *blofeld)
    :_synth(blofeld)
{

    _arrModel = new ArrangementModel(_synth);
    _instruModel = new InstrumentModel(_synth);
    _proprieteModel = new ProprieteModel(_synth);

    _arrVue = new ArrangementVue(_arrModel,this);
    _propsVue= new ProprieteVue( _proprieteModel,this );
    _instruVue = new InstrumentVue(_instruModel,this);
    _propsElementVue = new ProprieteElementsVue(_proprieteModel,this);

    _arrVue->connectAll(this);
    _instruVue->connectAll(this);
    _propsVue->connectAll(this);
    _propsElementVue->connectAll(this);

    QHBoxLayout *lyV3  = new QHBoxLayout;
    lyV3->addWidget(_propsElementVue);
    lyV3->addWidget(_propsVue);
    QHBoxLayout *lyV4  = new QHBoxLayout;
    lyV4->addWidget(_instruVue);
    lyV4->addWidget(_arrVue);
    lyV4->addWidget(_wtVue);
    QVBoxLayout *lyV5  = new QVBoxLayout;
    lyV5->addLayout(lyV3);
    lyV5->addLayout(lyV4);
    _wTargetCtrl=new QWidget(this);
    _wTargetCtrl->setLayout(lyV5);
}


void BlofeldPersistenceVue::updateView(int pid)
{
    updateView(_synth->getTarget()->getparametre(pid));
}

void BlofeldPersistenceVue::updateView(const Parametre * p)
{
    updatePElements();
}
void BlofeldPersistenceVue::updatePElements(){
    const Propriete * prpch = _synth->getTarget()->getChannel()->getProprieteChannel();
    _propsElementVue->setModel(prpch);
}

void BlofeldPersistenceVue::updateView(const Propriete * p)
{
    updateInstrumentView();
}



void BlofeldPersistenceVue::updateInstrumentView()
{
    updatePElements();
}

