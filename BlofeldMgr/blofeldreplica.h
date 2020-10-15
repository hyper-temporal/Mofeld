#ifndef BLOFELDREPLICA_H
#define BLOFELDREPLICA_H

#include <QVector>
#include "Messaging/dumpglobal.h"
#include "Messaging/requestglobal.h"

#include "Messaging/dumpmulti.h"
#include "Messaging/dumpinstrument.h"
#include "Messaging/requestinstrument.h"
#include "Messaging/parametrecom.h"
#include "Messaging/requestwave.h"
#include "Messaging/dumpwave.h"

#include "BlofeldMgr/arrangement.h"
#include "wtDrawer_LIB/blofeldwavetablemgrmodel.h"

#include "BlofeldMgr/patienteur.h"
#include "Midi/miomgr.h"
//  classe de facade, les methodes publiques sont l'API offerte au monde exterieur.
//
#include "Messaging/requestmulti.h"
#include "defs.h"

class BlofeldReplica
        : public QObject, public Entity
{
    Q_OBJECT

    int _id;
    Patienteur _patienteur;
    int _tempo;
    int _editedChannel;
    DumpGlobal _globalParser;
    DumpMulti _multiParser;
    RequestMulti _multiRequest;
    DumpInstrument _instruParser;

    DumpWave _waveTableSender;

//    BlofeldWaveTableMgrModel _waveTables;
    Arrangement  *_Arrangement;
    //donnee par le dump machine
    QVector<Parametre> _paramGlobal;
    //autre classe se servant des capacite de persistance : represente les memoires persistance de la machine
    QVector<Instrument> _storeInstrument; //128*8
    QVector<Instrument> _storeArrangement;//128. référence 16 instruments de storeinstrument
//    QVector<BlofeldWaveTableMgrModel> _waveTables;//111 - 86
//Toutes ces mémloires sont synchronisable , séparément, par groupe ou de manière globale

    //  TODO : possedee une classe pour la gestion de l'actualisation de l'interface graphique et l'application de mediator
    //  sous qt ce sera par les signal/slot
    //
//    QObject * _parent;
    MIOMgr * _connecta;
public:
    BlofeldReplica();
    ~BlofeldReplica();
    RequestWave * ur;

    void Regenerate();
    void Regenerate(int ch);
    void ModifyArrangement(Arrangement * i, bool propch, bool propinstr, bool cntrnt, bool values);
    void ModifyInstrument(Instrument * i, bool props, bool cntrnt,  bool values);
    void setInstrumentName(QString s);

    //    DumpInstrument * getDump(){return &_instruParser;}
//    const BlofeldWaveTableMgrModel *getWaveTables(){return &_waveTables;}
    const Arrangement * getArrangement()const{ return _Arrangement; }
    const BlofChannel * getChannel(int ch)const{ return _Arrangement->getChannel(ch); }
    const BlofChannel * getChannel()const{ return _Arrangement->getChannel(_editedChannel); }
    const Instrument * getInstrument()const{ return _Arrangement->getInstrument(_editedChannel); }
    const Instrument * getInstrument(int ch)const{ return _Arrangement->getInstrument(ch); }
    const Propriete * getProprieteChannel()const{ return _Arrangement->getProprieteChannel(_editedChannel); }
    const Parametre * getparametre(int pid)const{ return _Arrangement->getParametre(_editedChannel,pid); }
    const Parametre * getparametre(int ch, int pid)const{ return _Arrangement->getParametre(ch,pid); }
    //  TODO : une classe TRANSACTION  qui gere les sequence request/dump , et les temps de reponse et de maniere generale le synchronisme avec le hard
    //  TODO : methodes a generaliser avec un protocole melant adresse + structure + typeprotocole(dump ,request)

    int getChCurrent(){return _editedChannel;}
    void ChangeEditedChannel(int ch);

    void syncParametre(int ch, int pid);

    void importInstrument(){importInstrument(_editedChannel);}
    void importInstrument(int ch);
    void importInstrument(int bank, int pgm);

    void importArrangement();

    void  initReplica();
//    BlofeldWaveTableMgrModel *editWaveTables(){return &_waveTables;}
    Arrangement * editArrangement(){return _Arrangement;}
    BlofChannel * editChannel(int ch){return _Arrangement->editChannel(ch);}
    Instrument * editInstrument(){return _Arrangement->editInstrument(_editedChannel);}
    Instrument * editInstrument(int ch){return _Arrangement->editInstrument(ch);}

    Parametre * editParam( int pid){return _Arrangement->editParam(_editedChannel,pid);}

    void setContrainte(int pid, Contrainte * c);
    void setPropriete(int pid, bool isprop){editChannel(_editedChannel)->setPropriete(pid,isprop);}
    void MixPropriete( const Propriete *p );
    void MixPropriete( const Propriete * p , int ch);
    //Lorsqu'on a une valeur a affecter
    void MixParametre( int ch,int pid, int val);
    //Lorsqu'on reçoit un parametre entier(contrainte, prop, etc)
    void MixParametre(const Parametre *pr, int ch);
    void MixArrangement(const Arrangement *);
    void MixInstrument(const Instrument *instr);
    void MixInstrument(const Instrument *instr, int ch);
    void setInstrument(  Instrument i);
    void setInstrument( Instrument i, int ch);

    MixPropParams *editMixPars(){return _Arrangement->editMixPars(_editedChannel);}

    QStringList getParamNames();


    const DumpMulti *getDumpMulti()const{return &_multiParser;}
    void multiRequest(int num);
    void multiSend(int num);

private slots:
    void newMessageReceived(std::vector<uchar> *);
public slots:
    void sendTable(const BlofeldWaveTableModel *, int wtnum, QString wtName);

signals:
    void updateArrangement(const Arrangement * arr);
    void updateInstrument(const Instrument * inst);
    void updatePropriete(const Propriete * prop);
    void updateParametre(const Parametre * param);
    void syncMulti();
private :
    void exportParametre(int ch, const Parametre *p);
    void MixParametres(const QVector<Parametre> * ps, int ch);
    void setMidiEnvironment();
//    Propriete * initPropriete(Propriete *p);

};


#endif // BLOFELDREPLICA_H
