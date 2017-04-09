#ifndef DSPHELPER_H
#define DSPHELPER_H

#include <QVector>
#include "irealsignal.h"

class DSPHelper
        :public IRealSignal
{
    //LUTs
    int _ratio;
    int    _sinusPrecision;
    QVector<double> _sinus;
public:
    DSPHelper(unsigned int);
    QVector<double> getRandom();
    QVector<double> getSinus();
    QVector<double> getSquare(int percent);
    QVector<double> getRamp();
    QVector<double> getTriangle();
    void fillSignal (QVector<double>, QVector<double>*, int);

protected:
    double sin_x(double);
    double cos_x(double);
private:
    void sinus();
};

#endif // DSPHELPER_H
