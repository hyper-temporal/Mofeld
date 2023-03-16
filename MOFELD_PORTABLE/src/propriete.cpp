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

//void Propriete::addToPropriete_force(const Propriete * prop){
//    foreach(Parametre  p, *prop->getParametres()){
//        addToPropriete_force(p);
//    }
//}
//void Propriete::addToPropriete_weak(const Propriete * prop){
//    foreach(Parametre  p, *prop->getParametres()){
//        addToPropriete_weak(p);
//    }
//}

//void Propriete::addToPropriete_force(const Parametre &par){
//    int pos = 0;
//    foreach(Parametre  p,_elements){
//        if(p.getID() == par.getID()){
//            _elements.replace(pos,par);
//            return;
//        }
//        pos++;
//    }
//    _elements.append(par);
//}

//void Propriete::addToPropriete_weak(const Parametre &par){
//    foreach(Parametre  p,_elements){
//        if(p.getID() == par.getID()){
//            return;
//        }
//    }
//    _elements.append(par);
//}

//void Propriete::clearAll(){
//    _elements.clear();
//}
//void Propriete::removePropriete(int id)
//{
//    int cnt(0);
//    foreach(Parametre p, _elements){
//        if(p.getID()==id){
//            _elements.remove(cnt,1);
//        }
//        cnt++;
//    }
//}

//void Propriete::setPropriete(const Propriete * prop){
//    clearAll();
//    foreach(Parametre  p, *prop->getParametres()){
//        _elements.append(p);
//    }
//}
//void Propriete::insertParam(const Parametre & par){
//    _elements.push_back(par);
//}

//Parametre Propriete::popParam(){
//    Parametre p = _elements.last();
//    _elements.pop_back();
//    return p;
//}

//void Propriete::move(Propriete * src, Propriete * dest){
//    for(int i(0);i< src->count();i++){
//        dest->insertParam(src->popParam());
//    }
//}
//Propriete * Propriete::keepParamsNotInDest(const Propriete * src, Propriete * dest){
//    QVector<Parametre> vp;
//    foreach(Parametre p, *src->getParametres())
//    {
//        if(! dest->contains(p.getID())){
//            vp.append(p);
//        }
//    }
//    return new Propriete(&vp);
//}

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
