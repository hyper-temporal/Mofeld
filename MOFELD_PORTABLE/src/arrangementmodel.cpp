#include "arrangementmodel.h"


ArrangementModel::ArrangementModel(TargetProvider *r)
    : EntityDAO<Arrangement>("Arrangement","arrgnt","./Datas/Lezards/"),
      _synth(r)
{}

void ArrangementModel::ajouter(QString nom)
{
    const Arrangement *a = _synth->getTarget()->getArrangement();
    addEntity(nom,a);
}
