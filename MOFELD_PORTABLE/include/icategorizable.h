#ifndef ICATEGORIZABLE_H
#define ICATEGORIZABLE_H

#include  <QString>
#include <QAbstractTableModel>
#include <QDirIterator>

class ICategorizable: public QAbstractTableModel
{
protected:
     QString _path;
     QStringList _catsName;
     QString _typeName;
public:
    ICategorizable(QString path,QString typeName);

    const QString * getTypeName(){return &_typeName;}
    QStringList getCatsName();
    void addCategory(QString newCat);
    virtual void setCategory(int id) =0;

};

#endif // ICATEGORIZABLE_H
