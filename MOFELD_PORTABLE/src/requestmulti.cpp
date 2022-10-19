#include "requestmulti.h"

RequestMulti::RequestMulti()
    :Blofable(9,1)
{
    setAdressContent();
    setDataContent();
    setChecksum();
}

std::vector<uchar> * RequestMulti::getMessage(int macid, int ad2){
    setWordValue(6,ad2);
    return Blofable::getMessage(macid);
}

void RequestMulti::setAdressContent(){
    appenWord (new WordConstante("unused",&_message[5],0));
    appenWord (new WordAny("Multi Number",&_message[6]));
}
void RequestMulti::setDataContent(){
    //null
}

void RequestMulti::setChecksum(){
    appenWord (new WordConstante("CHK",&_message[7],0x7f));
}

