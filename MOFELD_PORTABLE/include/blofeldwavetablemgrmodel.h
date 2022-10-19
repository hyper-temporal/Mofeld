#ifndef BLOFELDWAVETABLEMGR_H
#define BLOFELDWAVETABLEMGR_H


#include <QVector>
#include "blofeldwavetablemodel.h"
#include <itagable.h>
#include <entitydao.h>

class BlofeldWaveTableMgrModel
        :public ITagable,public Entity
{
    //gère l'ensemble des wavetables éditables du blofeld
    QVector<BlofeldWaveTableModel> _waveTables;

public:
    BlofeldWaveTableMgrModel();
    int countSamples()const{return _waveTables.at(0).countSamples();}
    int countAnalysis()const{return _waveTables.at(0).countAnalysis();}
    int countWaves()const{return _waveTables.size();}

    //constructeur appelé par la classe de serialisation lors de l'import
    BlofeldWaveTableMgrModel(const BlofeldWaveTableMgrModel *other, int id , QString nom);
    SignalReal * editSignal(int tableNum, int waveNum);
    const SignalReal * getSignal(int tableNum, int waveNum);


    const BlofeldWaveTableModel *getTable(int num)const ;
    void setTable(int num, const BlofeldWaveTableModel *table);


    const QVector<BlofeldWaveTableModel>  *getTables()const{return &_waveTables;}
//    QVector<BlofeldWaveTableModel>  *editTables(){return &_waveTables;}
public slots:
    void setSignal(int tableNum, int waveNum, int freq, double mgn, double phs);
    BlofeldWaveTableModel *editTable(int num);

private:
    //    void setSignal(int tableNum, int waveNum, SignalReal sr);


};


#endif // BLOFELDWAVETABLEMGR_H
