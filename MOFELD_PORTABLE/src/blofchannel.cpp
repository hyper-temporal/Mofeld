#include "blofchannel.h"


#define NB_MULTISLICE_PARAMETRE 21

BlofChannel::BlofChannel()
    : _channelNum(-1)
{
}


BlofChannel::BlofChannel(const BlofChannel * other)
    :_channelNum(other->_channelNum),
      _instrument(other->_instrument),
      _mixPars(other->_mixPars),
      _multiPars(other->_multiPars)
{
}

BlofChannel::BlofChannel(const int ch)
    : _channelNum(ch)
{
}

void BlofChannel::MixParametre(const Parametre * par)
{
    _instrument.updateParametre(par,&_mixPars );
}

void BlofChannel::setInstrument(const Instrument i)
{
    _instrument.SetInstrument(i);
}

Instrument * BlofChannel::editInstrument(){
    return &_instrument;
}
void BlofChannel::setParamContrainte(int pid,const Contrainte * c){
    _instrument.setParamContrainte(pid,c);
}
void BlofChannel::setParamValue(int pid,int v){

    _instrument.setParamValue(pid,v);
}




const Propriete * BlofChannel::getProprieteChannel()const{
    return _instrument.getPropriete();
}


void BlofChannel::setPropriete(int id, bool state){
    _instrument.setPropriete(id,state);
}
void  BlofChannel:: setMultiPars(const QVector<Parametre> *pars)
{
    if(pars->count() != 21)  return;

    //
    if(_multiPars.count() != 21)
    {
        for(int i(0);i<pars->count();i++)
        {
            _multiPars.append( pars->at(i));
        }
    }
    else{
        for(int i(0);i<pars->count();i++)
        {
            setParametreValue(i, pars->at(i).getValue());
        }
    }
}

QDataStream & operator << (QDataStream & out, const BlofChannel & Valeur)
{
    out << Valeur._instrument
        << Valeur._mixPars
        << Valeur._multiPars
           ;

    return out;
}

QDataStream & operator >> (QDataStream & in, BlofChannel & Valeur)
{
    in  >> Valeur._instrument
        >> Valeur._mixPars
        >> Valeur._multiPars
           ;

    return in;
}
