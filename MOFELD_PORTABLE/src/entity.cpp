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

