#ifndef PARAMETRE_H
#define PARAMETRE_H

#include <QFile>
#include <QDir>
#include <QDirIterator>
#include <QSettings>

#include <BlofeldEnums.h>
#include "contrainteparametre.h"
#include "valuemgr.h"
#include <defs.h>

class Parametre
{
    ValueMgr * _type;
    int _id;
    Contrainte _contrainte;
    bool _isProp;
public:
    Parametre();
    Parametre(const Parametre &p);
    Parametre(ValueMgr *w ,int i);
    Parametre(ValueMgr *w ,int i,int mi, int ma);

    Contrainte * editContrainte();
    const Contrainte * getContrainte() const;
//    void copyContrainte(const Contrainte *c);
    void setContrainte(const Contrainte *c);
    void setMethode(int m);
    void setProp(bool isprop){_isProp=isprop;}
    bool getProp()const{ return _isProp;}

    void setValue(int value);
    int getValue()const{return _type->getValue();}
    int getValue(int v)const;
    void SetNewValue(int v);
    void SetNewValue(int v,int min, int max);


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

#endif // PARAMETRE_H
