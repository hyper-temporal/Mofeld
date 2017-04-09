#include "parametre.h"


Parametre::Parametre()
{
    _isProp = false;
    _type=new ValueEnum() ;
}

Parametre::Parametre(const Parametre &p)
    :   _type(p._type),
        _id(p.getID()),
        _contrainte(p.getContrainte()),
        _isProp(p._isProp)
{}

Parametre::Parametre(ValueEnum * w ,int i)
    :_type(new ValueEnum(*w)),_id(i),_isProp(false)
{}

Parametre::Parametre(ValueEnum * w ,int i,int mi, int ma)
    :_type(new ValueEnum(*w)),_id(i),_contrainte(mi,ma),_isProp(false)
{}


Contrainte * Parametre::editContrainte(){
    return &_contrainte;
}
const Contrainte * Parametre::getContrainte()const{
    return &_contrainte;
}

Contrainte * Parametre::getNewContrainte( Contrainte * cn, int meth){
    switch(meth){
    case METHOD_RANGE_RESTRICT:
        return _contrainte.getNewRestricted(cn);
        break;
    case METHOD_RANGE_EXTEND:
        return _contrainte.getNewExtended(cn);
        break;
    case METHOD_RANGE_KEEPMINS:
        return _contrainte.getNewKeepMins(cn);
        break;
    case METHOD_RANGE_KEEPMAX:
        return _contrainte.getNewKeepMaxs(cn);
        break;
    default:
        return _contrainte.getNewRestricted(cn);
        break;
    }
}


void Parametre::setContrainte(const Contrainte * c){
    _contrainte = *c;
    setValue( getValue());
}

void Parametre::setValue(int value){
    _type->setValue( _contrainte.check(value));
}

int Parametre::getValue(int v) const{
    return _type->getValue(v);
}
int Parametre::SetNewValue(int v) {
    setValue(_type->getNewValue(v));
}
int Parametre::SetNewValue(int v,int min, int max) {
    setValue(_type->getNewValue(v,min,max));

}

QDataStream & operator << (QDataStream & out, const Parametre & Valeur)
{
    out << Valeur._id
        << Valeur._type->getValue()
        << Valeur._contrainte
        << Valeur._isProp
            ;
    return out;
}
QDataStream & operator >> (QDataStream & in, Parametre & Valeur)
{
    int i;
    in  >> Valeur._id
        >> i
        >> Valeur._contrainte
        >> Valeur._isProp
           ;

    Valeur._type->setValue(i);
    return in;
}
