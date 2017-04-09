#ifndef BLOFELDWAVETABLEMGR_H
#define BLOFELDWAVETABLEMGR_H


#include <QVector>
#include "blofeldwavetablemodel.h"
#include "genericity/entitydao.h"

class BlofeldWaveTableMgrModel
        :public Entity
{
    //gère l'ensemble des wavetables éditables du blofeld
    QVector<BlofeldWaveTableModel> _waveTables;

public:
    BlofeldWaveTableMgrModel();

    //constructeur appelé par la classe de serialisation lors de l'import
    BlofeldWaveTableMgrModel(const BlofeldWaveTableMgrModel *other, int id , QString nom);

    void setSignal(int tableNum, int waveNum, SignalReal sr);
    const SignalReal * getSignal(int tableNum, int waveNum);
    SignalReal * editSignal(int tableNum, int waveNum);
    const BlofeldWaveTableModel *getTable(int num)const ;
    void setTable(int num, const BlofeldWaveTableModel *table);

    const QVector<BlofeldWaveTableModel>  *getTables()const{
        return &_waveTables;
    }

private:
    BlofeldWaveTableModel *editTable(int num);

    friend QDataStream & operator << (QDataStream &, const BlofeldWaveTableMgrModel &);
    friend QDataStream & operator >> (QDataStream &, BlofeldWaveTableMgrModel &);
};
Q_DECLARE_METATYPE(BlofeldWaveTableMgrModel)
QDataStream & operator << (QDataStream & out, const BlofeldWaveTableMgrModel & Valeur);
QDataStream & operator >> (QDataStream & in, BlofeldWaveTableMgrModel & Valeur);


#endif // BLOFELDWAVETABLEMGR_H
