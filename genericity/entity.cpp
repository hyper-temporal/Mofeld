#include "entity.h"

Entity::Entity():_id(0),_name("_new_")
{
    _datecreation = QDate::currentDate();
}


Entity::Entity(int id, QString n)
    :_id(id),_name(n)
{
    _datecreation = QDate::currentDate();
}



//QDataStream & operator << (QDataStream & out, const Entity & Valeur)
//{
//    out << Valeur._name
//        << Valeur._datecreation
//        << Valeur._id;
//    return out;
//}

//QDataStream & operator >> (QDataStream & in, Entity & Valeur)
//{
//    in  >> Valeur._name
//        >> Valeur._datecreation
//        >> Valeur._id;
//    return in;
//}
