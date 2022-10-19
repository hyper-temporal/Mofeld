#include "instrumentmodel.h"

InstrumentModel::InstrumentModel(BlofeldReplica *r)
    : EntityDAO<Instrument>("Instrument","inst","./Datas/Instrus/"),_synth(r)
{}

void InstrumentModel::ajouter(QString nom)
{
    const Instrument *i = _synth->getInstrument();
    addEntity(nom,i);
}


