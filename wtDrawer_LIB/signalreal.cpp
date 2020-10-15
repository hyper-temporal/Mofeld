#include "signalreal.h"


SignalReal::SignalReal()
    : DSPHelper(128)
{
    clearAnalysis();
    clearTimeDomain();
}

SignalReal::SignalReal(int sampleNum)
    : DSPHelper(sampleNum)
{
    clearAnalysis();
    clearTimeDomain();
}



SignalReal::SignalReal(QVector<double> v)
    :DSPHelper(v.size())
{
//    clearAnalysis();
//    clearTimeDomain();
//    _timeDomain = (v);
    setSamples(&v);
    dft();
}

SignalReal::SignalReal(QVector<double> mg,QVector<double> ph)
    :DSPHelper(mg.size()*2)
{

    if(     mg.size()!=ph.size()
        ||  mg.size()<= 0 )
    {
        throw("Les vecteurs sont mal initialisés");
    }
    setMagnitude(&mg);
    setPhase(&ph);
    idft();
}

SignalReal::SignalReal(const SignalReal &other)
    :DSPHelper(other),_timeDomain(other._timeDomain),_magnitude(other._magnitude),_phase(other._phase)
{
}



void SignalReal::fillSignal(QVector<double> sig, int freq)
{
    _timeDomain.resize(sig.size());
    DSPHelper::fillSignal(sig,&_timeDomain,freq);
}


void SignalReal::clearTimeDomain(){
    _timeDomain.resize(_size);
    _timeDomain.fill(0.0);
}


void SignalReal::clearAnalysis(){
    _magnitude.resize(1+_size/2);
    _phase.resize(1+_size/2);
    _magnitude.fill(0.0);
    _phase.fill(0.0);
}

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

void SignalReal::dft()
{
    clearAnalysis();


    int tSize= _timeDomain.size();
    int fSize= _timeDomain.size()/2;

    int cnt_k,cnt_n;
    for(cnt_k=0;cnt_k<=fSize;cnt_k++)
    {
        for(cnt_n=0;cnt_n<tSize;cnt_n++)
        {
            double v= 2*M_PI*cnt_k*cnt_n/tSize;
            _magnitude[cnt_k]= _magnitude[cnt_k] +_timeDomain[cnt_n] * cos_x(v);
            _phase[cnt_k]= _phase[cnt_k] - _timeDomain[cnt_n]*sin_x(v);
        }
        _magnitude[cnt_k]= 2*_magnitude[cnt_k]/(tSize) ;  //Partie reelle
        _phase[cnt_k]= -2*_phase[cnt_k]/(tSize) ; //Partie imaginaire
        Rect2PolInPlace(&_magnitude[cnt_k],&_phase[cnt_k] );
        NormalisePolar(&_magnitude[cnt_k],&_phase[cnt_k] );
    }
}

void SignalReal::idft()
{
    clearTimeDomain();

    int tSize= _timeDomain.size();
    int fSize= _timeDomain.size()/2;

    int cnt_k;
    int cnt_n;

    QVector<double> cmg ;
    QVector<double> cph ;


    for(int i(0);i< fSize+1;i++){
        cmg.append(_magnitude[i]);
        cph.append(_phase[i]);
    }
    cmg[0]/= 2;
    cmg[fSize]/= 2;

    for(cnt_k=0;cnt_k<= fSize;cnt_k++)
    {
        Pol2RectInPlace(&cmg[cnt_k],&cph[cnt_k] );
    }


    for(cnt_n=0; cnt_n< tSize;cnt_n++)
    {
        for(cnt_k=0;cnt_k<= fSize ;cnt_k++)
        {
            _timeDomain[cnt_n]+= cmg[cnt_k]*cos_x( 2*M_PI*cnt_k*cnt_n/tSize);
            _timeDomain[cnt_n]+= cph[cnt_k]*sin_x(2*M_PI*cnt_k*cnt_n/tSize);
        }
    }
}

void SignalReal::Pol2RectInPlace(double* Magn2Real, double* Phase2Imag)//reference...
{
    double   CosPhase= cos_x(*Phase2Imag);
    double   SinPhase= sin_x(*Phase2Imag);
    *Phase2Imag=SinPhase*(*Magn2Real);
    *Magn2Real=CosPhase*(*Magn2Real);
}

double SignalReal::polarMagnitude(double  real, double  imag )
{
    double mag;
    mag = sqrt(pow(real,2)+ pow(imag,2));
    return mag;
}

double SignalReal::polarPhase(double  real, double  imag)
{
    #define COSERROR    0.001
    double phase;

    if (real == 0.0)
    {
        if (imag > 0.0)
        {phase = M_PI_2;}
        else
        {phase = -M_PI_2;}
    }
    else
    {phase = atanf(imag / real);}
/*
** settle sign ambiguity on phase. If real and imaginary are  both
** negative the returned arctan needs 180 subtracted. If the real
** is negative and imaginary is positive, add 180.
*/
    if ((real < 0) && (imag < 0) ) {
            phase = phase - M_PI;
    }
    if ((real < 0.0) && (imag >= 0.0)) {
            phase = phase + M_PI;
    }

    if( phase > M_PI-COSERROR)
    {
        phase = phase - 2*M_PI;
    }
    return phase;
}

void SignalReal::Rect2PolInPlace(double* Real2Magn, double* Imag2Phase)
{
    double   Realcpy= *Real2Magn;
    double   Imagcpy= *Imag2Phase;
    *Real2Magn=polarMagnitude( Realcpy, Imagcpy );
//    if(*Real2Magn<0.00001)
//    {*Imag2Phase=0;}
//    else
//    {
        *Imag2Phase=polarPhase( Realcpy, Imagcpy );
//    }

}

void SignalReal::NormalisePolar(double* Magn, double* Phase)
{
    //*Magn= *Magn*2 -1;
//
#define CONSIDER0 0.001

//    *Phase=  *Phase/(M_PI) ; //pour ramener entre -1 1
//    if(*Phase>1){*Phase=1;}
//    if(*Phase<-1){*Phase=-1;}
//    if(*Magn>1){*Magn=1;}
//    if(*Magn<-1){*Magn=-1;}
    while( *Phase < 0){
        *Phase+=(2*M_PI) ; //pour ramener entre -1 1
    }
    while( *Phase > (2*M_PI)){
        *Phase-=(2*M_PI) ; //pour ramener entre -1 1
    }
    if(*Magn<CONSIDER0)
    {
        *Magn = 0.0;
    }
//    if(Phase<CONSIDER0){
//        *Phase= 0.5;
//    }

}


void SignalReal::iir_narrowband(int periode, int bandwidth, int filterType)
{
    ushort cnt_n=0;
    double speedupcst=cos_x(2*M_PI*periode/_size );

    QVector<double> copy_input;
    QVector<double> temp_output;


    copy_input << _timeDomain + _timeDomain;
    temp_output << _timeDomain +_timeDomain;

    double coeffa0=0;
    double coeffa1=0;
    double coeffa2=0;
    double coeffb1=0;
    double coeffb2=0;

    double R = 1 - 3*bandwidth/(_size*64 );
    double cnt_K = (1- 2*R*speedupcst+ R*R)/(2 - 2*speedupcst);

    if (filterType== 0)
    {
        coeffa0= 1-cnt_K;
        coeffa1= 2*(cnt_K-R)*speedupcst;
        coeffa2= R*R-cnt_K;
        coeffb1= 2*R*speedupcst;
        coeffb2= -R*R;
    }
    else
    {
        coeffa0= cnt_K;
        coeffa1= -2*cnt_K*speedupcst;
        coeffa2= cnt_K;
        coeffb1= 2*R*speedupcst;
        coeffb2= -R*R;
    }

    for (cnt_n=2; cnt_n < _size*2; cnt_n++)
    {
        temp_output[cnt_n]=     coeffa0*copy_input[cnt_n]
                            +   coeffa1*copy_input[cnt_n-1]
                            +   coeffa2*copy_input[cnt_n-2]
                            +   coeffb1*temp_output[cnt_n-1]
                            +   coeffb2*temp_output[cnt_n-2];
    }

    for (cnt_n=0; cnt_n < _size; cnt_n++)
    {
        _timeDomain[cnt_n]=temp_output[cnt_n+_size];
    }
}
double castPhaseMag(double sv){
    if(sv>1.0){
         return 1.0;
    }else if(sv<0){
        return 0.0;
    }else{
        return sv;
    }
}

double castSample(double sv){
    if(sv>1.0){
         return 1.0;
    }else if(sv<-1.0){
        return -1.0;
    }else{
        return sv;
    }
}
void SignalReal::normalisePeaks()
{

    for(int i(0);i<_timeDomain.size();i++)
    {
        if(_timeDomain[i]>1){
            _timeDomain[i]=1.0;
        }else if(_timeDomain[i]<-1.0){
            _timeDomain[i]=-1.0;
        }
    }

}


void SignalReal::normalise()
{
    double dm(0.0),d0 = 0.0;
    for(int i(0);i<_timeDomain.size();i++)
    {
        d0=_timeDomain[i];
        if(d0<0){d0=-d0;}
        if(d0>dm){dm=d0;}
    }
    if(dm>0.0)
    {
       double fact = 1.0/dm;
       for(int pos(0);pos<_timeDomain.size();pos++)
       {
           _timeDomain[pos]*=fact;
       }
    }

}

void SignalReal::setMagnitude(const QVector<double> *vs)
{
    if(vs->size()<0 || vs->size() >_magnitude.size())return;
    int cnt=0;
    foreach(double d,*vs){
        setMagnitude(cnt++,d);
    }
}
void SignalReal::setPhase(const QVector<double> *vs)
{
    if(vs->size()<0 || vs->size() >_phase.size())return;
    int cnt=0;
    foreach(double d,*vs){
        setPhase(cnt++,d);
    }
}
void SignalReal::setSamples(const QVector<double> *vs)
{
    if(vs->size()<0 || vs->size() >_timeDomain.size())return;
    int cnt=0;
    foreach(double d,*vs){
        setSample(cnt++,d);
    }
}
void SignalReal::setMagnitude(int pos,double v)
{
    if(pos<0 || pos >_magnitude.size())return;
    _magnitude[pos]=(v);
}
void SignalReal::setPhase(int pos,double v)
{
    if(pos<0 || pos >_phase.size())return;
    _phase[pos]=(v);
}
void SignalReal::setSample(int pos, double sv)
{
    if(pos<0 || pos >_timeDomain.size())return;
    else
        _timeDomain[pos] =(sv);
}

void SignalReal::linearMorphing(QVector<double> *_toMorpg, int from, int to)
{

    if(_toMorpg->size()<to)return;
    try {

        double step = (_toMorpg->at(to) - _toMorpg->at(from))/(to-from+1);
        double value = _toMorpg->at(from);

        for(int i=from; i<=to; i++)
        {
            double *pf= &(*_toMorpg)[i];
            *pf =value;
            value += step;
        }
    } catch (...) {

    }
}

void SignalReal::rotateMG(int samples){
    rotate(editMagnitude(),samples);
}

void SignalReal::rotatePH(int samples){
    rotate(editPhase(),samples);
}
void SignalReal::rotateT(int samples)
{
    rotate(editSamples(),samples);
}


void SignalReal::rotate(QVector<double> *values,int samples)
{
    int sam = samples%values->count();
    if(sam>0){
        for(int i(0);i<sam;i++)
        {
            double d = values->last();
            values->push_front(d);
            values->pop_back();
        }
    }else{
        for(int i(0);i<-sam;i++){
            double d = values->first();
            values->push_back(d);
            values->pop_front();
        }
    }
}



void SignalReal::addSignal(QVector<double>  v )
{
    int cnt =0;
    foreach(double d , *getSamples()){
        d+=_timeDomain.at(cnt);
        setSample(cnt++,d);
    }
}

void SignalReal::multiplySignal(QVector<double>  v )
{
    int cnt =0;
    foreach(double d , *getSamples()){
        d*=_timeDomain.at(cnt);
        setSample(cnt++,d);
    }
}

void SignalReal::setGain(double v )
{
    int cnt(0);
    foreach(double d , *getSamples()){
        d*=v;
        setSample(cnt++,d);
    }
}




