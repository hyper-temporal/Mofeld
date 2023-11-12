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


class ITagable
{
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
