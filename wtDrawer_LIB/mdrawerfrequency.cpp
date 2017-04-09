#include "mdrawerfrequency.h"
#include <QMouseEvent>
#include <cmath>
#include <QDebug>

using namespace std;

MDrawerFrequency::MDrawerFrequency(SignalReal *s,QWidget *p )
    :MDrawer(s,p)
{
    _name ="Frequencies";
    for(int i(0);i<_model->countAnalysis();i++)
    {
        _slices.append( new SliceOFrequency( _model->editMagnitude(i),_model->editPhase(i),this));
        layout()->addWidget(_slices.last());
    }
}

void MDrawerFrequency::refresh()
{
    for(int i(0);i<_model->countAnalysis();i++)
    {
        SliceOFrequency *slice = static_cast<SliceOFrequency*>( _slices.at(i));
        slice->setModel( _model->editMagnitude(i),_model->editPhase(i));
    }
}

double MDrawerFrequency::getSampleValue(const QPoint &p)
{
    if( p.y() > height()) return 0.0;
    else if( p.y() < 0)return 1.0;
    else return  1.0 - (double)p.y()/height();
}

