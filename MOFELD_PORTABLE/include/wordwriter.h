#ifndef WORDWRITER_H
#define WORDWRITER_H

#include "BlofeldEnums.h"
#include "bytemanager.h"
#include "valuemgr.h"
#include <valuerange.h>

class WordWriter
{
protected:
    ValueMgr * _valueMgr;
    QVector<ByteManager> _byteMgrs;
public:
    WordWriter( ValueMgr * vm, uchar * octetRef, int bitness , int offset );
    WordWriter( ValueMgr * vm,  uchar * octetRef , int bitness );
    WordWriter( WordWriter * w, uchar * octetRef );

    const QString * getNom(){return _valueMgr->getName();}
    ValueMgr * getValueMgr()const{return  _valueMgr;}

    int getValue()const{return _valueMgr->getValue();}
    int getValue(int v)const{return _valueMgr->getValue(v);}
    void setValue(int v){ _valueMgr->setValue(v);}
    virtual void parseBytes() ;
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
    WordAny(QString s,  uchar * oct );
    WordAny(QString s,  uchar * oct, int v );
};

class WordBig
        :public WordWriter
{
public:
    WordBig(QString s,  uchar  *  oct , int bitness)
        :WordWriter(new ValueMgr(s,bitness),oct,7){}
    void setValue(int v);
};

class WordEnum
        :public WordWriter
{
public:
    WordEnum(QString s, uchar  * v ,int enid);
    WordEnum(QString s,  uchar  * v ,int enid, int bitness, int offset);
    WordEnum(ValueMgr * vm,  uchar  * v );

};

class WordConstante
        :public WordWriter
{
public:
    WordConstante(QString s,  uchar * oct ,int cst);
};

class WordRange
        :public WordWriter
{
public:
    WordRange(QString s,  uchar * oct ,int min, int max);
};



#endif // WORDWRITER_H
