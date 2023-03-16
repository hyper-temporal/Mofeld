#include "proprietemodel.h"

#include "dumpinstrument.h"

ProprieteModel::ProprieteModel(TargetProvider *r)
    : EntityDAO<Propriete>("Propriete","props","./Datas/Props/"),_synth(r)
{}

void ProprieteModel::ajouter(QString nom)
{
    const Propriete *p = _synth->getTarget()->getProprieteChannel();
    addEntity(nom,p);
}


