#ifndef UIWAVETABLEMGR_H
#define UIWAVETABLEMGR_H


#include <QKeyEvent>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QRadioButton>
#include <QGroupBox>
#include <QLineEdit>

#include "dspcontrol.h"
#include "blofeldwavetablemgrmodel.h"
#include "targetprovider.h"

class UIWaveTableMgrVue
        :public QWidget
{

    Q_OBJECT
    TargetProvider *_tp;
    SignalReal _waveBuffer;
    BlofeldWaveTableMgrModel _wavetableMgr;
    DSPControl _SignalCtrl;

    QLineEdit _wtName;
    QSpinBox _tableNum,_waveNum,_ratio;
    QPushButton _send,_sendAll;
    QRadioButton _sine,_triangle,_ramp,_square,_random,_user,_wav;
    QDoubleSpinBox _gain;
    QRadioButton _plus,_minus,_multiplyWith,_multiplySelf;
    QRadioButton _filterCut,_filterPass;
    QSpinBox _frequency,_filterQ;
    QRadioButton _noJump, _jumpLEFT, _jumpRIGHT, _jumpDOWN, _jumpUP;
    QPushButton _lockMag,_lockPhase,_lockWave,_normalise, _cuttingEdges;

    QRadioButton _autoBEFORE,_autoAFTER;
public:
    UIWaveTableMgrVue(TargetProvider * target, QWidget *parent=0);
    BlofeldWaveTableMgrModel *getModel(){ return &_wavetableMgr;}
    SignalReal *editCurrentSignal();
    const SignalReal *getCurrentSignal();

signals:
    void drawWave(int type,int frequency);
    void sendTable(const BlofeldWaveTableModel *, int wtNum, QString wtName);
    void sendAllTables(const QVector<BlofeldWaveTableModel>  *);
public slots:
    void setDrawModePhase(){_SignalCtrl.setDrawModePhase();}
    void setDrawModeMagnitude(){_SignalCtrl.setDrawModeMagnitude();}
    void setDrawModeRotationMG(bool state){_SignalCtrl.setDrawModeRotateMG(state);}
    void setDrawModeRotationPH(bool state){_SignalCtrl.setDrawModeRotatePH(state);}
    void setDrawModeRotationT(bool state){_SignalCtrl.setDrawModeRotateT(state);}

    void onModify();
    void  addSignal(QVector<double> sig );
    void normalise();
    void cutEdges();
private slots:

    void draw();
    void updateAndJump();
    void everythingHasChanged();
    void waveSelect(int wn);
    void tableSelect(int tn);
    void sendWaveTable();
    void sendAllWaveTables();
    int getpos(int wavenum);
private:
    void setNames();
    void arrangeLayout();
    void setSignal();
    QVector<double> getSignal();
    SignalReal *editSignal();

};

#endif // UIWAVETABLEMGR_H
