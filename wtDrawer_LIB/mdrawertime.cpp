#include "mdrawertime.h"
#include "sliceotime.h"

using namespace std;

MDrawerTime::MDrawerTime(SignalReal *m, QWidget *p)
    :MDrawer(m,p)
{
    _name ="Samples";

    for(int i(0);i<_model->countSamples();i++)
    {
        _slices.append( new SliceOTime( _model->editSample(i),this));
        layout()->addWidget(_slices.last());
    }
}

void MDrawerTime::refresh()
{
    for(int i(0);i<_model->countSamples();i++)
    {
        SliceOTime*slice = static_cast< SliceOTime*>( _slices.at(i));
        slice->setModel( _model->editSample(i));
    }
}


double MDrawerTime::getSampleValue(int pos){
    return _model->getSample(pos);
}

double MDrawerTime::getSampleValue(const QPoint &p)
{
    double ret;

    if(height()<2) return 0.0;
    if(p.y()<0){
        return 1.0;
    }
    else if(p.y()>height())
    {
        return -1.0;
    }
    else
    {
        int offset = height()/2;
        int sansOffset;

        if(p.y()==offset)
        {
            return 0.0;
        }
        else if(p.y() > offset)
        {
            sansOffset = offset -p.y();
        }else{
            sansOffset = - (p.y()- offset);
        }
        ret = (double)2*sansOffset/height();
    }
    if(ret<-1.0){
        ret= -1.0;
    }
    else if(ret>1.0)
    {
        ret= 1.0;
    }
    else if(ret < 0.001 && ret>-0.001)return 0.0;
    return ret;
}



