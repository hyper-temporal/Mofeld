#include "parametrecom.h"

ParametreCom::ParametreCom( int ad1,int ad2  ):
    Blofable(10,0x20), _idt(0),_ad1(ad1),_ad2(ad2)
{
    setAdressContent();
    appenWord(new WordConstante ("HH",&_message[6],_ad1));
    appenWord(new WordConstante ("PP",&_message[7],_ad2));
}


ParametreCom::ParametreCom(int id,int ad1,int ad2,  WordWriter * w ):
    Blofable(10,0x20), _idt(id),_ad1(ad1),_ad2(ad2),_word(w)
{
    setAdressContent();
    setDataContent();
}



void ParametreCom::setParamValue(int v){
    try {
        _word->setValue(v);
    } catch (...) {
    }
}

void ParametreCom::setParamChannel(int ch){
    try {
        WordWriter * w = getWord(5);
        w->setValue(ch);
    } catch (...) {

    }
}

int ParametreCom::getChannel(){
    return ( getWordValue(5));
}

int ParametreCom::getValue(){
    return ( getWordValue(8));
}

bool ParametreCom::adressMatch(int ad1,int ad2){
    return (    getWordValue(6) ==ad1
            &&  getWordValue(7) ==ad2);
}

std::vector<uchar> * ParametreCom::getMessage(int macid){
    return Blofable::getMessage(macid);
}

std::vector<uchar> * ParametreCom::getMessage(int macid,int chid){
    setParamChannel(chid);
    return getMessage(macid);
}
std::vector<uchar> * ParametreCom::getMessage(int macid,int chid, int v){
    setParamValue(v);
    return getMessage(macid,chid);
}


void ParametreCom::setDataContent(){
    appenWord(new WordConstante ("HH",&_message[6],_ad1));
    appenWord(new WordConstante ("PP",&_message[7],_ad2));
    appenWord(new WordWriter (_word ,&_message[8]));
}



void ParametreCom::setAdressContent(){
   appenWord(new WordRange ("LL",&_message[5],0,15));
}
