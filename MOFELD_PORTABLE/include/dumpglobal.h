#ifndef BLOXGLOBAL_H
#define BLOXGLOBAL_H

#include "blofable.h"
#include "parametre.h"

//Chargée d'instancier les différentes structure
//Coté persistance on a un messa ge que l'on est capable de parser :
//donc ya plus qu'a l'ecrire sur un disque
class DumpGlobal
        :public Blofable
{
    QVector<Parametre*> _Parametres;

public:
    DumpGlobal();
    std::vector<uchar> * getMessage(int macid){
        return Blofable::getMessage(macid);
    }

    ValueMgr* getParametre(int pid){return _Parametres[pid]->getType();}

    void debug();
    void setParamValue(int pid, int value){
        _Parametres[pid]->setValue(value);
    }

private:
    void setAdressContent();
    void setDataContent();
    void setChecksum();
    //pour construire une interface sur les mots d'un message
    void addParametre(WordEnum *w);



};

#endif // BLOXGLOBAL_H
