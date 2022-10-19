#include "icategorizable.h"



ICategorizable::ICategorizable(QString path, QString typeName)
    :_path(path), _typeName(typeName)
{
    QDirIterator directories( _path,  QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    while(directories.hasNext()){
        QDir d(directories.next());
        _catsName.append(d.dirName());
    }
}

QStringList ICategorizable::getCatsName()
{
    QStringList ret;
    foreach(QString s, _catsName)
    {
        if(s.trimmed()!="")
        {
            ret.append( s );
        }
    }
    return ret;
}

void ICategorizable::addCategory(QString newCat)
{
    newCat = newCat.trimmed();
    foreach(QString s, _catsName)
    {
        if(s.trimmed()==newCat)
        {
            return;
        }
    }
    _catsName.append(newCat);
}
