#ifndef MGEOMETRY_H
#define MGEOMETRY_H

#include <QWidget>
#include <QMouseEvent>
/*

Classe dont la responsabilitée est de donner des informations
sur les evenements qui ont lieu a partir des clics et deplacement par rapport a la surface du widget
cellule selectionnée

*/

///TODO ajouter les constructeur et methodes necessaire pour que cette classe soit un prototype pour des implementation differentes de comportement d'une surface seravant a modifier des valeurs dans une matrice
//dimension,
class MGeometry
        :public QWidget
{
    Q_OBJECT

    //position actuelle
    int _X,_Y,
    //deplacement instantane
    _dX,_dY,
    //position d'origine(click)
    _frstX, _frstY;
protected:
    const int _divX,_divY;
    //case actuelle
    int _ColSelected, _LineSelected,
    //case avant deplacement
    _ColLast,_LineLast,
    //case d'origine (click)
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
