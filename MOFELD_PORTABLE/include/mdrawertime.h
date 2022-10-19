#ifndef MDRAWERTIME_H
#define MDRAWERTIME_H


#include "mdrawer.h"

class MDrawerTime
        :public MDrawer
{
public:
    MDrawerTime(SignalReal *m,QWidget * parent =0);
    QVector<double> *editSamples();
private:

//    double getSampleValue(int pos);
//    double getSampleValue(const QPoint &p);
    void drawBars(QPainter &painter);
    void drawLanczos(QPainter &painter);

protected:
    void paintDomain(QPainter &painter);
    int getSampleCount(){return _model->countSamples();}
    double transposeValue(double value);


};

#endif // MDRAWERTIME_H
