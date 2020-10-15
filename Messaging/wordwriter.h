#ifndef WORDWRITER_H
#define WORDWRITER_H

#include "genericity/BlofeldEnums.h"
#include "bytemanager.h"
#include "genericity/valuemgr.h"
#include "genericity/valuerange.h"

//Ecrit et de lit un entier a partir d'une serie d'octets
//un mot partagé et un mot simple ne possedera qu'un ByteManager
// un mot dont bitness > 8 instanciera plusieurs ByteMgr

//lors de la construction d'un synthObject le mot fournit un parametre qui permet de recuperer le type du mot, d'en lire et modifier la valeur

//est instancié par un messagewriter qui instancie egalement le vecteur dans lequel l'ecriture a lieu
class WordWriter
{
protected:
    ValueMgr * _valueMgr;
    QVector<ByteManager> _byteMgrs;
public:
    WordWriter( ValueMgr * vm, uchar * octetRef, int bitness , int offset );
    // WordMany and Single
    WordWriter( ValueMgr * vm,  uchar * octetRef , int bitness );
    // WordShared
    //copy exept ref
    WordWriter( WordWriter * w, uchar * octetRef );

    const QString * getNom(){return _valueMgr->getName();}
    ValueMgr * getValueMgr()const{return  _valueMgr;}

    int getValue()const{return _valueMgr->getValue();}
    int getValue(int v)const{return _valueMgr->getValue(v);}
    void setValue(int v){ _valueMgr->setValue(v);}

    //met a jour sa valeur selon les octets du message, eux memes pointés par les bytesmgr
    virtual void parseBytes() ;
    //met a jour le message suivant sa valeur
    virtual void writeBytes() ;

private:

    friend class MessageWriter;
    friend class Param;
    friend class ParametreBO;
    friend class DumpInstrument;
};


class WordAny
        :public WordWriter
{
public:
    //any
    WordAny(QString s,  uchar * oct );
    WordAny(QString s,  uchar * oct, int v );
};

class WordBig
        :public WordWriter
{
public:
    //Enum b, o
    WordBig(QString s,  uchar  *  oct , int bitness)
        :WordWriter(new ValueMgr(s,bitness),oct,7){}
    void setValue(int v);
};

class WordEnum
        :public WordWriter
{
public:
    //ENUM 7b
    WordEnum(QString s, uchar  * v ,int enid);
    //Enum b, o
    WordEnum(QString s,  uchar  * v ,int enid, int bitness, int offset);
    WordEnum(ValueMgr * vm,  uchar  * v );

};

class WordConstante
        :public WordWriter
{
public:
    //constante
    WordConstante(QString s,  uchar * oct ,int cst);
};

class WordRange
        :public WordWriter
{
public:
    //constante
    WordRange(QString s,  uchar * oct ,int min, int max);
};



#endif // WORDWRITER_H
