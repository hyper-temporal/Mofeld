#ifndef WAVEDRAWERSLICE_H
#define WAVEDRAWERSLICE_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>


class DrawerSlice
        :public QWidget
{
    Q_OBJECT


    //TODO: utiliser dérivée 1 ,2 pour lisser la courbe
public:
    DrawerSlice(QWidget *parent=0);
    void mouseToValue();

private:
    void mouseToValue(const QPoint &);
    double getPhase(const QPoint &);

    void paintEvent(QPaintEvent *);
    virtual void paintDomain(QPainter &painter)=0;
signals:
    void startTracking();
    void stopTracking();
    void sendSample(int,double);
};


///COULEURS PHASE
#define     MVALUE  255
#define     AVALUE  120
#define     BVALUE  100
#define     OVALUE  10

#define     REDAT1      MVALUE
#define     GREENAT1    MVALUE
#define     BLUEAT1     BVALUE

#define     REDAT2      AVALUE
#define     GREENAT2    MVALUE
#define     BLUEAT2     BVALUE

#define     REDAT3      BVALUE
#define     GREENAT3    BVALUE
#define     BLUEAT3     MVALUE

#define     REDAT4      MVALUE
#define     GREENAT4    BVALUE
#define     BLUEAT4     BVALUE

#define     LCDBACKLIGHT    255,255,255
#define     LCDROUNDING     20,20,20


#endif // WAVEDRAWERSLICE_H
