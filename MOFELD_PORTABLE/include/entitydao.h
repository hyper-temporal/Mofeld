#ifndef ENTITYDAO_H
#define ENTITYDAO_H

#include <QtCore/QCoreApplication>
#include <QVariant>
#include <QtDebug>
#include <QFile>
#include <QDir>
#include <QDirIterator>
#include <QSettings>
#include <QString>
#include <QDate>
#include <QAbstractTableModel>
#include "entity.h"
#include "icategorizable.h"



//persistance et gestion des collection generique
template<class T>
class EntityDAO
        : public ICategorizable
{


public:
    EntityDAO(
            QString cn,
            QString ext,
            QString path )
        :ICategorizable(path,cn),
          _className(cn),
          _extension(ext)
    {
        if(_catsName.empty()){
            addCategory("defaut");
        }
        setCategory(0);
    }
    virtual void ajouter(QString nom )=0;


    void setCategory(int id){
        beginResetModel();
        if(id > _catsName.size() || id < 0 ){
            _catName = &_catsName[0];
        }else{
            _catName = &_catsName[id];
        }
        QString s = _path + "/" + *_catName;
        importEntities(loadEntities(s));
        endResetModel();
    }

    int count()const{
        return _objects.count();
    }

    const T * getById(int i)const
    {
        foreach (Entity e, _objects){
            if(e.getID()==i){
                Entity * pe = &e;
                return pe; break;
            }
        }
        return NULL;
    }

    int findEntityByName(QString s){
        int i(0);
        foreach (const Entity * e, _objects){
            if(e->getName() == s){
                return i;
            }
            i++;
        }
        return -1;
    }

    void addEntity(QString s, const T *newT){
        if(s.trimmed()=="")return;

        int i = findEntityByName(s);
        if(i>=0){
            removeRows(i,1,QModelIndex());
        }

        const T * t = new T(newT,getNewId(),s);

        beginInsertRows(QModelIndex(), 0, 0);
        _objects.append(t);
        endInsertRows();
        saveEntity(*t);
    }

    void importEntities(QList<const T*> it){
        _objects.clear();
        beginInsertRows(QModelIndex(), 0,0);
        foreach(const T * t,it){
            _objects.append(t);
        }
        endInsertRows();
    }

    const T * getEntity(int i)const{
        foreach(const T * t,_objects){
            if(t->_id==i){
                return t;
            }
        }
        return NULL;
    }

    void deleteEntity(int row){
        if(row<0)
            return;
        QString Name = _objects.at(row)->getName();
        QFile::remove( _path + *_catName + "/" + Name + "." + _extension) ;
        removeRows(row,1,QModelIndex());
    }

    void saveEntity( T a){


        QDir dir = QDir(_path+ *_catName +"/");
        if(!dir.exists()){
            QDir().mkdir(dir.absolutePath());
        }
        QSettings fichier_ecrire(
                    _path+ *_catName +"/" + a._name+ "." + _extension,
                    QSettings::IniFormat);
        fichier_ecrire.setValue( _className , QVariant::fromValue(a));
        fichier_ecrire.sync();
    }

    QList<const T*> loadEntities(QString path)
    {
        QDir dir = QDir(_path+ *_catName +"/");
        if(!dir.exists()){
            QDir().mkdir(dir.absolutePath());
        }
        QDirIterator it(path, QStringList() << "*." + _extension , QDir::Files, QDirIterator::Subdirectories);
        QList<const T*> lst;
        while (it.hasNext()){
            QSettings fichier_lire( it.next(), QSettings::IniFormat);
            T t(qvariant_cast<T>(fichier_lire.value(_className, QVariant::fromValue(T()))));
            lst.append(new T(t));
        }
        return lst;
    }


private:
    int getNewId()
    {
        sortById();
        int cnt = _objects.count();
        if(cnt<3){
            for(int i(0);i<cnt;i++){
                if(i<_objects.at(i)->_id)
                    return i;
            }
            return cnt;
        }

        for(int i(0);i<_objects.count()-1;i++){

            int i0 =  _objects.at(i)->_id;
            int i1 =  _objects.at(i+1)->_id;

            if( i1 - i0>1){
                return (i0+1) ;
            }
        }
        return (_objects.last()->_id+1);
    }

    static bool sortEntities_ById(const T * v1,const T * v2)
    {
        return v1->_id < v2->_id;
    }

    void sortById()
    {
        std::sort(_objects.begin(),_objects.end(),sortEntities_ById);
    }

protected:
    QString _className;
    QString _extension;
    QObject * _parent;
    QVector<const T*> _objects;
    const QString  * _catName ;

    int rowCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return count();
    }
    int columnCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return 3;
    }
    QVariant data(const QModelIndex &index, int role) const
    {
        if (!index.isValid())
            return QVariant();

        if (index.row() >= count() || index.row() < 0)
            return QVariant();

        if (role == Qt::DisplayRole) {
            const Entity * e = _objects.at(index.row());
            if (index.column() == 0){
                return e->_name;
            }
            else if (index.column() == 1){
                return e->_datecreation;
            }
            else if (index.column() == 2){
                return e->_id;
            }

        }
        return QVariant();
    }
    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return tr("Nom");
                case 1:
                    return tr("Date");
                case 2:
                    return tr("Id");
                default:
                    return QVariant();
            }
        }
        return QVariant();
    }
    bool insertRows(int position, int rows, const QModelIndex &index)
    {
        Q_UNUSED(index);
        beginInsertRows(QModelIndex(), position, position+rows-1);

        for (int row=0; row < rows; row++) {

        }

        endInsertRows();
        return true;
    }
    bool removeRows(int position, int rows, const QModelIndex &index)
    {
        Q_UNUSED(index);
        beginRemoveRows(QModelIndex(), position, position+rows-1);

        for (int row=position; row < position+rows; ++row) {
            _objects.remove(row);
        }
        endRemoveRows();
        return true;
    }
    bool setData(const QModelIndex &index, const QVariant &value, int role)
    {
        if (index.isValid() && role == Qt::EditRole) {
            int row = index.row();

            const T * e = _objects.at(row);
            if (index.column() == 0){
                //                e->_name = value.toString();
                return false;
            }
            _objects.replace(row,e);
            emit(dataChanged(index, index));
            return true;
        }

        return false;
    }
    Qt::ItemFlags flags(const QModelIndex &index) const
    {
        if (!index.isValid())
            return Qt::ItemIsEnabled;

        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    }
};




#endif // ENTITYDAO_H
