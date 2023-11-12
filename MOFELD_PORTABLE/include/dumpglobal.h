#ifndef BLOXGLOBAL_H
#define BLOXGLOBAL_H

#include "blofable.h"
#include "parametre.h"

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
    void addParametre(WordEnum *w);
};

#endif // BLOXGLOBAL_H
