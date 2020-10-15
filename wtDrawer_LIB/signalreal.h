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

    enum SIG_Operation{
        OP_add= 0,
        OP_min = 1,
        OP_mul = 2
    };
    SignalReal(QVector<double>);
    SignalReal(QVector<double>,QVector<double>);
    SignalReal(int);
    SignalReal();
    SignalReal(const SignalReal &other);

    void addSignal(QVector<double>  v );
    void normalisePeaks();
    int countSamples()const{return _timeDomain.size();}
    int countAnalysis()const{return _magnitude.size();}

    void transform(SignalReal *other,SIG_Operation op);
    void setMagnitude(const QVector<double> *);
    void setPhase(const QVector<double> *);
    void setSamples(const QVector<double> *);

    void setMagnitude(int p,double v);
    void setPhase(int p,double v);

    void setSample(int sn, double sv);
    const QVector<double> *getValuesPh()const{return &_phase;}
    const QVector<double> *getValuesMg()const{return &_magnitude;}
    const QVector<double> *getSamples()const{return &_timeDomain;}
    double getSample(int p)const{return _timeDomain[p];}
    const double *editSample(int p){return &_timeDomain[p];}
    const double *editMagnitude(int p){return &_magnitude[p];}
    const double *editPhase(int p){return &_phase[p];}
    double getMagnitude(int p){return _magnitude[p];}
    double getPhase(int p){return _phase[p];}
    QVector<double> *editSamples(){return &_timeDomain;}
    QVector<double> *editMagnitude(){return &_magnitude;}
    QVector<double> *editPhase(){return &_phase;}
    void    dft();
    void    idft();
    void linearMorphing(QVector<double> *_toMorpg, int from, int to);
    void fillSignal(QVector<double> sig, int freq);


    void rotateMG(int samples);
    void rotatePH(int samples);
    void rotateT(int samples);
    void rotate(QVector<double> *values,int samples);
    void normalise();
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

    void multiplySignal(QVector<double>  v );
    void setGain(double v );


    friend class BlofeldWaveTableModel;


};


#endif // SIGNALREAL_H
