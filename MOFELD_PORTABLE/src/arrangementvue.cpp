#include "arrangementvue.h"

void ArrangementVue::ajouterArrangement()
{
    _model->ajouter(_leEntity.text());
}

void ArrangementVue::connectAll(QWidget * parent){
    connect(&_btnEntityAdd, SIGNAL(clicked()),
            this, SLOT(ajouterArrangement()));

    connect(&_btnEntityRemove, SIGNAL(clicked()),
            this, SLOT(effacerArrangement()));

    connect(&_tvEntity,SIGNAL(doubleClicked(QModelIndex)),
        this,SLOT (envoyerArrangement(QModelIndex)));

    connect(this,SIGNAL(envoyerArrangement(const Arrangement*)),
            parent,SLOT (recevoirArrangement(const Arrangement*)));

    connectEList();
}

void ArrangementVue::envoyerArrangement(QModelIndex index ){
    int id = getId();
    const Arrangement * a = _model->getEntity(id);
    if(a!=NULL){
        _leEntity.setText(a->getName());
        emit envoyerArrangement(a);
    }
}

void ArrangementVue::effacerArrangement(){
    try{
        _model->deleteEntity(getSelectedRow());
    }catch(...){

    }
}






