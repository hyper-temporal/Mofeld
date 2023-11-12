#ifndef BLOFELDREPLICA_H
#define BLOFELDREPLICA_H

#include <QVector>
#include "dumpglobal.h"
#include "dumpmulti.h"
#include "dumpinstrument.h"
#include "requestwave.h"
#include "dumpwave.h"
#include "arrangement.h"
#include "patienteur.h"
#include "miomgr.h"
#include "requestmulti.h"


class IBlofeldView;

struct BlofeldGlobal{
    int devid;
    int tune;
    int midichannel;
};


class BlofeldReplica
        :public Entity
        ,public MidiReceiver
{
protected:
    IBlofeldView* _view;
private:
    BlofeldGlobal _id;
    IMidiIn *_min;
    IMidiOut *_mout;
    Patienteur _patienteur;
    int _tempo;
    int _editedChannel;
    DumpGlobal _globalParser;
    DumpMulti _multiParser;
    RequestMulti _multiRequest;
    DumpInstrument _instruParser;
    DumpWave _waveTableSender;

    Arrangement  _Arrangement;
    QVector<Parametre> _paramGlobal;

public:
    BlofeldReplica(
            IBlofeldView *view,
            IMidiIn *min,
            IMidiOut *mout,
            BlofeldGlobal g);
    BlofeldReplica(const BlofeldReplica& );
    BlofeldReplica(const BlofeldReplica&& );


    ~BlofeldReplica();

    ValueMgr* vaccessor(int pid, VAccessor aid){
        switch (aid) {
        case VAccessor::accessMulti:
            return _multiParser.getParametre(pid)->getType();
            break;
        case VAccessor::accessInstrument:
            return _instruParser.getParam(pid)->getValueMgr();
            break;
        case VAccessor::accessGlobal:
            return _globalParser.getParametre(pid);
            break;
        default:
            return nullptr;
            break;
        }
    }

    RequestWave * ur;
    void sendSysex(std::vector<uchar> message);
    void sendSysexFromFile(QString path);

    void Regenerate();
    void Regenerate(int ch);
    void ModifyArrangement(Arrangement * i, bool propch, bool propinstr, bool cntrnt, bool values);
    void ModifyInstrument(Instrument * i, bool props, bool cntrnt,  bool values);
    void setInstrumentName(QString s);

    const Arrangement * getArrangement()const{ return &_Arrangement; }
    const BlofChannel * getChannel(int ch)const{ return _Arrangement.getChannel(ch); }
    const BlofChannel * getChannel()const{ return _Arrangement.getChannel(_editedChannel); }
    const Instrument * getInstrument()const{ return _Arrangement.getInstrument(_editedChannel); }
    const Instrument * getInstrument(int ch)const{ return _Arrangement.getInstrument(ch); }
    const Propriete * getProprieteChannel()const{ return _Arrangement.getProprieteChannel(_editedChannel); }
    const MixPropParams * getPropAppliance()const{ return _Arrangement.getMixPars(_editedChannel); }
    const Parametre * getparametre(int pid)const{ return _Arrangement.getParametre(_editedChannel,pid); }
    const Parametre * getparametre(int ch, int pid)const{ return _Arrangement.getParametre(ch,pid); }

    DumpInstrument& getIMessage(){ return _instruParser; }


    int getChCurrent(){return _editedChannel;}
    void ChangeEditedChannel(int ch);

    void syncParametre(int ch, int pid);

    void importGlobal();
    void importInstrument(){importInstrument(_editedChannel);}
    void importInstrument(int ch);
    void importInstrument(int bank, int pgm);

    void importArrangement();

    void  initReplica(BlofeldGlobal g);
    BlofChannel * editChannel(int ch){return _Arrangement.editChannel(ch);}
    Instrument * editInstrument(){return _Arrangement.editInstrument(_editedChannel);}
    Instrument * editInstrument(int ch){return _Arrangement.editInstrument(ch);}

    Parametre * editParam( int pid){return _Arrangement.editParam(_editedChannel,pid);}

    void setContrainte(int pid, Contrainte * c);
    void setPropriete(int pid, bool isprop){editChannel(_editedChannel)->setPropriete(pid,isprop);}
    void MixPropriete( const Propriete *p );
    void MixPropriete( const Propriete * p , int ch);
    void MixParametre( int ch,int pid, int val);
    void MixParametre(const Parametre *pr, int ch);
    void MixArrangement(const Arrangement *);
    void MixInstrument(const Instrument *instr);
    void MixInstrument(const Instrument *instr, int ch);
    void setInstrument(  Instrument i);
    void setInstrument( Instrument i, int ch);

    MixPropParams *editMixPars(){return _Arrangement.editMixPars(_editedChannel);}

    QStringList getParamNames();


    const DumpMulti *getDumpMulti()const{return &_multiParser;}
    void multiRequest(int num);
    void multiSend(int num);
    void receive(std::vector<uchar> *) final;
    void sendTable(const BlofeldWaveTableModel *, int wtnum, QString wtName);
    void sendAllTables(const QVector<BlofeldWaveTableModel>  * tables);

private :
    void exportParametre(int ch, const Parametre *p);
    void MixParametres(const QVector<Parametre> * ps, int ch);
};


#endif // BLOFELDREPLICA_H
