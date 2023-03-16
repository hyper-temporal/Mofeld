#ifndef DUMPMULTI_H
#define DUMPMULTI_H
#include "blofable.h"
#include "parametre.h"

class BlofChannel;

class DumpMulti
        :public Blofable
{
    QVector<Parametre*> _Parametres;

public:
    DumpMulti();
    std::vector<uchar> * getMessage(int macid, int multid){
        setMultiNumber(multid);
        return Blofable::getMessage(macid);
    }
    void setMultiNumber(int num);
    int getMultiNumber();

    QString getMultiName();
    void setMultiName(QString);

    void initChannel(BlofChannel *ch, int chid);
    void fromChannel(BlofChannel *ch, int chid);
    void toChannel(BlofChannel *ch, int chid);

    int getMultiTempo();
    void setMultiTempo(int);

    int getMultiVolume();
    void setMultiVolume(int);
    Parametre *getParametre(int id)const{
        return _Parametres[id];
    }


private:
    void setAdressContent();
    void setDataContent();
    void setChecksum();
    //pour construire une interface sur les mots d'un message
    void addParametre(WordWriter *w );

    friend class BlofeldMultiSlice;
    friend class BlofeldMultiVue;

};

#endif // DUMPMULTI_H
