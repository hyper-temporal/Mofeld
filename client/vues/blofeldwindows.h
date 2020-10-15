#ifndef BLOFELDWINDOWS_H
#define BLOFELDWINDOWS_H

#include <QWidget>
#include <QTabWidget>
#include <QToolButton>

#include "blofeldEditorVue.h"

#include "client/vues/edition/operationvue.h"
#include "client/vues/edition/arrangementvue.h"
#include "client/vues/edition/instrumentvue.h"
#include "client/vues/edition/proprietevue.h"
#include "client/vues/edition/proprieteelementsvue.h"
#include "client/Models/arrangementmodel.h"
#include "client/Models/operationModel.h"


#include "client/vues/edition/wavetableselectvue.h"
#include "client/vues/blofeldmultivue.h"



class ParamContext;

class BlofeldViews
        :public QWidget
{
    Q_OBJECT

    Patienteur _patienteur;
    UIWaveTableMgrVue *_wtEditor;

    BlofeldMultiVue *_multi;
    BlofeldEditorVue *_editor;
    OperationVue *_CommonVue;
//    QWidget *_wTargetCtrl;
    QWidget *_wMulti,*_wToolBar;

    WaveTableSelectVue *_wtVue;
    WTModel *_wtModel;

    ArrangementVue *_arrVue;
    InstrumentVue *_instruVue;
    ProprieteVue *_propsVue;
    ProprieteElementsVue *_propsElementVue;

    QAction *actionQuitter;

    BlofeldReplica * _synth;

    ArrangementModel *_arrModel;
    InstrumentModel *_instruModel;
    ProprieteModel *_proprieteModel;
    OperationModel  * _OperationModel;

public:
    BlofeldViews(QWidget *par);
    ~BlofeldViews();

    QWidget *getMultiView(){return _multi;}
    QWidget *getEditorWidget(){return _editor;}
//    QWidget *getTargetWidget(){return  _wTargetCtrl;}
    QWidget *geOperationView(){return  _CommonVue;}
    QWidget *getWaveTableEditor(){return _wtEditor;}


private:
    void updatePElements();
    void updateInstrumentView();
    void recevoirInstrument(Instrument * i,int ch);
signals:
    void  updateStyle(QString s);

private slots:
    void closeEvent(QCloseEvent *);

public slots:
    void setMinimum(int,int,ParamContext*);
    void setMaximum(int,int,ParamContext*);
    void setPropriete(int,bool,ParamContext*);
    void restrictValue(int,ParamContext*);
    void updateContext(int pid, ParamContext *pc);
    void recevoirTables(const BlofeldWaveTableMgrModel *m);
    void recevoirArrangement(const Arrangement * a);
    void recevoirInstrument(const Instrument *i);
    void recevoirPropriete(const Propriete * p);
    void setParametre(int pid, int v);



   void k_generate(){ }
   void k_onModifyStretch(){ }
    void k_onModifyRestrict(){ }
    void k_CopyWave(){ }
    void k_PasteWave(){ }

void k_prevWaveTable(){ }
void k_nextWaveTable(){ }
void k_NextFrequency(){ }
    void k_PrevFrequency(){ }
    void k_NextTable(){ }
    void k_PrevTable(){ }
    void k_nextWave(){ }
    void k_prevWave(){ }
    void k_Drawers4Rotation(){ }
    void k_Drawer4Phase(){ }


    //TODO IMPLEMENTER MEDIATOR (avec signaux et slots)
    void updateView(const Arrangement * a);
    void updateView(const Instrument * i);
    void updateView(const Parametre * p);
    void updateView(int pid);
    void updateView(const Propriete * p);

    void SetInstrumentName(QString);
    void deleteProprietes(QVector<int> propIdsChannel);

    void ImportInstrument(int bank, int pgm);
    void Reimport();
    void ReGenerate();
    void UpdateChannel(int channel);

    void multiRequest(int);
    void multiSend(int);
    void updateMultiView();
 private:
    CtrlParamLeaf * GetCtrl(int ad1,int ad2);

};

#endif // BLOFELDWINDOWS_H
