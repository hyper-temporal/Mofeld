#include "wavetableselectvue.h"



void WaveTableSelectVue::ajouterTables()
{
    _model->ajouter(_leEntity.text());
}

void WaveTableSelectVue::disconnectAll(){
    disconnect(&_btnEntityAdd, SIGNAL(clicked()));

    disconnect(&_btnEntityRemove, SIGNAL(clicked()));

    disconnect(&_tvEntity,SIGNAL(doubleClicked(QModelIndex)));

    disconnect(this,SIGNAL(envoyerTables(const BlofeldWaveTableMgrModel*)));

    disconnectEList();
}
void WaveTableSelectVue::connectAll(QWidget * parent){
    connect(&_btnEntityAdd, SIGNAL(clicked()),
            this, SLOT(ajouterTables()));

    connect(&_btnEntityRemove, SIGNAL(clicked()),
            this, SLOT(effacerTables()));

    connect(&_tvEntity,SIGNAL(doubleClicked(QModelIndex)),
        this,SLOT (envoyerTables(QModelIndex)));

    connect(this,SIGNAL(envoyerTables(const BlofeldWaveTableMgrModel*)),
            parent,SLOT (recevoirTables(const BlofeldWaveTableMgrModel*)));

    connectEList();
}

void WaveTableSelectVue::envoyerTables(QModelIndex index ){
    int id = getId();
    const BlofeldWaveTableMgrModel * a = _model->getEntity(id);
    if(a!=NULL){
        _leEntity.setText(a->getName());
        emit envoyerTables(a);
    }
}

void WaveTableSelectVue::effacerTables(){
    try{
        _model->deleteEntity(getSelectedRow());
    }catch(...){

    }
}






