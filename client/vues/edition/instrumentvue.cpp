#include "instrumentvue.h"

void InstrumentVue::connectAll(QWidget * _parent)
{
    connect(_btnEntityAdd, SIGNAL(clicked()),
            this, SLOT(ajouterInstrument()));

    connect(_btnEntityRemove, SIGNAL(clicked()),
            this, SLOT(effacerInstrument()));

    connect(_tvEntity,SIGNAL(doubleClicked(QModelIndex)),
        this,SLOT (envoyerInstrument(QModelIndex)));

    connect(this,SIGNAL(envoyerInstrument(const Instrument*)),
            _parent,SLOT (recevoirInstrument(const Instrument*)));

    connectEList();

}


void InstrumentVue::ajouterInstrument()
{
    _model->ajouter(_leEntity->text());
}

void InstrumentVue::envoyerInstrument(QModelIndex index ){
    int id = getId();
    const Instrument * a = _model->getEntity(id);
    if(a!=NULL){
        _leEntity->setText(a->getName());
        emit envoyerInstrument(a);
    }
}

void InstrumentVue::effacerInstrument(){

    try{
        _model->deleteEntity(getSelectedRow());
    }catch(...){

    }
}


