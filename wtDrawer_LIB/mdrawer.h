#ifndef MDRAWER_H
#define MDRAWER_H



#include <QWidget>
#include <QDial>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPainter>
#include "signalreal.h"
#include "mcolorhelper.h"

class MDrawer
        :public QWidget, public MColorHelper
{
    Q_OBJECT

    QVector<bool> _locked;
    bool _ctrl,_alt,_left,_right;
protected:
    SignalReal * _model;
    QString _name ;

public:
    enum DrawMode{
        DM_PHASE=0,
        DM_MAGNI=1
    };
    enum DrawType{
        DM_VALUES=0,
        DM_TRANSLATE=1
    };
    MDrawer(SignalReal *m, QWidget * parent =0 );
    void mouseToValue();

private:

    void mouseToValue(const QPoint &);
    double getPhase(const QPoint &);

    void requestValue(QMouseEvent *);
    int getSampleNumber(QMouseEvent *me);

public slots:
     void setSignal(SignalReal *m);
signals:
    void follow(int,double);
    void stopFollow(int,double);
    void startFollow(int,double);
private slots:
    void mousePressEvent(QMouseEvent *me);
    void mouseMoveEvent(QMouseEvent *me);
    void mouseReleaseEvent(QMouseEvent *me);

protected:
    double getSampleValue(const QPoint &p);
    virtual int getSampleCount()=0;
    void paintEvent(QPaintEvent *);
    virtual void paintDomain(QPainter &painter)=0;

    QSize minimumSizeHint() const
    {   return QSize(4, 84);    }

    QSize sizeHint() const
    {   return QSize(4, 128);    }

};



#endif // MDRAWER_H
