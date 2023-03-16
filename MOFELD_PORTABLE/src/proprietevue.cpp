#include "proprietevue.h"

void ProprieteVue::connectAll(QWidget * parent){

    connect(&_btnEntityAdd, SIGNAL(clicked()),
            this, SLOT(ajouterPropriete()));

    connect(&_btnEntityRemove, SIGNAL(clicked()),
            this, SLOT(effacerPropriete()));

    connect(&_tvEntity,SIGNAL(doubleClicked(QModelIndex)),
        this,SLOT (envoyerPropriete(QModelIndex)));

    connect(this,SIGNAL(sendPropriete(const Propriete*)),
            parent,SLOT (recevoirPropriete(const Propriete*)));

    connectEList();
//    ui.groupBox->setLayout(_layout);

}

void ProprieteVue::ajouterPropriete(){
    _model->ajouter(_leEntity.text());
}


void ProprieteVue::envoyerPropriete(QModelIndex index ){

    int i =getId();
    const Propriete * a = _model->getEntity(i);
    if(a!=NULL)
    {
        _leEntity.setText(a->getName());
        emit sendPropriete(a);
    }
}

void ProprieteVue::effacerPropriete(){

    try{
        _model->deleteEntity(getSelectedRow());
    }catch(...){

    }

}






