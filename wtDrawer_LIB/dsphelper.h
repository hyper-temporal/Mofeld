#ifndef DSPHELPER_H
#define DSPHELPER_H

#include <QVector>
#include "irealsignal.h"

class DSPHelper
        :public IRealSignal
{
    int _lanczosCoreSize;
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

    QVector<double> getLanczosCore (int sampleCount)const;
    QVector<double>  getLanckosz (const QVector<double> *src,int width)const;

protected:
    double sin_x(double) const;
    double cos_x(double) const;
private:
    void sinus();
};

#endif // DSPHELPER_H
