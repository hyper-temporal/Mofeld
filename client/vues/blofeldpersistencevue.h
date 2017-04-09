#ifndef BLOFELDPERSISTENCEVUE_H
#define BLOFELDPERSISTENCEVUE_H

#include "BlofeldMgr/blofeldreplica.h"
#include "client/vues/edition/operationvue.h"
#include "client/vues/edition/arrangementvue.h"
#include "client/vues/edition/instrumentvue.h"
#include "client/vues/edition/proprietevue.h"
#include "client/vues/edition/proprieteelementsvue.h"
#include "client/Models/arrangementmodel.h"
#include "client/Models/operationModel.h"
#include "client/Models/wtmodel.h"
#include "client/vues/edition/wavetableselectvue.h"

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
