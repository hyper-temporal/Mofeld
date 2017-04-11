#ifndef WORDPARAM_H
#define WORDPARAM_H

#include "blofable.h"


class ParametreCom
        :public Blofable
{
    const int _idt;
    const int _ad1,_ad2;
    WordWriter * _word;

 public :
    ParametreCom( int ad1,int ad2);
    ParametreCom(int id,int ad1,int ad2, WordWriter * w );

    bool adressMatch(int ad1,int ad2);
    int getValue();
    int getChannel();
    int getId()const{return _idt;}

    const QString * getNom(){return _word->getNom(); }
    ValueEnum * getValueMgr()const{
        return  dynamic_cast<ValueEnum*>(_word->getValueMgr());
    }

    void setParamValue(int v);
    void setParamChannel(int ch);

    std::vector<uchar> * getMessage(int mid);
    std::vector<uchar> * getMessage(int macid,int chid);
    std::vector<uchar> * getMessage(int macid,int chid, int v);

    void updateInstrument( int v);
private:

    void setDataContent();
    void setAdressContent();
    void setChecksum(){}

    friend class GuiBlofActionSpecifier;
    friend class GuiCtrlMgr;
    friend class DumpInstrument;

};


#endif // WORDPARAM_H
