#ifndef WAVEDFTCONTROLE_H
#define WAVEDFTCONTROLE_H

#include "mdrawertime.h"
#include "mdrawerfrequency.h"

class DSPControl: public QWidget
{
    Q_OBJECT

public:
    enum DrawMode {
        DrawTime=0,
        DrawPhase=1,
        DrawMagnitude=2
    };

    enum WaveType{
        WAVE_SINE=0,
        WAVE_TRIANGLE=1,
        WAVE_RAMP=2,
        WAVE_RANDOM=3,
        WAVE_SQUARE=4,
        WAVE_USER=5
    };



private:
    int from,to;

    bool _rotatePH,_rotateMG,_rotateT;
    int _lastSample, _currentSample;
    DrawMode _mode;
    MDrawerTime *_timeDomain;
    MDrawerFrequency *_frequencyDomain;
    SignalReal *_signal;

public:
    DSPControl( QWidget *parent, SignalReal * s);
    void setSignal(SignalReal * sig);
    void fillSignal(QVector<double> sig,int f);

signals:
    void updateAndJump();
    void everythingHasChanged();
private slots:
    void setDrawModeMagnitude(){_mode=DrawMagnitude;}
    void setDrawModePhase(){_mode=DrawPhase;}
    void setDrawModeRotateMG(bool state){ _rotateMG =state;}
    void setDrawModeRotatePH(bool state){_rotatePH =state;}
    void setDrawModeRotateT(bool state){_rotateT =state;}

    void startDomainF(int pos, double v);
    void startDomainT(int pos, double v);
    void followF(int pos, double v);
    void FollowT(int pos, double v);
    void stopFollowT(int pos, double v );
    void stopFollowF(int pos, double v );
private:
    void updateFromTo();
    QVector<double>  getSine(){return _signal->getSinus();}
    QVector<double> getSquare(int ratio){ return _signal->getSquare(ratio);}
    QVector<double>  getTriangle(){ return _signal->getTriangle();}
    QVector<double>  getRamp(){return _signal->getRamp();}
    QVector<double>  getRandom(){return _signal->getRandom();}
    void setSample(int id,double v);
    void setPhase(int id,double v);
    void setMagnitude(int id,double v);

    void valueIntegration(int );
    void valueDesintegration();

    void updateAllT();
    void updateAllF();
    QVector<double> *getEditedValues(DrawMode type);
    void morphAndUpdate(DrawMode type, int from, int to);
    void rotateT(int pos0);
    void rotatePH(int pos0);
    void rotateMG(int pos0);
    int getMin();
    int getMax();
    double transposeValueSample(double value);
    double transposeValuePhase(double value);
    double transposeValueMag(double value);

    friend class UIWaveTableMgrVue;
};

#endif // WAVEDFTCONTROLE_H
