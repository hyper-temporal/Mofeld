#ifndef WREPLACER_H
#define WREPLACER_H

#include <QVector>
class MessageWriter;
class WordWriter;


class Consequence
{
    WordWriter * _mot;
    int _position;
public:
    Consequence(int p,WordWriter * m)
        :_mot(m),_position(p){}
    virtual WordWriter * doIt(MessageWriter * mw);
};

class WordMutation
{
public:
    WordMutation(int v,QVector<Consequence*> * lst ):_state(v),_consequences(lst){}
    int _state ;    //valeur pour laquelle la liste de consequence est appliquée
    QVector<Consequence*> * _consequences;
};

class WReplacer
{
public:
    WReplacer(const WordWriter * w , QVector<WordMutation*> * l )
        :_WordPos(w),_mutation(l){}
    const WordWriter * _WordPos;
    QVector<WordMutation*> * _mutation;
    int getValue() const;
};



#endif // WREPLACER_H
