#ifndef BLOFELDWINDOWS_H
#define BLOFELDWINDOWS_H

#include <QWidget>
#include <QTabWidget>
#include <QToolButton>

#include "blofeldEditorVue.h"

#include "operationvue.h"
#include "arrangementvue.h"
#include "instrumentvue.h"
#include "proprietevue.h"
#include "proprieteelementsvue.h"
#include "arrangementmodel.h"
#include "operationModel.h"


#include "wavetableselectvue.h"
#include "targetprovider.h"
#include "uiwavetablemgrvue.h"
#include "blofeldmultivue.h"


class ParamContext;

class BlofeldViews
        :public QWidget
        ,public IBlofeldView
{
    Q_OBJECT
    QAction quitAction;
    TargetProvider _tp;
    BlofeldEditorVue _editor;
    OperationModel   _OperationModel;
    OperationVue _CommonVue;
    UIWaveTableMgrVue _wtEditor;
    WTModel _wtModel;
    WaveTableSelectVue _wtVue;

    ArrangementModel _arrModel;
    InstrumentModel _instruModel;
    ProprieteModel _proprieteModel;
    ArrangementVue _arrVue;
    ProprieteVue _propsVue;
    InstrumentVue _instruVue;
    ProprieteElementsVue _propsElementVue;

    Patienteur _patienteur;
    BlofeldMultiVue _multi;
public:
    BlofeldViews(QWidget *par);
    ~BlofeldViews();


    QWidget *getEditorWidget(){return &_editor;}
    QWidget *geOperationView(){return  &_CommonVue;}
    QWidget *getWaveTableEditor(){return &_wtEditor;}
    QWidget *getMultiEditor(){return &_multi;}

    void updateView(const Arrangement * a)final;
    void updateView(const Instrument * i)final;
    void updateView(const Parametre * p)final;
    void updateView(int pid)final;
    void updateView(const Propriete * p)final;

private:

    void initWTEditor(QWidget *parent);
    void initMidiIO(QWidget *parent);

    void updatePElements();
    void updateInstrumentView();
    void recevoirInstrument(Instrument * i,int ch);
//signals:
//    void  updateStyle(QString s);

private slots:
    void closeEvent(QCloseEvent *);

public slots:
    void setSynthId(int bid);



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
