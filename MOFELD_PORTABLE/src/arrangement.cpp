#include "arrangement.h"

Arrangement::Arrangement()
{
    init();
}

//constructeur appelé par la classe de serialisation lors de l'import
Arrangement::Arrangement(const Arrangement *other, int id , QString nom)
    :Entity(id,nom)
{
    init();
    for(int i(0);i<16;i++)
    {
        Instrument ni(other->_BlofChannel[i].getInstrument(),
                      other->getID(),
                      other->getName());
        _BlofChannel[i].setInstrument(ni);
        _BlofChannel[i].setMixPars(other->getMixPars(i));
        _BlofChannel[i].setMultiPars(other->getMultiPars(i));
    }
}


void Arrangement::init(){

    for(int i(0);i<16;i++){
        _BlofChannel.append( BlofChannel(i));
    }
}



void Arrangement::setArrangement(const Arrangement *a){
    int i(0);
    foreach(BlofChannel bc,a->_BlofChannel)
    {
        setInstrument(*bc.editInstrument(),i++);
    }
}

void Arrangement::setInstrument(const Instrument i, int ch)
{
    if(ch<_BlofChannel.count() && ch>=0){
        _BlofChannel[ch].setInstrument(i);
    }
}
void Arrangement::Regenerate(int ch){
    _BlofChannel[ch].Regenerate();
}

QDataStream & operator << (QDataStream & out, const Arrangement & Valeur)
{
    out << Valeur._id
        << Valeur._name
        << Valeur._datecreation
        << Valeur._BlofChannel
           ;
    return out;
}

QDataStream & operator >> (QDataStream & in, Arrangement & Valeur)
{

    in  >> Valeur._id
        >> Valeur._name
        >> Valeur._datecreation
        >> Valeur._BlofChannel
           ;
    return in;
}
