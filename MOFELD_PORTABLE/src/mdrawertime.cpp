#include "mdrawertime.h"

using namespace std;

MDrawerTime::MDrawerTime(SignalReal *m, QWidget *p)
    :MDrawer(m,p)
{}


void MDrawerTime::paintDomain(QPainter &painter)
{
    auto datas = _model->getSamples();
    int nbsegments = datas->size();
    QPoint pav(0.0, height()*(1.0-( 0.5+ 0.5 * datas->at(0))));
    double tseg_d = (double)width()/(nbsegments);
    double dwidth(0.0);
    for(int inx(1);inx <= nbsegments;inx++){
        dwidth += tseg_d;
        double vp = 0.5+ 0.5* datas->at(inx-1);
        double h =  height()*(1.0-vp);
        QPoint npo(pav);
        npo.setY(h);
        painter.drawLine( QLine(pav,npo));
        QPoint npv(dwidth,h);
        painter.drawLine( QLine(npo,npv));
        pav = npv;
    }



}

