#ifndef BLOFELDWAVETABLESMODEL_H
#define BLOFELDWAVETABLESMODEL_H


#include <QSettings>
#include <QVector>

#include "signalreal.h"
#include "DefsWT.h"


class BlofeldWaveTableModel
{
    //gère une table d'onde soit une succession de 64 signaux
    QVector<SignalReal> _signals;
    QString _wtName;
public:
    BlofeldWaveTableModel();
    BlofeldWaveTableModel(const BlofeldWaveTableModel &other);
    void setSignal(int waveNum, SignalReal sr){_signals.replace(waveNum,sr);}
    const SignalReal *getSignal(int waveNum)const {return &_signals.at(waveNum);}
    SignalReal *editSignal(int waveNum) {return &_signals[waveNum];}
    const QVector<SignalReal> * getSignals() const{ return &_signals;}
    QString getName(){return _wtName;}

    int countSamples()const{return _signals.at(0).countSamples();}
    int countAnalysis()const{return _signals.at(0).countAnalysis();}
    int countWaves()const{return _signals.size();}


};



#endif // BLOFELDWAVETABLESMODEL_H
