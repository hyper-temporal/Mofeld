#include "wtmodel.h"


WTModel::WTModel( BlofeldWaveTableMgrModel *edited)
    : EntityDAO<BlofeldWaveTableMgrModel>(
          "BlofeldWaveTableMgrModel",
          "wtables",
          "./Datas/wavetables/")
    ,_edited(edited)
{}

void WTModel::ajouter(QString nom)
{
    addEntity(nom,_edited);
}


