#ifndef UIWAVETABLEMGR_H
#define UIWAVETABLEMGR_H

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

    DSPControl *_SignalCtrl;
    BlofeldWaveTableMgrModel *_wavetableMgr;

    QLineEdit _wtName;
    QSpinBox _tableNum,_waveNum,_ratio;
    QPushButton _send;
    QRadioButton _sine,_triangle,_ramp,_square,_random,_wav;
    QDoubleSpinBox _gain;
    QRadioButton _plus,_minus,_multiplyWith,_multiplySelf;
    QRadioButton _filterCut,_filterPass;
    QSpinBox _frequency,_filterQ;
    QRadioButton _noJump,_jumpPrevious,_jumpNext;
    QPushButton _lockMag,_lockPhase,_normalise;

public:
    UIWaveTableMgrVue(QWidget *parent=0);
    BlofeldWaveTableMgrModel *getModel(){ return _wavetableMgr;}
signals:
    void drawWave(int type,int frequency);
    void sendTable(const BlofeldWaveTableModel *, int wtNum, QString wtName);
private slots:
    void drawSine();
    void drawSquare();
    void drawTriangle();
    void drawRamp();
    void drawRandom();
    void everythingHasChanged();
    void waveSelect(int v);
    void sendWaveTable();

private:
    void setNames();
    void arrangeLayout();
    void goNextTable();
    void goPreviousTable();
    SignalReal *editCurrentSignal();
    const SignalReal *getCurrentSignal();
    void setSignal();

    void setWaveNum(int v);
};

#endif // UIWAVETABLEMGR_H
