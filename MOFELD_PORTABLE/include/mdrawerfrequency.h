#ifndef MDRAWERFREQUENCY_H
#define MDRAWERFREQUENCY_H


#include "mdrawer.h"
#include "mcolorhelper.h"

class MDrawerFrequency
        :public MDrawer
{


public:

DrawMode _mode;
    MDrawerFrequency(SignalReal *s,QWidget * parent =0);
    void setDrawModePhase();
    void setDrawModeMAgnitude();
    QVector<double> *editPhase(){return _model->editPhase();}
    QVector<double> *editMag();

private:
//    double getSampleValue(int p);
//    double getSampleValue(const QPoint &p);
//    QColor getColorPhase(double phase);

protected:
    void paintDomain(QPainter &painter);
    int getSampleCount(){return _model->countAnalysis();}
    double transposeValue(double value);


};
#endif // MDRAWERFREQUENCY_H
