#include "dumpwave.h"

DumpWave::DumpWave()
    : BufferSpec(21,128,7),Blofable(410,0x12)
{
    setAdressContent();
    setDataContent();
    setChecksum();
}
void DumpWave::setMessage(const SignalReal *sr)
{
    int cnt(8);
    int fval = (pow(2,20)-1);
    const QVector<double> sis = *sr->getSamples();
    foreach(double d ,sis)
    {
        float f = (float)d;
        if(f>1.0){ f = 1.0;}
        else if(f<-1.0){ f = -1.0;}
        setWordValue(cnt++,f*fval);
    }
}

void DumpWave::setAdressContent(){
    appenWord(new WordAny ("WT n°",&_message[5] ));
    appenWord(new WordAny ("Wave Number n°",&_message[6]));
}

void DumpWave::setDataContent(){
    int cnt = 7;
    appenWord(new WordAny("FORMAT",&_message[cnt++] ));

    for(int snum(0);snum<_length;snum++){
        WordWriter * w = new WordBig ("Sample n°%d",&_message[3*cnt++],21);
        appenWord(w);
    }
    int n = 392;
    //multi type avec des char?
    for(int cntName(0);cntName<14;cntName++)
    {
        QString s;
        s.sprintf("char n°%d",cntName);
        appenWord(new WordAny (s,&_message[cntName+n],33));
    }
}

void  DumpWave::setEmbeddedName(QString name){
    int offset=136;
    for(int i=0; i<14 && name.length()>i;i++)
    {
        char c ;
        if(i >= name.length()){
            c = (char)0x20;
        }
        else{
            c = name.at(i).toAscii();
        }
        const char res(c);
        setWordValue(i+offset,res);
    }
}


void DumpWave::setChecksum(){
    appenWord(new WordChecksum(&_message,408,7,407));
}


std::vector<uchar> * DumpWave::getMessage(int macid, int tableid, int waveid)
{
    replaceWord(5,new WordConstante("WT n°",&_message[5],tableid));
    replaceWord(6,new WordConstante ("Wave Number n°",&_message[6],waveid));
    return Blofable::getMessage(macid);
}

