#ifndef WORDPARAM_H
#define WORDPARAM_H

#include "blofable.h"


/*

 classe qui est a la fois un mot et un message: participe a la construction d'un message
 elle a egalement la responsabilite d'un mot particulier dans une instance de message: le word writer qu'elle contient est celui utilise lors de l'envoi
*/
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
