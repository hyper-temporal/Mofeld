#include "arrangementmodel.h"


ArrangementModel::ArrangementModel(BlofeldReplica *r)
    : EntityDAO<Arrangement>("Arrangement","arrgnt","./Datas/Lezards/"),_synth(r)
{}

void ArrangementModel::ajouter(QString nom)
{
    const Arrangement *a = _synth->getArrangement();
    addEntity(nom,a);
}
