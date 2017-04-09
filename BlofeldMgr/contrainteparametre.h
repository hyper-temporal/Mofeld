#ifndef CONTRAINTEPARAMETRE_H
#define CONTRAINTEPARAMETRE_H

#include <QFile>
#include <QDir>
#include <QDirIterator>
#include <QSettings>
#include <QAbstractTableModel>
#include "defs.h"

#include "genericity/valuemgr.h"

class Contrainte
{

    int _min;
    int _max;
    ValueMgr *_valueMgr;

public:
    Contrainte(ValueMgr *);
    Contrainte():_min(0),_max(127){}
    Contrainte(int min , int max);
    Contrainte(const Contrainte * c);

    int  check(int);

    int getMinValue()const{return _min;}
    int getMaxValue()const{return _max;}
    Contrainte * getNewRestricted(const Contrainte *) const;
    Contrainte * getNewExtended(const Contrainte *) const;
    Contrainte * getNewKeepMins(const Contrainte *) const;
    Contrainte * getNewKeepMaxs(const Contrainte *) const;

    void updateMin(int v);
    void updateMax(int v);
    void restrict2Value(int v);
private:

    int getSmallestMin(const Contrainte * co,const Contrainte * cn)const;
    int getSmallestMax(const Contrainte * co,const Contrainte * cn)const;
    int getTallestMin(const Contrainte * co,const Contrainte * cn)const;
    int getTallestMax(const Contrainte * co,const Contrainte * cn)const;

    friend class Parametre;

    friend QDataStream & operator << (QDataStream &, const Contrainte &);
    friend QDataStream & operator >> (QDataStream &, Contrainte &);
};

Q_DECLARE_METATYPE(Contrainte)
QDataStream & operator << (QDataStream & out, const  Contrainte & Valeur);
QDataStream & operator >> (QDataStream & in, Contrainte & Valeur);


#endif // CONTRAINTEPARAMETRE_H
