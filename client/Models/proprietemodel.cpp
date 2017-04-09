#include "proprietemodel.h"

#include "Messaging/dumpinstrument.h"

ProprieteModel::ProprieteModel(BlofeldReplica *r)
    : EntityDAO<Propriete>("Propriete","props","./Datas/Props/"),_synth(r)
{}

void ProprieteModel::ajouter(QString nom)
{
    const Propriete *p = _synth->getProprieteChannel();
    addEntity(nom,p);
}


