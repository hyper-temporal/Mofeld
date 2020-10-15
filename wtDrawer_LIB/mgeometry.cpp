#include "mgeometry.h"

MGeometry::MGeometry(const int x, const int y, QWidget *p)
    :QWidget(p),_divX(x),_divY(y)
{
}
double MGeometry::getPropTrimmed(int total,int part){

    if(part>total)return 1.0;
    if(part<0)return 0.0;
    return (double)part/total;
}


void MGeometry::mousePressEvent(QMouseEvent *me){

    _dX = 0;
    _dY = 0;
    _X = me->x();
    _Y = me->y();
    _frstX=_X;
    _frstY=_Y;

    startTracking();
}
void MGeometry::mouseMoveEvent(QMouseEvent *me){

    updateCoords(me);
    track();
}

void MGeometry::mouseReleaseEvent(QMouseEvent *me){

    _ColSelected = -1;
    _LineSelected =-1;
    _ColLast = -1;
    _LineLast =-1;

}

void MGeometry::updateCoords(QMouseEvent *me){
    _dX = _X - me->x();
    _dY = _Y - me->y();
    _X = me->x();
    _Y = me->y();
}


void MGeometry::startTracking()
{
    _ColSelected = getPosX();
    _LineSelected = getPosY();
    _ColLast = _ColSelected;
    _LineLast = _LineSelected;
    _ColOrig=_ColSelected;
    _LineOrig=_LineSelected;

}

void MGeometry::track(){

    _ColLast=_ColSelected;
    _LineLast=_LineSelected;

    _ColSelected = getPosX();
    _LineSelected = getPosY();
}
void MGeometry::stopTracking(){
    _ColLast=-1;
    _LineLast=-1;
    _ColSelected = -1;
    _LineSelected =-1;
    _ColOrig=-1;
    _LineOrig=-1;
}

int MGeometry::getPosX(){
    return _divX*getPropTrimmed(width(),_dX);
}

int MGeometry::getPosY(){
    return _divY*getPropTrimmed(height(),_dY);
}

int MGeometry::getMotionMin()
{
    if (_ColLast>0)
    {
        return _ColSelected;
    }else if (_ColLast<0){
        if (_ColSelected >= 0) return _ColSelected;
        else if (_ColLast >=0) return _ColLast;
        else return -1;
    }
}
int MGeometry::getMotionMax(){
    if (_ColLast>_ColSelected)
    {
        if(_ColLast>=0){return _ColLast;}
        else if (_ColSelected >= 0) return _ColSelected;
        else return -1;
    }else{
        if (_ColSelected >= 0) return _ColSelected;
        else if (_ColLast >= 0) return _ColLast;
        else return -1;
    }
}


