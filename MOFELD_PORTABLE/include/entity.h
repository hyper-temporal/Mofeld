#ifndef ENTITY_H
#define ENTITY_H

#include <QVariant>
#include <QFile>
#include <QDir>
#include <QDirIterator>
#include <QSettings>
#include <QString>
#include <QDate>

class Entity
{
protected:
public:
    int _id;
    QString _name;
    QString _path;
    QDate _datecreation;
    Entity();
    Entity(int id ,QString n);
    Entity  getEntity()const{return *this;}
    int getID()const{return _id;}
    QString getName()const{
        return (_name.trimmed());
    }

    void setName(QString n){ _name=n;}
    //    void setID(int i){ _id=i;}
    friend QDataStream & operator << (QDataStream & out, const Entity & Valeur);
    friend QDataStream & operator >> (QDataStream & in, Entity & Valeur);

};

Q_DECLARE_METATYPE(Entity)



#endif // ENTITY_H
