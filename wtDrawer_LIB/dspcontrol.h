#ifndef WAVEDFTCONTROLE_H
#define WAVEDFTCONTROLE_H

#include "mdrawertime.h"
#include "mdrawerfrequency.h"

class DSPControl: public QWidget
{
    Q_OBJECT

public:

    enum WaveType{
        WAVE_SINE=0,
        WAVE_TRIANGLE=1,
        WAVE_RAMP=2,
        WAVE_RANDOM=3,
        WAVE_SQUARE=4,
        WAVE_USER=5
    };

private:
    int _lastSample, _currentSample;
    SignalReal::DrawMode _mode;
    MDrawerTime *_timeDomain;
    MDrawerFrequency *_frequencyDomain;
    SignalReal *_signal;

public:
    DSPControl( QWidget *parent, SignalReal * s);
    void setSignal(SignalReal * sig);

signals:
    void everythingHasChanged();
private slots:
    void setDrawModeMagnitude()
    {
        _mode=SignalReal::DrawMagnitude;
    }

    void setDrawModePhase()
    {
        _mode=SignalReal::DrawPhase;
    }

    void drawSine(int f);
    void drawSquare(int ratio,int f);
    void drawTriangle(int f);
    void drawRamp(int f);
    void drawRandom(int f);

    void startDomainF(int pos, double v);
    void startDomainT(int pos, double v);
    void sentFromDomainF(int pos, double v);
    void sentFromDomainT(int pos, double v);
    void stopFollowT(int pos, double v );
    void stopFollowF(int pos, double v );
private:

    void setSample(int id,double v);
    void setPhase(int id,double v);
    void setMagnitude(int id,double v);

    void valueIntegration(int );
    void valueDesintegration();

    void updateAllT();
    void updateAllF();

    void morphAndUpdate(int type);
    int getMin();
    int getMax();

    friend class UIWaveTableMgrVue;
};

#endif // WAVEDFTCONTROLE_H
