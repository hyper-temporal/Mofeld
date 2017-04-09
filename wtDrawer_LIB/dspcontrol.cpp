#include "dspcontrol.h"

DSPControl::DSPControl(QWidget *parent, SignalReal *sig)
    : QWidget(parent)
{
    _signal = sig;

    _lastSample = -1;
    _currentSample = -1;

    _mode = SignalReal::DrawMagnitude;
    _frequencyDomain = new MDrawerFrequency(_signal,this);
    _timeDomain  = new MDrawerTime(_signal,this);


    connect( _frequencyDomain, SIGNAL(sendValue(int,double)),
             this, SLOT(sentFromDomainF(int,double)));
    connect( _timeDomain, SIGNAL(sendValue(int,double)),
             this, SLOT(sentFromDomainT(int,double)));

    connect( _timeDomain, SIGNAL(startFollow(int,double)),
             this, SLOT(startDomainT(int,double)));
    connect( _frequencyDomain, SIGNAL(startFollow(int,double)),
             this, SLOT(startDomainF(int,double)));


    connect( _timeDomain, SIGNAL(stopFollow(int,double)),
             this, SLOT(stopFollowT(int,double)));
    connect( _frequencyDomain, SIGNAL(stopFollow(int,double)),
             this, SLOT(stopFollowF(int,double)));

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


void DSPControl::valueIntegration(int pos )
{
    _lastSample = _currentSample;
    _currentSample = pos;
}

void DSPControl::setSample(int pos,double v){
    _signal->setSample(pos,v);
    _signal->dft();
//    _timeDomain->UpdateOne(pos);
//    _frequencyDomain->UpdateAll();
    emit everythingHasChanged();

}

void DSPControl::setPhase(int pos,double v)
{
    _signal->setPhase(pos,v * M_PI);
    _signal->idft();
    _signal->normalisePeaks();
    _signal->dft();
//    _frequencyDomain->UpdateOne(pos);
//    _timeDomain->UpdateAll();
    emit everythingHasChanged();

}
void DSPControl::setMagnitude(int pos,double v)
{
    _signal->setMagnitude(pos,v);
    _signal->idft();
    _signal->normalisePeaks();
    _signal->dft();
//    _frequencyDomain->UpdateOne(pos);
//    _timeDomain->UpdateAll();
    emit everythingHasChanged();

}

void DSPControl::morphAndUpdate(int type)
{
    int from,to;
    from = getMin();
    to = getMax();

    if(to==-1 && from ==-1)return;
    else if (from == -1)
    {
        from = to;
    }
    else if (to == -1){
        to = from;
    }

    _signal->linearMorphing(type,from,to);

    switch(type){
    case SignalReal::DrawTime:
//        for(int i=from;i<to;i++)
//        {
//            _timeDomain->UpdateOne(i);
//        }
        _signal->dft();
//        _frequencyDomain->UpdateAll();
        break;
    default:
//        for(int i=from;i<to;i++)
//        {
//            _frequencyDomain->UpdateOne(i);
//        }
        _signal->idft();
//        _timeDomain->UpdateAll();
        break;
    }
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


void DSPControl::drawSine(int f)
{
   _signal->fillSignal(_signal->getSinus(),f);
    updateAllT();
}
void DSPControl::drawSquare(int ratio,int f)
{
   _signal->fillSignal(_signal->getSquare(ratio),f);
    updateAllT();
}
void DSPControl::drawTriangle(int f)
{
   _signal->fillSignal(_signal->getTriangle(),f);
    updateAllT();
}
void DSPControl::drawRamp(int f)
{
   _signal->fillSignal(_signal->getRamp(),f);
    updateAllT();
}
void DSPControl::drawRandom(int f)
{
   _signal->fillSignal(_signal->getRandom(),f);
    updateAllT();
}

void DSPControl::valueDesintegration(){
    _lastSample = -1;
    _currentSample =-1;
}


void DSPControl::updateAllT()
{
//    _timeDomain->UpdateAll();
    _signal->dft();
//    _frequencyDomain->UpdateAll();
    emit everythingHasChanged();

}
void DSPControl::updateAllF()
{
//    _frequencyDomain->UpdateAll();
    _signal->idft();
//    _timeDomain->UpdateAll();
    emit everythingHasChanged();
}


void DSPControl::stopFollowT(int pos, double v )
{
    valueDesintegration();

}

void DSPControl::stopFollowF(int pos, double v )
{
    valueDesintegration();

    _signal->dft();
    _frequencyDomain->UpdateAll();

}

void DSPControl::startDomainF(int pos, double v)
{
    valueIntegration(pos);
    if(_mode==SignalReal::DrawMagnitude){
        setMagnitude(pos,v);

    }else if(_mode==SignalReal::DrawPhase){
        setPhase(pos,v);
    }

}
void DSPControl::startDomainT(int pos, double v)
{
    valueIntegration(pos);
    setSample(pos,v);

}

void DSPControl::sentFromDomainF(int pos, double v)
{
    valueIntegration(pos);
    try {
        if(_mode==SignalReal::DrawMagnitude){
            setMagnitude(pos,v);

        }else if(_mode==SignalReal::DrawPhase){
            setPhase(pos,v);
        }
        morphAndUpdate(_mode);


    } catch (...) {

    }
}

void DSPControl::sentFromDomainT(int pos, double v){
    valueIntegration(pos);
    try {
        setSample(pos,v);
        morphAndUpdate(SignalReal::DrawTime);

    } catch (...) {

    }
}
