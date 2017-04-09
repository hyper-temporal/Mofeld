#ifndef MDRAWER_H
#define MDRAWER_H



#include <QWidget>
#include <QDial>
#include <QGroupBox>
#include <QHBoxLayout>

#include "wavedrawerslice.h"
#include "signalreal.h"

class MDrawer
        :public QWidget
{
    Q_OBJECT

    bool _ctrl,_alt,_left,_right;
protected:
    SignalReal * _model;
    QVector<DrawerSlice*> _slices;
    QString _name ;

public:
    MDrawer(SignalReal *m, QWidget * parent =0 );

public slots:
    void UpdateAll();
    void UpdateOne(int id);
    int getSliceCount(){return _slices.count();}
    void setSignal(SignalReal *m);
signals:
    void sendValue(int,double);
    void stopFollow(int,double);
    void startFollow(int,double);
private slots:
    void mousePressEvent(QMouseEvent *me);
    void mouseMoveEvent(QMouseEvent *me);
    void mouseReleaseEvent(QMouseEvent *me);
private:
    void requestValue(QMouseEvent *);
    double mouseToValue();
    int getSampleNumber(QMouseEvent *me);
protected:
    virtual double getSampleValue(const QPoint &p)=0;
    virtual void refresh()=0;
//    void setValue(int id,double value);


    QSize minimumSizeHint() const
    {   return QSize(4, 84);    }

    QSize sizeHint() const
    {   return QSize(4, 127*3);    }

};

#endif // MDRAWER_H
