#ifndef WREPLACER_H
#define WREPLACER_H

#include <QVector>
class MessageWriter;
class WordWriter;
/*
    Met en relation une position avec un mot
*/
class Consequence
{
    WordWriter * _mot;
    int _position;
public:
    Consequence(int p,WordWriter * m)
        :_mot(m),_position(p){}
    virtual WordWriter * doIt(MessageWriter * mw);
};

//met en relation un etat avec une liste de mots qui viendrons en remplacer d'autres si cet etat est satisfait
class WordMutation
{
public:
    WordMutation(int v,QVector<Consequence*> * lst ):_state(v),_consequences(lst){}
    int _state ;    //valeur pour laquelle la liste de consequence est appliquée
    QVector<Consequence*> * _consequences;
};

//contient la position d'un mot dans un message (pourquoi pas un pointeur constant?)
class WReplacer
{
public:
    WReplacer(const WordWriter * w , QVector<WordMutation*> * l )
        :_WordPos(w),_mutation(l){}
    const WordWriter * _WordPos;
    QVector<WordMutation*> * _mutation;
    int getValue() const;
};

//si un certain mot (constant) contenu dans un message extrait(parse) une valeur particuliere,
//une liste de mot est remplacée


#endif // WREPLACER_H
