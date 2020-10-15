#ifndef MSOUNDPRINTERVUE_H
#define MSOUNDPRINTERVUE_H



#include <QMouseEvent>
#include <QDial>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPainter>
#include "blofeldwavetablemgrmodel.h"
#include "mgeometry.h"
#include "mcolorhelper.h"

class MSoundPrinterVue
        :public MGeometry,public MColorHelper
{

    Q_OBJECT

    int _slctWave,_slctFrequency;
    BlofeldWaveTableModel _model;

public:

    MSoundPrinterVue(BlofeldWaveTableModel *m, QWidget * parent =0 );
    void mouseToValue();

private:
    int getWaveValue(const QPoint &p);
    int getFrequencyValue(const QPoint &p);

    double getNewPhs();
    double getNewMgn();


signals:
    void modifyWave(int wn,int fn, double mg, double ph);
protected slots:
    void mousePressEvent(QMouseEvent *me);
    void mouseMoveEvent(QMouseEvent *me);
    void mouseReleaseEvent(QMouseEvent *me);

protected:

    void paintEvent(QPaintEvent *);
    void drawWave(int wn,QPainter &painter);

    QSize minimumSizeHint() const
    {   return QSize(128, 128);    }

    QSize sizeHint() const
    {   return QSize(128, 128);    }

};


#endif // MSOUNDPRINTERVUE_H
