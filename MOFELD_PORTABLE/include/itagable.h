#ifndef ICATEGORISABLE_H
#define ICATEGORISABLE_H


#include <QStringList>
#include <QStringListModel>
#include <QStringMatcher>

class Tag{
    QString _nom;
    int _id;
public:
    Tag(QString s):_nom(s){}
    bool IsMatching(QString);
    int getId()const{return _id;}
    QString getNom()const{return _nom;}

    friend class TagList;
};

//Une liste de references
class TagList{
    QList<Tag*> _tags;

public:
    TagList();
    QList<Tag*> getTags()const{return _tags;}
    Tag * addTag(QString s);
    Tag * getByIndex(int i);
    Tag * getByName(QString s);

private:
    int getNewIndex();
    int getIndex(QString s);

};


//la classe contient les identifiants des tags de la liste qu'elle utilise
//On peut associer la classe a
class ITagable
{
    //la class fournissant les données de tag devra etre instanciée au préalable et passé à la construction
protected :
    TagList * _tagsCommon;
    QList<Tag*> _tagsCollect;

public:
    ITagable();

    void addTag(QString s );
    QList<Tag*>  getObjectTags() const {return _tagsCollect;}
    ITagable addTheseTags(const TagList * );
    ITagable formatAndAddifNotExist(QString ,QList<ITagable> * );
    ITagable selection(TagList ,QList<ITagable> * );
};




#endif // ICATEGORISABLE_H
