#ifndef BLOXGLOBAL_H
#define BLOXGLOBAL_H

#include "blofable.h"
#include "BlofeldMgr/parametre.h"


class DumpGlobal
        :public Blofable
{
    QVector<Parametre*> _Parametres;

public:
    DumpGlobal();

    std::vector<uchar> * getMessage(int macid){return Blofable::getMessage(macid);}

private:
    void setAdressContent(){;}
    void setDataContent();
    void setChecksum();
    void addParametre(WordWriter *w);



};

#endif // BLOXGLOBAL_H
