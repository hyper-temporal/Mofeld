#ifndef WRITERMESSAGE_H
#define WRITERMESSAGE_H

#include <QList>
#include <QVector>
#include "wordwriter.h"
#include "wordchecksum.h"
#include "replacer.h"


class MessageWriter
{

protected:

    QVector<WordWriter*> _mots;
    std::vector<uchar> _message;

    QVector<WReplacer *> * _replacers;
    void setWordValue(int p , int v);
    int getWordValue(int p );

    void appenWord(WordWriter * );
    void appenWords(QVector<WordWriter*> );
    void insertWord(int , WordWriter* );
    void insertWords(int , QVector<WordWriter*> );
    WordWriter* mutateWord(int pos, WordWriter* mutant);
    void replaceWord(int , WordWriter* );
    void replaceWords(int , QVector<WordWriter*> );
    void replaceMessage(QVector<WordWriter*> );
    WordWriter *  getWord(int p){return _mots.at(p);}
    int countWords(){return _mots.count();}
public:
    MessageWriter(int size);
    QVector<WordWriter *> checkWReplacers();
private:
    void checkPosition(int);

    friend class Consequence;
    friend class Sysexable;

};









#endif // WRITERMESSAGE_H
