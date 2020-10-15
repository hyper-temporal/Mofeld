#include "dspcontrol.h"

#include <math.h>
DSPControl::DSPControl(QWidget *parent, SignalReal *sig)
    : QWidget(parent)
    ,_rotatePH(false)
    ,_rotateMG(false)
    ,_rotateT(false)
{
    _signal = sig;
//    _normalise=false;
    _lastSample = -1;
    _currentSample = -1;

    _mode = DrawMagnitude;
    _frequencyDomain = new MDrawerFrequency(_signal,parent);
    _timeDomain  = new MDrawerTime(_signal,this);


    connect( _timeDomain, SIGNAL(follow(int,double)),
             this, SLOT(FollowT(int,double)));
    connect( _timeDomain, SIGNAL(startFollow(int,double)),
             this, SLOT(startDomainT(int,double)));
    connect( _timeDomain, SIGNAL(stopFollow(int,double)),
             this, SLOT(stopFollowT(int,double)));

    connect( _frequencyDomain, SIGNAL(follow(int,double)),
             this, SLOT(followF(int,double)));
    connect( _frequencyDomain, SIGNAL(startFollow(int,double)),
             this, SLOT(startDomainF(int,double)));
    connect( _frequencyDomain, SIGNAL(stopFollow(int,double)),
             this, SLOT(stopFollowF(int,double)));



//    QGroupBox *gbTimeD = new QGroupBox("Time Domain");
//    gbTimeD->setLayout(_timeDomain->layout());
//    QGroupBox *gbFreqD = new QGroupBox("Frequency Domain");
//    gbFreqD->setLayout(_frequencyDomain->layout());

    QVBoxLayout *lyDrawingPanel  = new QVBoxLayout;
    lyDrawingPanel->addWidget(_timeDomain);
    lyDrawingPanel->addWidget(_frequencyDomain);
    setLayout(lyDrawingPanel);
    setMinimumWidth(256);
    setMinimumHeight(105);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

void DSPControl::setSignal(SignalReal * sig){
    _signal = sig;
    _timeDomain->setSignal(_signal);
    _frequencyDomain->setSignal(_signal);
}


void DSPControl::setSample(int pos,double v){
    _signal->setSample(pos,transposeValueSample(v));
//    _signal->dft();
//    _timeDomain->UpdateOne(pos);
//    _frequencyDomain->UpdateAll();
//    emit everythingHasChanged();

}

void DSPControl::setPhase(int pos,double v)
{
    _signal->setPhase(pos,transposeValuePhase(v));
//    _signal->idft();
//    _signal->normalisePeaks();
//    _signal->dft();
//    _frequencyDomain->UpdateOne(pos);
//    _timeDomain->UpdateAll();
//    emit everythingHasChanged();

}
void DSPControl::setMagnitude(int pos,double v)
{
    _signal->setMagnitude(pos,transposeValueMag(v));
//    _signal->idft();
//    _signal->normalisePeaks();
//    _signal->dft();
//    _frequencyDomain->UpdateOne(pos);
//    _timeDomain->UpdateAll();
//    emit everythingHasChanged();

}

QVector<double> *DSPControl::getEditedValues(DrawMode type){

    if(type==DrawTime){
        return _signal->editSamples();
    }
    else if(type == DrawMagnitude)
    {
        return _signal->editMagnitude();
    }
    else if(type == DrawPhase){
        return _signal->editPhase();
    }

    return NULL;

}
void DSPControl::rotateT(int pos0){
    _signal->rotateT(pos0);

}
void DSPControl::rotateMG(int pos0){
    _signal->rotateMG(pos0);
}
void DSPControl::rotatePH(int pos0){
    _signal->rotatePH(pos0);
}

void DSPControl::morphAndUpdate(DrawMode type, int from, int to)
{

     QVector<double> *tomorph = getEditedValues(type);
     if(tomorph==NULL)return;


    _signal->linearMorphing(tomorph,from,to);

    switch(type){
    case DrawTime:
        updateAllF();
        break;
    case DrawPhase:
        updateAllT();
        break;
    case DrawMagnitude:
        updateAllT();
        break;
    default:
        break;
    }
}


void DSPControl::fillSignal(QVector<double> sig,int f)
{
   _signal->fillSignal(sig,f);
    updateAllF();
}


void DSPControl::updateAllT()
{
    _signal->idft();
    emit everythingHasChanged();

}
void DSPControl::updateAllF()
{
    _signal->dft();
    emit everythingHasChanged();
}


void DSPControl::stopFollowT(int pos, double v )
{
    valueDesintegration();
    emit  updateAndJump();
}

void DSPControl::stopFollowF(int pos, double v )
{
    valueDesintegration();
    emit  updateAndJump();
}


double DSPControl::transposeValueSample(double value){

    return  -1.0+2*value;
}
#define _USE_MATH_DEFINES
#include <math.h>

double DSPControl::transposeValuePhase(double value){
    return 2*M_PI*(value);

}
double DSPControl::transposeValueMag(double value){
    return  value;
}

void DSPControl::startDomainF(int pos, double v)
{
    followF(pos,v);
}

void DSPControl::startDomainT(int pos, double v)
{
    FollowT(pos,v);
}

void DSPControl::followF(int pos, double v)
{
    valueIntegration(pos);
    try {
        if(!(_rotatePH || _rotateMG)){
            if(_mode==DrawMagnitude){
                setMagnitude(pos,v);
            }
            else if(_mode==DrawPhase){
                setPhase(pos,v);
            }

        }else{
            from = getMin();
            to = getMax();
        }
        if(_rotatePH)
        {
            if(_currentSample>_lastSample){
                _signal->rotatePH(to-from);
            }else if(_lastSample>_currentSample){
                _signal->rotatePH(from-to);
            }
        }
        if( _rotateMG)
        {
            if(_currentSample>_lastSample){
                _signal->rotateMG(to-from);
            }else if(_lastSample>_currentSample){
                _signal->rotateMG(from-to);
            }
        }
        updateFromTo();

        if(!(_rotatePH || _rotateMG))
        {
            morphAndUpdate(_mode,from,to);
        }else{
            updateAllT();
        }

    } catch (...) {
    }
}

void DSPControl::FollowT(int pos, double v){
    valueIntegration(pos);
    try {

        if(! _rotateT)
        {
            setSample(pos,v);
            updateFromTo();
            morphAndUpdate(DrawTime,from,to);
        }
        else
        {
            from = getMin();
            to = getMax();
            if(_currentSample>_lastSample){
                _signal->rotateT(to-from);
            }else if(_lastSample>_currentSample){
                _signal->rotateT(from-to);
            }
            updateAllF();
        }

    } catch (...) {
    }
}



void DSPControl::valueIntegration(int pos )
{
    _lastSample = _currentSample;
    _currentSample = pos;
}


void DSPControl::valueDesintegration(){
    _lastSample = -1;
    _currentSample =-1;
}

int DSPControl::getMin()
{
    if (_currentSample>_lastSample)
    {
        if(_lastSample>=0){return _lastSample;}
        else if (_currentSample >= 0) return _currentSample;
        else return -1;
    }else{
        if (_currentSample >= 0) return _currentSample;
        else if (_lastSample >=0) return _lastSample;
        else return -1;
    }
}
int DSPControl::getMax(){
    if (_lastSample>_currentSample)
    {
        if(_lastSample>=0){return _lastSample;}
        else if (_currentSample >= 0) return _currentSample;
        else return -1;
    }else{
        if (_currentSample >= 0) return _currentSample;
        else if (_lastSample >= 0) return _lastSample;
        else return -1;
    }
}


void DSPControl::updateFromTo(){
    from = getMin();
    to = getMax();
    if(to==-1 && from ==-1)return ;

    else if (from == -1)
    {
        from = to;
    }
    else if (to == -1){
        to = from;
    }

    if(to<from || from<0){
        throw("bad input min<=max");
    }
}

