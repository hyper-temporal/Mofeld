#ifndef SIGNALREAL_H
#define SIGNALREAL_H


#include <QVector>
#include <QSettings>
#include "dsphelper.h"
#include "DefsWT.h"

class SignalReal
        :public DSPHelper
{
    QVector<double> _timeDomain;
    QVector<double> _magnitude;
    QVector<double> _phase;
public:
    enum DrawMode {
        DrawTime=0,DrawPhase=1, DrawMagnitude=2
    };
    SignalReal(QVector<double>);
    SignalReal(QVector<double>,QVector<double>);
    SignalReal(int);
    SignalReal();
    SignalReal(const SignalReal &other);

    void normalisePeaks();
    int countSamples(){return _size;}
    int countAnalysis(){return 1+_size/2;}
    void setSignal(QVector<double>);
    void setSignal(QVector<double>,QVector<double>);

    void setMagnitude(int p,double v);
    void setPhase(int p,double v);

    void setSample(int sn, double sv);
    const QVector<double> *getSamples()const{return &_timeDomain;}
    double getSample(int p)const{return _timeDomain[p];}
    const double *editSample(int p){return &_timeDomain[p];}
    const double *editMagnitude(int p){return &_magnitude[p];}
    const double *editPhase(int p){return &_phase[p];}
    double getMagnitude(int p){return _magnitude[p];}
    double getPhase(int p){return _phase[p];}

    void    dft();
    void    idft();
    void linearMorphing(int type, int from, int to);
    void fillSignal(QVector<double> sig, int freq);

    void rotate(int );
private:

    void    Pol2RectInPlace(double* Magn2Real, double* Phase2Imag);
    double   polarMagnitude(double  real, double  imag );
    double   polarPhase(double  real, double  imag);
    void    Rect2PolInPlace(double* Real2Magn, double* Imag2Phase);
    void    NormalisePolar(double* Magn, double* Phase);
    void    ApplyFilter(double* time_tab, double* RealTab, double* ImagTab);
    void    iir_narrowband(int periode, int bandwidth, int ftype);
    void    iir_simplepass(double buffer[]);

    void clearTimeDomain();
    void clearAnalysis();

    friend QDataStream & operator << (QDataStream &, const SignalReal &);
    friend QDataStream & operator >> (QDataStream &, SignalReal &);
};
Q_DECLARE_METATYPE(SignalReal)
QDataStream & operator << (QDataStream & out, const SignalReal & Valeur);
QDataStream & operator >> (QDataStream & in, SignalReal & Valeur);

#endif // SIGNALREAL_H
