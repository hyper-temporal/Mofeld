#include "sysexable.h"

Sysexable::Sysexable(const int size)
    :MessageWriter(size)
{
    appenWord(new WordConstante("EXC",&_message[0],0xF0));
}

std::vector<uchar> * Sysexable::writeMessage(){
     sysexEndCheck();
     foreach(WordWriter * ww,_mots){
         ww->writeBytes();
     }
     return &_message;
 }


void Sysexable::parseMessage(std::vector<uchar> * vc){

    if(vc->size()!=_message.size()) throw ("la taille du message ne correspond pas");

    int i(0);
    foreach(uchar c, *vc){
        _message.at(i)=c;
        i++;
    }
    foreach(WordWriter * w,_mots){
        w->parseBytes();
    }
 }


void Sysexable::sysexEndCheck(){
    if(_mots.last()->getValue()!=0xF7){
         appenWord(new WordConstante ("EOX",&_message[_message.size()-1],0xF7));
    }
}
