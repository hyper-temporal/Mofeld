#include "instrumentmodel.h"

InstrumentModel::InstrumentModel(TargetProvider *r)
    : EntityDAO<Instrument>("Instrument","inst","./Datas/Instrus/"),_synth(r)
{}

void InstrumentModel::ajouter(QString nom)
{
    const Instrument *i = _synth->getTarget()->getInstrument();
    addEntity(nom,i);
}


