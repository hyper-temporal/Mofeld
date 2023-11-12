#ifndef MGEOMETRY_H
#define MGEOMETRY_H

#include <QWidget>
#include <QMouseEvent>

class MGeometry
        :public QWidget
{
    Q_OBJECT

    int _X,_Y,
    _dX,_dY,
    _frstX, _frstY;
protected:
    const int _divX,_divY;
    int _ColSelected, _LineSelected,
    _ColLast,_LineLast,
    _ColOrig,_LineOrig;
public:
    MGeometry(const int x, const int y, QWidget *p);
    double getPropTrimmed(int ,int);
signals:
    void mouseMovedwithXSelected(int posX, double vx);
    void mouseMovedwithYSelected(int posY, double vy);
    void mouseMovedwithXYSelected(int posX, int posY,double vx, double vy);

protected slots:
    void mousePressEvent(QMouseEvent *me);
    void mouseMoveEvent(QMouseEvent *me);
    void mouseReleaseEvent(QMouseEvent *me);

    void startTracking();
    void track();
    void stopTracking();
private:
    void updateCoords(QMouseEvent *me);
    void valueIntegration(int pos );
    int getPosX();
    int getPosY();

    int getMotionMin();
    int getMotionMax();
    void updateFromTo();
};

#endif // MGEOMETRY_H
