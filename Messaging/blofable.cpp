#include "Messaging/blofable.h"


Blofable::Blofable(const int s,const int t):Sysexable(s){
    setManufacturer();
    setDeviceModel();
    setDevice();
    setType(t);
}

    //gerer par marque...
void Blofable::setManufacturer(){
    appenWord(new WordConstante("MID",&_message[1],0x3E));
}

//gerer par model...
void Blofable::setDeviceModel(){
    appenWord(new WordConstante("IDE",&_message[2],0x13));
}
//gerer par device... cette methode doit intitialiser la fonction d'obtention d'un pointeur sur un device
//le device sera accessible en lecture et ecriture a l'adresse ou est implementer ce mot
void Blofable::setDevice(){
    appenWord(new WordAny("DEV",&_message[3],0));
}
void Blofable::setType(const int t){
    appenWord(new WordConstante("IDM",&_message[4],t));
}


std::vector<uchar> * Blofable::getMessage(int macid){
    setDevice(macid);
    return writeMessage();
}
void Blofable::setDevice(const int d){
    setWordValue(3,d);
}

int Blofable::getDevice(){
    return getWordValue(3);
}









