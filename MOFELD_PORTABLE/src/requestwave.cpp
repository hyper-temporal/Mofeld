#include "requestwave.h"

RequestWave::RequestWave(uchar idm):
    Blofable(9, idm )
{
    setAdressContent();
    setChecksum();
}

std::vector<uchar> * RequestWave::getMessage(int macid,int shelve , int draw){
    setWordValue(5,shelve);
    setWordValue(6,draw);
    return Blofable::getMessage(macid);
}


void RequestWave::setAdressContent(){
    appenWord (new WordAny("Table n°",&_message[5]));
    appenWord (new WordAny("Wave n°",&_message[6]));
}
void RequestWave::setDataContent(){
}

void RequestWave::setChecksum(){
    appenWord (new WordChecksum( &_message,_message.size()-2,5,6));
}
