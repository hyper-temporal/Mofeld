#ifndef BLOFELDPERSISTENCEVUE_H
#define BLOFELDPERSISTENCEVUE_H

#include "blofeldreplica.h"
#include "operationvue.h"
#include "arrangementvue.h"
#include "instrumentvue.h"
#include "proprietevue.h"
#include "proprieteelementsvue.h"
#include "arrangementmodel.h"
#include "operationModel.h"
#include "wtmodel.h"
#include "wavetableselectvue.h"

class BlofeldPersistenceVue
        :public QWidget
{
    Q_OBJECT

    QWidget *_wTargetCtrl;
    ArrangementModel *_arrModel;
    InstrumentModel *_instruModel;
    ProprieteModel *_proprieteModel;
    OperationModel  * _OperationModel;
    WaveTableSelectVue *_wtVue;
    WTModel *_wtModel;
    BlofeldReplica *_synth;
    ArrangementVue *_arrVue;
    InstrumentVue *_instruVue;
    ProprieteVue *_propsVue;
    ProprieteElementsVue *_propsElementVue;
public:
    BlofeldPersistenceVue(BlofeldReplica *blofeld);
private slots:
    void updateView(const Arrangement * a);
    void updateView(const Instrument * i);
    void updateView(const Parametre * p);
    void updateView(int pid);
    void updateView(const Propriete * p);
private:
    void updatePElements();
    void updateInstrumentView();
};

#endif // BLOFELDPERSISTENCEVUE_H
