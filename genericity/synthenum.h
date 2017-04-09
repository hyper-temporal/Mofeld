#ifndef SYNTHENUM_H
#define SYNTHENUM_H

#include <cmath>

#include <QVariant>
#include "QString"
#include <QVector>
#include "synthenumelement.h"
#include <stdexcept>


class SynthEnum
{

public:
    QString _nom;
    int _id;
    QVector<SynthEnumElement*> MesElements;

    SynthEnum();
    SynthEnum(QString s );
    SynthEnum(QList<QString> elts);

    void EnumValidation( SynthEnumElement *el);

    QVector<SynthEnumElement*> getElements()const{return MesElements;}
    const SynthEnumElement *  getElement(int i)const{return MesElements.at(i);}
    int getClosestValue(int input) const;
    int getNewValue(int input) const;
    int getNewValue(int input, int min, int max)const;

    int CountElements()const{return MesElements.count();}

    static bool sortElements(const SynthEnumElement * v1,const SynthEnumElement * v2)
    {
        return v1->Lentier < v2->Lentier;
    }
    void sort(){
        qSort(MesElements.begin(),MesElements.end(),sortElements);
    }
    int getMin()const{return MesElements.first()->Lentier;}
    int getMax()const{return MesElements.last()->Lentier;}

    int getRandomValue();
    int getRandomValue(int min, int max);
};


#endif // SYNTHENUM_H
