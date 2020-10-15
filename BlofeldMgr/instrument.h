#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QFile>
#include <QDir>
#include <QDirIterator>
#include <QVector>
#include <QSettings>
#include <QAbstractTableModel>

#include "genericity/entitydao.h"
#include "propriete.h"
#include "itagable.h"

#include "mixpropparams.h"

class Instrument
        :public ITagable,public Entity
{
    QVector<Parametre> _parametre;
public:

    Instrument();
    Instrument(const Instrument *other, int id, QString nom);
    Instrument(QString, QVector<Parametre> lst);

    void regenerate();
    int count()const{return _parametre.count();}

    void setParamValue(int pid,int v);
    void setParamContrainte(int pid,const Contrainte *c);
    int getValue(int idt) const;

    void replaceHeader(const Instrument i);
    void replaceParametres(const Instrument i);
    void SetInstrument(const Instrument i);

    void updateParametre(const Parametre *p, bool contr, bool val);
    void updateParametre(const Parametre *p, const MixPropParams *mps);
    void updateParametres(const QVector<Parametre> *pars, const MixPropParams *mps);
    void AddTag(QString s);

    Parametre * editParametre(int pid);
    const Parametre * getParametre(int pid)const;
    const QVector<Parametre> * getParametres()const{return &_parametre;}

    const Propriete *getPropriete() const;
    void setPropriete(int id, bool isprop);

private:
    void setContrainte(const Parametre *p);
    void setValue(const Parametre *p);
    bool paramBelongsToProp(int id);


    friend class InstrumentModel;

};


#endif // INSTRUMENT_H
