#ifndef VALUEMGR_H
#define VALUEMGR_H


#include "genericity/BlofeldEnums.h"


class ValueMgrInstancesMgr
{
    int intanceCounter;

public:

    static ValueMgrInstancesMgr& getInstance()
    {
        static ValueMgrInstancesMgr    instance; // Guaranteed to be destroyed.
                           // Instantiated on first use.
        return instance;
    }
    int getId(){return intanceCounter++;}

private:
    ValueMgrInstancesMgr():intanceCounter(0){}
    ValueMgrInstancesMgr(ValueMgrInstancesMgr const&);// Don't Implement
    void operator=(ValueMgrInstancesMgr const&);

};


class ValueMgr
{

protected:
    int instanceNum;
    const QString _nom;
    const int _bitness;
    int _value;
    const int _mask;
public:

    //constructeur initial WWr
    ValueMgr(QString s,int b=7, int v=0)
        :_nom(s),
          _bitness(b),
          _value(v),
          _mask(createMask(b)) { instanceNum = ValueMgrInstancesMgr::getInstance().getId(); }

    ValueMgr( const ValueMgr  &other)
        :_nom(other._nom),
          _bitness(other._bitness),
          _value(other._value),
          _mask(createMask(_bitness)){instanceNum = ValueMgrInstancesMgr::getInstance().getId();}

    virtual void setValue(int v)  ;
    virtual int getValue()const ;
    virtual int getValue(int v)const  ;
    virtual int getValueOfElement(int p)const{return _value;}
    virtual const QString getNameOfElement(int v)const{return QString::number(v);}

    virtual int getNewValue(int v)const;
    virtual int getNewValue(int v,int min, int max)const;

    const QString * getName()const{return &_nom;}
    int getBitness()const{return _bitness; }
private:
    int createMask(int bitness);
};


class ValueConstante
        :public ValueMgr
{
public:
    ValueConstante(QString s,int v  )
        :ValueMgr(s,8,v){}
    ValueConstante( const ValueConstante  &other)
        :ValueMgr(other){}

    void setValue(int v){}
    int getValue()const{return _value;}
    int getValue(const int v)const{return _value;}
    int getNewValue(int v)const{return _value;}
    int getNewValue(int v,int min, int max)const{return _value;}
};


class ValueEnum
        :public ValueMgr
{
    const SynthEnum  * _enum;
public:
    ValueEnum()
        :   ValueMgr("-_-",7,0),
            _enum(BlofeldTypesEnum::getInstance().GetEnum(0)){}

    ValueEnum(QString s,const int enid , int bitness = 7, int value =0)
        :   ValueMgr(s,bitness,value),
            _enum(BlofeldTypesEnum::getInstance().GetEnum(enid)){}

    ValueEnum( const ValueEnum  &other)
        :ValueMgr(other),_enum(other._enum){}
    void setValue(int v){ValueMgr::setValue(_enum->getClosestValue(v));}
    int getValue()const{return ValueMgr::getValue();}
    int getValue(int v)const{return _enum->getClosestValue(v);}
    int getNewValue(int v)const{return _enum->getNewValue(v);}
    int getNewValue(int v,int min, int max)const{return _enum->getNewValue(v,min,max);}

    int getValueOfElement(int p)const{return _enum->getElement(p)->Lentier;}
//    QString getNameOfElement(int p)const{return _enum->getElement(p)->LaChaine;}
    const QString getNameOfElement(int v)const
    {
        foreach(SynthEnumElement *se,_enum->getElements() ){
            if(se->Lentier == v)
            {
                return se->LaChaine;
            }
        }
        throw("no element at " + QString::number(v) );
    }
    const SynthEnum * getType()const{return _enum;}
    void setType(const SynthEnum * e){ _enum=e;}

};

class ValueAny7b
        :public ValueMgr
{
public:
    ValueAny7b(QString s, int value=0)
        :ValueMgr(s,7,value) {}
    ValueAny7b( const ValueAny7b  &other)
        :ValueMgr(other){}
    void setValue(int v){ValueMgr::setValue(v);}
    int getValue()const{return ValueMgr::getValue();}
    int getValue(int v)const{return ValueMgr::getValue(v);}

    const SynthEnum * getType()const{return BlofeldTypesEnum::getInstance().GetEnum(BLOT_STANDARD);}
};


#endif // VALUEMGR_H
