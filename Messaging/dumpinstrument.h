#ifndef BLOXINSTRUMENT_H
#define BLOXINSTRUMENT_H

#include "blofable.h"
#include "replacer.h"
#include "parametrecom.h"
#include "BlofeldMgr/instrument.h"
#include "wordchecksum.h"

class DumpInstrument: public Blofable
{
    QVector<ParametreCom*> _Parametres;

public:
    DumpInstrument();

    int getChannel();
    Instrument createInstrument();
    Parametre createParametre(int i);
    void setInstrument(const Instrument *) const;

    int count(){return _Parametres.count();}
    void  setEmbeddedName(QString name);
    QString getEmbeddedName();
    std::vector<uchar> *getMessage(int macid,int bank, int pgm);
    std::vector<uchar> *getMessage(int macid,int chid);
    std::vector<uchar> *getPMessage(const Parametre* p,int macid,int chid);

    QVector<ParametreCom*>  getParams(){return _Parametres;}

    QVector<ParametreCom *> getParams(std::vector<uchar> * v);
    QVector<ParametreCom *> getParams(int a1,int a2);
    QVector<ParametreCom *> getParams(int pid);
    QVector<ParametreCom *> updateParam(std::vector<uchar> * v);

    ParametreCom * getParam(std::vector<uchar> * v);
    ParametreCom * getParam(int pid);
    ParametreCom * getParam(int a1,int a2);
    ParametreCom createParam(int pid);

private:
    void addParametre(WordWriter *w ,int ad1,int ad2);
    void setAdressContent();
    void setDataContent();
    void setChecksum();


};

#endif // BLOXINSTRUMENT_H

