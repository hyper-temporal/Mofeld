#include "requestwave.h"

//dumptype 3 MSB
//messagetype 4 LSB

RequestWave::RequestWave(uchar idm):
    Blofable(9, idm )
//  Blofable(9, idm & 0b1111)
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
    //null
}

void RequestWave::setChecksum(){
    appenWord (new WordChecksum( &_message,_message.size()-2,5,6));
}
