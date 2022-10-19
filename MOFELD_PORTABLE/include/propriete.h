#ifndef INSTRUMENTSTICKER_H
#define INSTRUMENTSTICKER_H

#include "entitydao.h"
#include "itagable.h"
#include "parametre.h"

//Cette classe permet d'initialiser une selection de parametre
class Propriete
        :public ITagable,public Entity
{
    QVector<Parametre> _elements;
public:
    //pour la persistance
    Propriete();
    //copie identifiee
    Propriete(const Propriete *other, int id, QString nom);
    //echange de propriete
    Propriete(QVector<Parametre> * s):_elements(*s){}

    const QVector<Parametre> *getParametres()const{return &_elements;}
//    void clearAll();
//    void removePropriete(int id);
    int count(){return _elements.count();}

//    void addToPropriete_force(const Parametre &par);
//    void addToPropriete_weak(const Parametre &par);
//    void addToPropriete_force(const Propriete *prop);
//    void addToPropriete_weak(const Propriete *prop);

//    void setPropriete(const Propriete *prps);

//    static void move(Propriete * src, Propriete * dest);
//    static Propriete * keepParamsNotInDest(const Propriete *src, Propriete * dest);
    void addToPropriete(const Parametre &param);

private:
    bool  contains(int id );
//    void insertParam(const Parametre & par);
//    Parametre popParam();

};





#endif // INSTRUMENTSTICKER_H
