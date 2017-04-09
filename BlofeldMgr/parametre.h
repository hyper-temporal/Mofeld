#ifndef PARAMETRE_H
#define PARAMETRE_H

#include <QFile>
#include <QDir>
#include <QDirIterator>
#include <QSettings>

#include "genericity/BlofeldEnums.h"
#include "contrainteparametre.h"
#include "genericity/valuemgr.h"
#include "defs.h"

class Parametre
{
    ValueEnum * _type;
    int _id;
    Contrainte _contrainte;
    bool _isProp;
public:
    Parametre();
    Parametre(const Parametre &p);
    Parametre(ValueEnum *w ,int i);
    Parametre(ValueEnum *w ,int i,int mi, int ma);

    Contrainte * editContrainte();
    const Contrainte * getContrainte() const;
    void setContrainte(const Contrainte *c);
    void setMethode(int m);
    void setProp(bool isprop){_isProp=isprop;}
    bool getProp()const{ return _isProp;}

    void setValue(int value);
    int getValue()const{return _type->getValue();}
    int getValue(int v)const;
    int SetNewValue(int v);
    int SetNewValue(int v,int min, int max);


    int getID()const{return _id;}

    const QString * getNom()const{return _type->getName();}
    ValueMgr * getType()const{return _type ;}

private:
    Contrainte * getNewContrainte( Contrainte * cn, int meth);
    void updateParametre_p2v(int value, Contrainte * c, int meth);
    void updateParametre_p2r(int value, Contrainte * c, int meth);


    friend class ContrainteRange;
    friend class ContrainteModel;
    friend class DumpInstrument;
    friend class Instrument;
    friend QDataStream & operator << (QDataStream &, const Parametre &);
    friend QDataStream & operator >> (QDataStream &, Parametre &);
};
Q_DECLARE_METATYPE(Parametre)
QDataStream & operator << (QDataStream & out, const Parametre & Valeur);
QDataStream & operator >> (QDataStream & in, Parametre & Valeur);

#endif // PARAMETRE_H
