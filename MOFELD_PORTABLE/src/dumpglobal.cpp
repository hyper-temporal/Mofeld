#include "dumpglobal.h"
#include <QDebug>

DumpGlobal::DumpGlobal()
    :Blofable(80,0x14)
{
    setAdressContent();
    setDataContent();
    setChecksum();
}

void DumpGlobal::setChecksum()
{
    appenWord(new WordChecksum (&_message ,78,5,77));
}
void DumpGlobal::setAdressContent(){
//    appenWord( new WordAny ( "BB",&_message[5],0));
//    appenWord( new WordAny  ( "NN",&_message[6],0));
}


void DumpGlobal::addParametre(WordEnum * w)
{
    appenWord(w);

    _Parametres.append(
                new Parametre(
                    w->getValueMgr(),
                    _Parametres.count()));

}

void DumpGlobal::setDataContent()
{
/*00*/    addParametre(new WordEnum("MULTI SWITCH"   ,&_message[6], BLOT_SWITCH));
    for(int i(0);i<16;i++)
    {
        int offset = 2 * i;
        addParametre(new WordEnum("BANK"   ,&_message[7+offset], BLOT_BANK));
        addParametre(new WordEnum("PRGM"   ,&_message[8+offset], BLOT_STANDARD));
    }
///*33*/    addParametre(new WordEnum("MULTI NUM"   ,&_message[39], BLOT_STANDARD));
/*34*/    addParametre(new WordEnum("Auto Edit"   ,&_message[40], BLOT_SWITCH));
/*35*/    addParametre(new WordEnum("Midi Channel"   ,&_message[41], BLOT_CHANNEL));
/*36*/    addParametre(new WordEnum("Device ID"   ,&_message[42], BLOT_STANDARD));


    addParametre(new WordEnum("Popup Time  "   ,&_message[43], BLOT_STANDARD));
    addParametre(new WordEnum("Contrast    "   ,&_message[44], BLOT_STANDARD));
    addParametre(new WordEnum("Master Tune "   ,&_message[45], BLOT_OSC_SEMITONE));
    addParametre(new WordEnum("Transpose   "   ,&_message[46], BLOT_GLOB_TRANSPOSE));
    addParametre(new WordEnum("Ctrl Send   "   ,&_message[49], BLOT_GLOB_SEND_CTRL));
    addParametre(new WordEnum("Ctrl Receive"   ,&_message[50], BLOT_SWITCH));
//    addParametre(new WordEnum("Prog Send  "    ,&_message[51], BLOT_SWITCH));
    addParametre(new WordEnum("Clock       "   ,&_message[53], BLOT_SWITCH));
    addParametre(new WordEnum("Vel Curve   "   ,&_message[55], BLOT_GLOB_CURVE));
    addParametre(new WordEnum("Control W   "   ,&_message[56], BLOT_GLOB_CTRL));
    addParametre(new WordEnum("Control X   "   ,&_message[57], BLOT_GLOB_CTRL));
    addParametre(new WordEnum("Control Y   "   ,&_message[58], BLOT_GLOB_CTRL));
    addParametre(new WordEnum("Control Z   "   ,&_message[59], BLOT_GLOB_CTRL));
    addParametre(new WordEnum("Volume      "   ,&_message[60], BLOT_STANDARD));
    addParametre(new WordEnum("Cat. Filter "   ,&_message[61], BLOT_CATEGORIES));
//    addParametre(new WordEnum("Local Ctrl  "   ,&_message[62], BLOT_SWITCH));
//    addParametre(new WordEnum("Free Button "   ,&_message[64], BLOT_GLOB_FREEBUTTON));
//    addParametre(new WordEnum("Pedal       "   ,&_message[65], BLOT_SWITCH));
}

void DumpGlobal::debug(){
    int cnt = 0;
    for(auto p : _Parametres){
        qDebug() << cnt++  << "___"  << *(p->getType()->getName()) << "___" << p->getValue();
    }
}
