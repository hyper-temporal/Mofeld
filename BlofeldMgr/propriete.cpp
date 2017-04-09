#include "propriete.h"

Propriete::Propriete()
{}

//demandé pour la serialization
Propriete::Propriete(const Propriete *other, int id, QString nom)
    :Entity(id,nom)
{
    foreach(const Parametre &p, other->_elements){
        Parametre pbo(p);
        _elements.append(pbo);
    }
}

void Propriete::addToPropriete(const Parametre &param)
{
    if(!contains(param.getID())){
        _elements.append(param);
    }
}

bool  Propriete::contains(int id ){
    foreach(Parametre p, _elements){
        if(p.getID()==id){
            return true;
        }
    }
    return false;
}




QDataStream & operator << (QDataStream & out, const Propriete & Valeur)
{
    out << Valeur._id
        << Valeur._name
        << Valeur._datecreation
        << Valeur._elements
        ;
    return out;
}

QDataStream & operator >> (QDataStream & in, Propriete & Valeur)
{
    in >> Valeur._id
        >> Valeur._name
        >> Valeur._datecreation
        >> Valeur._elements
           ;

    return in;
}
