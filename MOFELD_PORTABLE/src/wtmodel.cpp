#include "wtmodel.h"


//WTModel::WTModel(BlofeldReplica *r)
//    : EntityDAO<BlofeldWaveTableMgrModel>("BlofeldWaveTableMgrModel","wtables","./Datas/wavetables/"),_synth(r)
//{}
WTModel::WTModel( BlofeldWaveTableMgrModel *edited)
    : EntityDAO<BlofeldWaveTableMgrModel>("BlofeldWaveTableMgrModel","wtables","./Datas/wavetables/"),_edited(edited)
{}

void WTModel::ajouter(QString nom)
{
    addEntity(nom,_edited);
}


