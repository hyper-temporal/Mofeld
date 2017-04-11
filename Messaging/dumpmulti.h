#ifndef DUMPMULTI_H
#define DUMPMULTI_H
#include "blofable.h"
#include "BlofeldMgr/parametre.h"

class BlofChannel;

class DumpMulti
        :public Blofable
{
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


private:
    void setAdressContent();
    void setDataContent();
    void setChecksum();
    void addParametre(WordWriter *w );
    Parametre *getParametre(int id)const{
        return new Parametre((ValueEnum*)_mots.at(id)->getValueMgr(),id);
    }

    friend class BlofeldMultiSlice;
    friend class BlofeldMultiVue;

};

#endif // DUMPMULTI_H
