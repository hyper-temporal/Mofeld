#include "itagable.h"


int TagList::getNewIndex(){
    int i =-1;
    foreach(Tag * t, _tags){
        if(t->_id > i){
            i=t->_id+1;
        }
    }
    return i;
}
Tag * TagList::getByIndex(int i){
    foreach(Tag * t, _tags){
        if(t->_id == i){
            return t;
        }
    }
    return NULL;
}
Tag * TagList::getByName(QString s){

    foreach(Tag * t, _tags){
        if(t->_nom == s){
            return t;
        }
    }
    return NULL;
}

Tag * TagList::addTag(QString s){
    Tag * t ;
    int index = getIndex(s);
    if(index<0){
       t = new Tag(s);
       index = getNewIndex();
       t->_id = index;
       _tags.append(t);
    }
    return getByIndex(index);
}

int TagList::getIndex(QString s){
    foreach(Tag * t, _tags){
        if(t->_nom == s){
            return t->_id;
        }
    }
    return -1;
}


ITagable::ITagable()
{
}

void ITagable::addTag(QString s){
    //Si il existe dans la liste on a finit
    foreach(Tag * t ,_tagsCollect){
        if(t->getNom() == s.trimmed()){
            return;
        }
    }
    Tag * t  =_tagsCommon->getByName(s);
    if(t == NULL){
        t =_tagsCommon->addTag(s);
    }
    _tagsCollect.append(t);
}


