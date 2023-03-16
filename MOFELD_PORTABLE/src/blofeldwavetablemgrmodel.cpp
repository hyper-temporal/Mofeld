#include "blofeldwavetablemgrmodel.h"

BlofeldWaveTableMgrModel::BlofeldWaveTableMgrModel()
    :_waveTables(WT_COUNT)
{

}

BlofeldWaveTableMgrModel::BlofeldWaveTableMgrModel(const BlofeldWaveTableMgrModel *other, int id , QString nom)
    :_waveTables(WT_COUNT)
    ,Entity(id,nom)
{
}
void BlofeldWaveTableMgrModel::setSignal(int tableNum, int waveNum, int freq, double mgn, double phs)
{
    SignalReal *s =editSignal(tableNum,waveNum);
    s->setPhase(freq,phs);
    s->setMagnitude(freq,mgn);
}


//void BlofeldWaveTableMgrModel::setSignal(int tableNum, int waveNum, SignalReal sr)
//{
//    BlofeldWaveTableModel * t = editTable(tableNum);
//    t->setSignal(waveNum,sr);
//}

const SignalReal * BlofeldWaveTableMgrModel::getSignal(int tableNum, int waveNum)
{
    return editSignal(tableNum,waveNum);
}

SignalReal * BlofeldWaveTableMgrModel::editSignal(int tableNum, int waveNum)
{
    return editTable(tableNum)->editSignal(waveNum);
}


const BlofeldWaveTableModel *BlofeldWaveTableMgrModel::getTable(int num)const
{
    if(num<_waveTables.count() && num>=0)
    {
        return &_waveTables[num];
    }else{
        throw ("la table est hors limites");
    }
}

 BlofeldWaveTableModel *BlofeldWaveTableMgrModel::editTable(int pos)
{
//     int pos = num - WT_START;
    if(pos<_waveTables.count() && pos>=0)
    {
        return &_waveTables[pos];
    }else{
        throw ("la table est hors limites");
    }
}
void BlofeldWaveTableMgrModel::setTable(int pos,const BlofeldWaveTableModel * table)
{
    BlofeldWaveTableModel *t =editTable(pos);
    if(table->getSignals()->count() != t->getSignals()->count())
    {
        throw ("les tables sont de taille différentes");
    }
    int count(0);
    foreach(SignalReal s, *table->getSignals())
    {
        t->setSignal(count++, s);
    }
}


