#include "messagewriter.h"

MessageWriter::MessageWriter(int size):_message(size)
{
    _replacers = new QVector<WReplacer*>();
}

void MessageWriter::setWordValue(int p , int v){
    _mots.at(p)->setValue(v);
}
int MessageWriter::getWordValue(int p ){
    return _mots.at(p)->getValue();
}

QVector<WordWriter *> MessageWriter::checkWReplacers()
{
    QVector<WordWriter *> vws;
    //pour chaque groupe variable/etat/consequence
    foreach(WReplacer * wrp, *(_replacers) ){
        foreach(WordMutation * wrs, *(wrp->_mutation) ){
        //Si le mot correspondant correspond a un etat
            if(wrp->getValue() == wrs->_state){
                //on applique chacune des consequences
                foreach(Consequence * c,*(wrs->_consequences)){
                    vws.append(c->doIt(this));
                    //replaceWord(c->_position,c->_mot);
                }
            }
        }
    }
    return vws;
}

void MessageWriter::appenWord (WordWriter * w){
    _mots.append(w);
}
void MessageWriter::appenWords(QVector<WordWriter*> words){
    foreach(WordWriter * w, words){
        appenWord(w);
    }
}


void MessageWriter::insertWord(int pos, WordWriter* word){
    checkPosition(pos);
    _mots.insert(pos, word);
}

void MessageWriter::insertWords(int pos, QVector<WordWriter*> words){
    foreach(WordWriter * w, words){
        insertWord(pos++,w);
    }
}

void MessageWriter::replaceWord(int pos, WordWriter* mutant){
    checkPosition(pos);
    _mots.replace(pos,mutant);
}

WordWriter * MessageWriter::mutateWord(int pos, WordWriter* mutant){
    replaceWord( pos,  mutant);
    return _mots.at(pos);
}

void MessageWriter::replaceWords(int pos, QVector<WordWriter*> mutants){
    checkPosition(pos);
    checkPosition(pos+mutants.count()-1);
    int i(0);
    foreach(WordWriter * w,mutants){
        replaceWord(i++,w);
    }
}

void MessageWriter::replaceMessage( QVector<WordWriter*> words){
    _mots.clear();
    foreach(WordWriter * w,words){
        _mots.append( w);
    }
}


void MessageWriter::checkPosition(int pos){
    if(this->_mots.size()<pos)throw("le message initial est trop petit");
}
