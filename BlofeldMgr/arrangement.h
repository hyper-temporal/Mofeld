#ifndef ARRANGEMENTMGR_H
#define ARRANGEMENTMGR_H

#include <QFile>
#include <QDir>
#include <QDirIterator>
#include <QSettings>
#include <QAbstractTableModel>
#include <QVector>

#include "blofchannel.h"
#include "genericity/entitydao.h"
#include "Messaging/dumpmulti.h"

class Arrangement
        :public Entity
{
    QVector<BlofChannel> _BlofChannel;
public:
    //pour la persistance
    Arrangement();
    //copie identifiee
    Arrangement(const Arrangement *other, int id, QString s );

    void Regenerate(int channel);
    void setArrangement(const Arrangement * a);
    void setInstrument(const Instrument i,int ch);

    void AddTag(QString s);

    const BlofChannel * getChannel(int ch)const{return &_BlofChannel[ch];}
    const Instrument * getInstrument(int ch)const{return _BlofChannel[ch].getInstrument();}
    const Propriete * getProprieteChannel(int ch)const{return _BlofChannel[ch].getProprieteChannel();}
    const Parametre * getParametre(int ch,int pid)const{return _BlofChannel[ch].getParametre(pid);}

    BlofChannel * editChannel(int ch){return &_BlofChannel[ch];}
    Instrument * editInstrument(int ch){return _BlofChannel[ch].editInstrument();}
    Parametre * editParam(int ch,int pid){return _BlofChannel[ch].editParametre(pid);}
    void setParametre(int chid, int pid, int v){ _BlofChannel[chid].setParamValue(pid,v);}

    const MixPropParams *getMixPars(int ch)const{return  _BlofChannel[ch].getMixPars();}
    MixPropParams *editMixPars(int ch){return  _BlofChannel[ch].editMixPars();}
    void setMixPars(int ch,const MixPropParams *mpars){ _BlofChannel[ch].setMixPars(mpars);}

    const QVector<Parametre> *getMultiPars(int ch)const{return  _BlofChannel[ch].getMultiPars();}
    void setMultiPars(int ch,const QVector<Parametre> *pars){ _BlofChannel[ch].setMultiPars(pars);}

private:
    void init();
    friend class ArrangementModel;
    friend class DumpMulti;

    friend QDataStream & operator << (QDataStream &, const Arrangement &);
    friend QDataStream & operator >> (QDataStream &, Arrangement &);

};

Q_DECLARE_METATYPE(Arrangement)
QDataStream & operator << (QDataStream & out, const Arrangement & Valeur);
QDataStream & operator >> (QDataStream & in, Arrangement & Valeur);



#endif // ARRANGEMENTMGR_H
