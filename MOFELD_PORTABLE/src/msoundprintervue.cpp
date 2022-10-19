#include "msoundprintervue.h"

MSoundPrinterVue::MSoundPrinterVue(BlofeldWaveTableModel *m, QWidget *parent)
    :MGeometry(m->countWaves(),m->countAnalysis(),parent)
{}

void MSoundPrinterVue::mousePressEvent(QMouseEvent *me){
    MGeometry::mousePressEvent(me);
}


void MSoundPrinterVue::mouseMoveEvent(QMouseEvent *me){

    MGeometry::mouseMoveEvent(me);

    //si on a une wave et une frequence de selectionnées
        //on actualise les données de déplacement
        //on calcule la nouvelle valeur de phase et de magnitude
        //on envoie le signal au model qui actualise les données et envoie les différents signaux d'update
    //sinon on selectionne la forme d'onde et la frequence
    //on actualise la position actuelle
    int wnum= _model.countWaves()*getPropTrimmed(width(),me->x());
    int fnum= _model.countAnalysis()*getPropTrimmed(height(),me->y());

}

void MSoundPrinterVue::mouseReleaseEvent(QMouseEvent *me){
    MGeometry::mouseReleaseEvent(me);
}

int MSoundPrinterVue::getWaveValue(const QPoint &p){
    int wtSize =_model.countWaves();
    double fvalue ;
    if( p.x() > width()) fvalue = 1.0;
    else if( p.y() < 0)fvalue= 0.0;
    else fvalue =(double)p.x()/width();
    return fvalue * wtSize ;
}

int MSoundPrinterVue::getFrequencyValue(const QPoint &p){
    int spectrum = _model.countAnalysis();

    double fvalue ;
    if( p.y() > height()) fvalue = 0.0;
    else if( p.y() < 0)fvalue= 1.0;
    else fvalue =(1.0 - (double)p.y()/height());
    return fvalue * spectrum ;
}

void MSoundPrinterVue::paintEvent(QPaintEvent * pe)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    for(int cntW(0);cntW<_model.countWaves();cntW++){
        drawWave(cntW,painter);
    }
}
#define _USE_MATH_DEFINES
#include <math.h>

void MSoundPrinterVue::drawWave(int wn,QPainter &painter)
{
    const SignalReal *s= _model.getSignal(wn);

    QVector<double>   vph =s->getLanckosz(s->getValuesPh(),height());
    QVector<double>   vMg =s->getLanckosz(s->getValuesMg(),height());

    int brillance;
    double vm,vp;

    for(int i(1);i<height();i++)
    {
        //calcul brillance
        brillance =  vMg.at(height()-i);
        //calcul couleur
        vp =  vph.at(height()-i)/(2*M_PI);

        QColor c = scaleColor(_clr_White,getColorPhase(vp),vm);
        painter.setPen(QPen(c));

        double w = (double)width()/_divX;
        int ox = _slctWave*w;
        painter.drawLine(QPoint(ox,height()-i),QPoint(ox+w,height()-i));
    }
}

