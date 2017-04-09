#include "blofeldwavetablemgrmodel.h"

BlofeldWaveTableMgrModel::BlofeldWaveTableMgrModel()
{
    int c = WT_COUNT;
    _waveTables.reserve(c);
    for (int i(0);i<c;i++)
    {
        BlofeldWaveTableModel *wt = new BlofeldWaveTableModel ;
        _waveTables.append(*wt );
    }
}

BlofeldWaveTableMgrModel::BlofeldWaveTableMgrModel(const BlofeldWaveTableMgrModel *other, int id , QString nom)
    :Entity(id,nom)
{
    int c = WT_COUNT;
    _waveTables.reserve(c);
    for (int i(0);i<c;i++)
    {
        const BlofeldWaveTableModel wt (*other->getTable(i)) ;
        _waveTables.append(wt );
    }
}


void BlofeldWaveTableMgrModel::setSignal(int tableNum, int waveNum, SignalReal sr)
{
    BlofeldWaveTableModel * t = editTable(tableNum);
    t->setSignal(waveNum,sr);
}

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

 BlofeldWaveTableModel *BlofeldWaveTableMgrModel::editTable(int num)
{
    if(num<_waveTables.count() && num>=0)
    {
        return &_waveTables[num];
    }else{
        throw ("la table est hors limites");
    }
}
void BlofeldWaveTableMgrModel::setTable(int num,const BlofeldWaveTableModel * table)
{
    BlofeldWaveTableModel *t =editTable(num);
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

QDataStream & operator << (QDataStream & out, const BlofeldWaveTableMgrModel & Valeur)
{
    out << Valeur._id
        << Valeur._name
        << Valeur._datecreation
        << Valeur._waveTables

           ;
    return out;
}
QDataStream & operator >> (QDataStream & in, BlofeldWaveTableMgrModel & Valeur)
{
    in  >> Valeur._id
        >> Valeur._name
        >> Valeur._datecreation
        >> Valeur._waveTables
           ;
    return in;
}
