#ifndef INSTRUMENTSTICKER_H
#define INSTRUMENTSTICKER_H

#include "itagable.h"
#include "parametre.h"
#include "entity.h"

class Propriete
        :public ITagable,
        public Entity
{
protected:
    QVector<Parametre> _elements;
public:
    Propriete();
    Propriete(const Propriete *other, int id, QString nom);
    Propriete(QVector<Parametre> * s):_elements(*s){}

    const QVector<Parametre> *getParametres()const{return &_elements;}
    int count(){return _elements.count();}
    void addToPropriete(const Parametre &param);

private:
    bool  contains(int id );
    friend QDataStream & operator << (QDataStream &, const Propriete &);
    friend QDataStream & operator >> (QDataStream &, Propriete &);
};


Q_DECLARE_METATYPE(Propriete)



#endif // INSTRUMENTSTICKER_H
