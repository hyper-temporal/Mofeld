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
#include "DefsWT.h"

class UIWaveTableMgrVue
        :public QWidget
{

    Q_OBJECT

    SignalReal _waveBuffer;
    DSPControl *_SignalCtrl;
    BlofeldWaveTableMgrModel *_wavetableMgr;

    QLineEdit _wtName;
    QSpinBox _tableNum,_waveNum,_ratio;
    QPushButton _send;
    QRadioButton _sine,_triangle,_ramp,_square,_random,_user,_wav;
    QDoubleSpinBox _gain;
    QRadioButton _plus,_minus,_multiplyWith,_multiplySelf;
    QRadioButton _filterCut,_filterPass;
    QSpinBox _frequency,_filterQ;
    QRadioButton _noJump,_jumpPrevious,_jumpNext;
    QPushButton _lockMag,_lockPhase,_lockWave,_normalise, _cuttingEdges;

    QCheckBox _cbAfterMorph,_cbNoMorph;
public:
    UIWaveTableMgrVue(QWidget *parent=0);
    BlofeldWaveTableMgrModel *getModel(){ return _wavetableMgr;}
    SignalReal *editCurrentSignal();
    const SignalReal *getCurrentSignal();

signals:
    void drawWave(int type,int frequency);
    void sendTable(const BlofeldWaveTableModel *, int wtNum, QString wtName);
public slots:
    void setDrawModePhase(){_SignalCtrl->setDrawModePhase();}
    void setDrawModeMagnitude(){_SignalCtrl->setDrawModeMagnitude();}
    void setDrawModeRotationMG(bool state){_SignalCtrl->setDrawModeRotateMG(state);}
    void setDrawModeRotationPH(bool state){_SignalCtrl->setDrawModeRotatePH(state);}
    void setDrawModeRotationT(bool state){_SignalCtrl->setDrawModeRotateT(state);}

    void onModify();
    void  addSignal(QVector<double> sig );
    void normalise();
    void cutEdges();
private slots:

    void draw();
//    void setNormalise();
    void updateAndJump();
    void everythingHasChanged();
    void waveSelect(int v);
    void sendWaveTable();

    int getpos(int wavenum);


//    void opUser();
//    void opSine();
//    void opSquare();
//    void opTriangle();
//    void opRamp();
//    void opRandom();
private:
    void setNames();
    void arrangeLayout();
    bool goNextTable();
    bool goPreviousTable();

    void setSignal();
    QVector<double> getSignal();
    SignalReal *editSignal();

    void setWaveNum(int v);
};

#endif // UIWAVETABLEMGR_H
