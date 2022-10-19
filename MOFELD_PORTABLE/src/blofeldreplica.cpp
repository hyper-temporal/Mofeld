#include "blofeldreplica.h"

using namespace OperationProps ;

BlofeldReplica::BlofeldReplica()
{
    _editedChannel = 0;
    _id=0;
    _Arrangement = new Arrangement();
    initReplica();
    setMidiEnvironment();
}

BlofeldReplica::~BlofeldReplica()
{
    delete _connecta;
}
void BlofeldReplica::Regenerate()
{
    Regenerate(_editedChannel);
}

void BlofeldReplica::Regenerate(int ch)
{
    Instrument *i = editInstrument(ch);
    i->regenerate();
    if(ch == _editedChannel){
        emit updateInstrument(getInstrument(ch));
    }
}

void BlofeldReplica::setInstrumentName(QString s )
{
    try {
        _instruParser.setEmbeddedName(s);
        for(int i(0);i<16;i++){
            ParametreCom *p= _instruParser.getParam(341 +i);
            std::vector<uchar> * vec = p->getMessage(_id,_editedChannel);
            _connecta->sendSysex(vec);
        }
    } catch (...) {

    }

}

void BlofeldReplica::setMidiEnvironment(){

    _connecta->setMidiInput("blofeld");
    _connecta->setMidiOutput("blofeld");
    connect(_connecta, SIGNAL(SysexChanged(std::vector< uchar > *))
            ,  this, SLOT(newMessageReceived(std::vector< uchar > *)));
}


void BlofeldReplica::newMessageReceived(std::vector< uchar > * sxMess)
{
    int siz = sxMess->size();
    qInfo()<< "rcv:" <<siz;
    switch(siz)
    {
        case(10):
        {
            QVector<ParametreCom *> ps =_instruParser.updateParam(sxMess);
            foreach(ParametreCom * p,ps){
                MixParametre(p->getChannel(),p->getId(),p->getValue());
                if(p->getChannel() == _editedChannel)
                {
                    const Parametre * par = _Arrangement->getParametre(p->getChannel(),p->getId());
                    emit(updateParametre(par));
                }
            }
        }
        break;
        case(392):{
        //c'est le role de la transaction de router un message vers un canal particulier
        //si le channel est -1 alors evaluer tr
            _instruParser.parseMessage(sxMess);
//            QVector<WordWriter *> vws = _instruParser.checkWReplacers();
            Instrument i = _instruParser.createInstrument();
            int ch =_instruParser.getChannel();
            if(ch>=0 && ch < 16){
                setInstrument(i,ch);
            }else{
                setInstrument(i,_editedChannel);
            }
        }
        break;
        case(80):{

//        saveRawData("GLBD.txt", sxMess);
        }
        break;
        case(425):
        {
            _multiParser.parseMessage(sxMess);

            _multiParser.getMultiNumber();
            _multiParser.getMultiTempo();
            _multiParser.getMultiVolume();
            for(int i(0);i<16;i++){
                _multiParser.toChannel(_Arrangement->editChannel(i),i);
            }
            emit syncMulti();
        }
        break;
        case(15):{
//        saveRawData("ID1.txt", sxMess);
        }
        break;
        default:
//        try {
//            saveRawData(QString::number(sxMess->at(0))+ "__.txt", sxMess);
//        } catch (...) {
//        }
        break;
    }
    delete sxMess;
}

void BlofeldReplica::importArrangement(){
    for(int i(0);i<16;i++){
        importInstrument(i);
    }
}

void   BlofeldReplica::initReplica()
{
    _connecta = new MIOMgr;

    for (int i(0);i<16;i++){
        Instrument inst = _instruParser.createInstrument();
        _Arrangement->setInstrument(inst,i);
        _multiParser.initChannel(_Arrangement->editChannel(i),i);
    }    
}


void BlofeldReplica::importInstrument(int ch){
    RequestInstrument rqi;
    try {
        _connecta->sendSysex(rqi.getMessage(_id,ch));
        _patienteur.usleep(300000);
    } catch (...) {
        setMidiEnvironment();
    }
}

void BlofeldReplica::importInstrument(int bank,int pgm){
    RequestInstrument rqi;
    try {
        std::vector<uchar> * v = rqi.getMessage(_id,bank,pgm);
        _connecta->sendSysex(v);
    } catch (...) {
        //setMidiEnvironment();
    }
}


#include <QFileDialog>

static void saveRawData(QString fileName, std::vector<uchar> * sx){
    QFile f( "C:/Users/Mac Elli/Desktop/" + fileName + ".syx" );
    f.open( QIODevice::WriteOnly );
    f.write( (char *)sx->data(),sx->size()  );
    f.close();
}


void BlofeldReplica::exportParametre(int chid ,const Parametre * par)
{
    try{
        _connecta->sendSysex(_instruParser.getPMessage(par,_id,chid));

    }catch(...){
        setMidiEnvironment();
    }
}

//method appelee par la vue pour synchroniser l'action (envoyer au device + eventuellement attacher a la propriete)
void BlofeldReplica::syncParametre(int ch, int pid)
{
    try{
//        _Arrangement->setParametre(ch,pid,v);
        exportParametre(ch,getparametre(ch,pid));

    }catch(...){
    }
}
void BlofeldReplica::ChangeEditedChannel(int ch)
{
    if(ch >=0 && ch <16){
        _editedChannel=ch;
    }
}

void BlofeldReplica::MixArrangement(const Arrangement *a)
{
    for(int i(0);i<16;i++){
        _Arrangement->setMultiPars(i,a->getMultiPars(i));
        MixInstrument(a->getInstrument(i),i);
    }
}
void BlofeldReplica::MixInstrument(const Instrument *instr)
{
    MixParametres(instr->getParametres(),_editedChannel);
}

void BlofeldReplica::MixInstrument(const Instrument *instr, int ch)
{
    MixParametres(instr->getParametres(),ch);
}

void BlofeldReplica::MixPropriete(const Propriete * pr )
{
    MixPropriete( pr, _editedChannel);
}
void BlofeldReplica::MixPropriete(const Propriete * pr, int ch )
{
    //Dans ce cas on n'a pas tous les parametres
    //donc en cas de REPLACE il faut initialiser tous les indicateurs de propriété
    editChannel(ch)->PrepareForProp();
    MixParametres( pr->getParametres(), ch);
}

void BlofeldReplica::MixParametres(const QVector<Parametre> * ps, int ch)
{
    foreach(Parametre p, *ps )
    {
        MixParametre(&p,ch);
    }
}

void BlofeldReplica::MixParametre( int ch,int pid, int val)
{
    Parametre *prm = new Parametre(*editChannel(ch)->getParametre(pid));
    prm->setValue(val);
    MixParametre(prm,ch);
}

void BlofeldReplica::MixParametre(const Parametre *pr, int ch)
{
    editChannel(ch)->MixParametre(pr);
    const Parametre *prm = editChannel(ch)->getParametre(pr->getID());
    syncParametre(ch,prm->getID());
}


void BlofeldReplica::setContrainte(int pid, Contrainte * c){
    Parametre * p = editParam(pid);
    p->setContrainte(c);
}

void BlofeldReplica::setInstrument(Instrument  i  ){
    setInstrument(i,_editedChannel);
}
void BlofeldReplica::setInstrument(Instrument i,int ch ){
    _Arrangement->setInstrument(i,ch);
    if(ch == _editedChannel)
    {
        emit(updateInstrument(_Arrangement->getInstrument(ch)));
    }
    _instruParser.setInstrument(_Arrangement->editInstrument(ch));
    //reemission apres eventuel modification dues aux proprietes
    try{
        _connecta->sendSysex(_instruParser.getMessage(_id,ch));
    } catch (std::runtime_error & e) {
        setMidiEnvironment();
    }
}


QStringList BlofeldReplica::getParamNames()
{
    QStringList ret;
    QVector<ParametreCom*> ps =_instruParser.getParams();
    for(int i(0);i<ps.count();i++){
        const QString * s0 =ps.at(i)->getNom();
        QString s = QString("%1-")
                .arg(ps.at(i)->getId());
        s.append(QString::fromStdString(s0->toStdString()));
        ret.append(s);
    }
    return ret;
}


void BlofeldReplica::multiRequest(int num)
{
    std::vector<uchar> *v= _multiRequest.getMessage(_id,num);
    _connecta->sendSysex(v);
}

void BlofeldReplica::multiSend(int num)
{
    std::vector<uchar> *v= _multiParser.getMessage(_id,num);
    _connecta->sendSysex(v);
}


void BlofeldReplica::sendTable(const BlofeldWaveTableModel *table, int wtnum, QString wtName)
{
    //actualisation du modele
//    _waveTables.setTable(wtnum-WT_START,table);

    for (int cnt(0);cnt<table->countWaves();cnt++)
    {
        const SignalReal *s = table->getSignal(cnt);
        _waveTableSender.setMessage(s);
        _waveTableSender.setEmbeddedName(wtName);
        std::vector<uchar> *v =_waveTableSender.getMessage(_id,wtnum,cnt);
        _connecta->sendSysex(v);
    }
}
