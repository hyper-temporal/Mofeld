#include "requestinstrument.h"

RequestInstrument::RequestInstrument()
    :Blofable(9,0x00)
{
    setAdressContent();
    setDataContent();
}

void RequestInstrument::setAdressContent(){
    appenWord (new WordAny("LL",&_message[5]));
    appenWord (new WordAny("HH",&_message[6]));
    appenWord (new WordAny("PP",&_message[7]));
}

void RequestInstrument::setDataContent(){
    appenWord (new WordAny("XX",&_message[8]));
}

std::vector<uchar> * RequestInstrument::getMessage(int macid,int chid){
    setWordValue(5,0x7f);
    setWordValue(6,chid);
    return Blofable::getMessage(macid);
}

std::vector<uchar> * RequestInstrument::getMessage(int macid,int bankid, int pgmid){
    setDevice(macid);
    replaceWord(5,new WordConstante ("BB",&_message[5],bankid));
    replaceWord(6,new WordConstante ("NN",&_message[6],pgmid));
    return writeMessage();
}


std::vector<uchar>  * RequestInstrument::getAllSounds(int macid){
    replaceWord(5,new WordConstante ("BB",&_message[5],0x40));
    replaceWord(6,new WordConstante ("NN",&_message[6],0));
    return Blofable::getMessage(macid);
}
