#include "blofeldreplica.h"
#include "targetprovider.h"
#include "requestinstrument.h"
#include "requestglobal.h"
#include <QFileDialog>

static void saveRawData(QString fileName, std::vector<uchar> * sx){
    QFile f( "./" + fileName + ".syx" );
    f.open( QIODevice::WriteOnly );

    f.write( (char *)sx->data(),sx->size()  );
    f.close();
}

BlofeldReplica::BlofeldReplica(
        IBlofeldView* view,
        IMidiIn *min,
        IMidiOut *mout,
        int id)
    : _view(view)
    ,_id(id)
    ,_min(min)
    ,_mout(mout)
{
    _min->openPort(this);
    _mout->openPort();

    _editedChannel = 0;
    initReplica();
}

BlofeldReplica::BlofeldReplica(const BlofeldReplica& o)
    :BlofeldReplica(o._view, o._min,o._mout, o._id)
{}

BlofeldReplica::BlofeldReplica(const BlofeldReplica&& o)
    :BlofeldReplica(o._view, o._min,o._mout, o._id)
{}



BlofeldReplica::~BlofeldReplica()
{
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
        _view->updateView(getInstrument(ch));
    }
}

void BlofeldReplica::setInstrumentName(QString s )
{
    _instruParser.setEmbeddedName(s);
    for(int i(0);i<16;i++){
        ParametreCom *p= _instruParser.getParam(341 +i);
        std::vector<uchar> * vec = p->getMessage(_id,_editedChannel);
        _mout->send(vec);
    }
}
void BlofeldReplica::sendSysex(std::vector<uchar> message){
    _mout->send(&message);

}

void BlofeldReplica::sendSysexFromFile(QString path){
    QFile filea(path);
    if(filea.open(QIODevice::ReadOnly)){
        QByteArray ba;
        QDataStream ds(&ba, QIODevice::ReadWrite);
        ds << filea.readAll();

        std::vector<unsigned char> v(
            ba.begin(), ba.end());
        _mout->send(&v);
    }
}

void BlofeldReplica::receive(std::vector< uchar > * sxMess)
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
//                if(p->getChannel() == _editedChannel)
//                {
//                    const Parametre * par = _Arrangement.getParametre(p->getChannel(),p->getId());
//                    _view->updateView(par);
//                }
            }
        }
        break;
        case(392):{
            _instruParser.parseMessage(sxMess);
//            QVector<WordWriter *> vws = _instruParser.checkWReplacers();
            Instrument i = _instruParser.createInstrument();
            const auto  props = *(getProprieteChannel());
            auto  mixprops = getPropAppliance();

            i.updateParametres(props.getParametres(), mixprops);

            int ch =_instruParser.getChannel();
            if(ch>=0 && ch < 16){
                setInstrument(i,ch);
            }else{
                setInstrument(i,_editedChannel);
            }
        }
        break;
        case(80):{

//            _patienteur.usleep(300000);
        }
        break;
        case(425):
        {
            _multiParser.parseMessage(sxMess);

            _multiParser.getMultiNumber();
            _multiParser.getMultiTempo();
            _multiParser.getMultiVolume();
            for(int i(0);i<16;i++){
                _multiParser.toChannel(_Arrangement.editChannel(i),i);
            }
//            _view->updateMulti();
        }
        break;
        case(15):{
//        saveRawData("ID1.txt", sxMess);
        }
        break;
        default:
//            saveRawData(QString::number(sxMess->at(0))+ "__.txt", sxMess);

        break;
    }
}

void BlofeldReplica::importArrangement(){
    for(int i(0);i<16;i++){
        importInstrument(i);
    }
}

void   BlofeldReplica::initReplica()
{

    /*

    0 ___ "MULTI SWITCH" ___ 0
    1 ___ "BANK" ___ 0
    2 ___ "PRGM" ___ 98
    3 ___ "BANK" ___ 0
    4 ___ "PRGM" ___ 0
    5 ___ "BANK" ___ 0
    6 ___ "PRGM" ___ 0
    7 ___ "BANK" ___ 0
    8 ___ "PRGM" ___ 0
    9 ___ "BANK" ___ 0
    10 ___ "PRGM" ___ 0
    11 ___ "BANK" ___ 0
    12 ___ "PRGM" ___ 0
    13 ___ "BANK" ___ 0
    14 ___ "PRGM" ___ 0
    15 ___ "BANK" ___ 0
    16 ___ "PRGM" ___ 0
    17 ___ "BANK" ___ 0
    18 ___ "PRGM" ___ 0
    19 ___ "BANK" ___ 0
    20 ___ "PRGM" ___ 0
    21 ___ "BANK" ___ 0
    22 ___ "PRGM" ___ 0
    23 ___ "BANK" ___ 0
    24 ___ "PRGM" ___ 0
    25 ___ "BANK" ___ 0
    26 ___ "PRGM" ___ 0
    27 ___ "BANK" ___ 0
    28 ___ "PRGM" ___ 0
    29 ___ "BANK" ___ 0
    30 ___ "PRGM" ___ 0
    31 ___ "BANK" ___ 0
    32 ___ "PRGM" ___ 0
    33 ___ "Auto Edit" ___ 0
    34 ___ "Midi Channel" ___ 0
    35 ___ "Device ID" ___ 0
    36 ___ "Popup Time  " ___ 0
    37 ___ "Contrast    " ___ 0
    38 ___ "Master Tune " ___ 52
    39 ___ "Transpose   " ___ 52
    40 ___ "Ctrl Send   " ___ 0
    41 ___ "Ctrl Receive" ___ 0
    42 ___ "Clock       " ___ 0
    43 ___ "Vel Curve   " ___ 0
    44 ___ "Control W   " ___ 0
    45 ___ "Control X   " ___ 0
    46 ___ "Control Y   " ___ 0
    47 ___ "Control Z   " ___ 0
    48 ___ "Volume      " ___ 127
    49 ___ "Cat. Filter " ___ 0
    */
    _globalParser.debug();
    _globalParser.setParamValue(0,0);
    _globalParser.setParamValue(34,1);
    _globalParser.setParamValue(38,52);
    _globalParser.setParamValue(48,127);
    _globalParser.setParamValue(39,64);
    std::vector<uchar> messm = *_globalParser.getMessage(0);
    _mout->send(&messm);

    for (int i(0);i<16;i++){
        Instrument inst = _instruParser.createInstrument();
        _Arrangement.setInstrument(inst,i);
        _multiParser.initChannel(_Arrangement.editChannel(i),i);
    }    
}


void BlofeldReplica::importInstrument(int ch){
    RequestInstrument rqi;
    _mout->send(rqi.getMessage(_id,ch));
    _patienteur.usleep(300000);

}

void BlofeldReplica::importInstrument(int bank,int pgm){
    RequestInstrument rqi;
    std::vector<uchar> * v = rqi.getMessage(_id,bank,pgm);
    _mout->send(v);
    _patienteur.usleep(300000);

}



void BlofeldReplica::exportParametre(int chid ,const Parametre * par)
{
    _mout->send(_instruParser.getPMessage(par,_id,chid));
}

//method appelee par la vue pour synchroniser l'action (envoyer au device + eventuellement attacher a la propriete)
void BlofeldReplica::syncParametre(int ch, int pid)
{
    exportParametre(ch,getparametre(ch,pid));
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
        _Arrangement.setMultiPars(i,a->getMultiPars(i));
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
//    editChannel(ch)->PrepareForProp();
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
    if(ch == _editedChannel)
    {
        _view->updateView(prm);
    }
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
    _Arrangement.setInstrument(i,ch);
    if(ch == _editedChannel)
    {
        _view->updateView(_Arrangement.getInstrument(ch));
    }
    _instruParser.setInstrument(_Arrangement.editInstrument(ch));
    _mout->send(_instruParser.getMessage(_id,ch));

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
    auto v= _multiRequest.getMessage(_id,num);
    _mout->send(v);
}

void BlofeldReplica::multiSend(int num)
{
    auto v= _multiParser.getMessage(_id,num);
    _mout->send(v);
}



void BlofeldReplica::sendTable(const BlofeldWaveTableModel *table, int wtnum, QString wtName)
{
//      actualisation du modele
//      _waveTables.setTable(wtnum-WT_START,table);

    for (int cnt(0); cnt<table->countWaves(); cnt++)
    {
        const SignalReal *s = table->getSignal(cnt);
        _waveTableSender.setMessage(s);
        _waveTableSender.setEmbeddedName(wtName);
        auto v =_waveTableSender.getMessage(_id,wtnum,cnt);
        _mout->send(v);
    }
}

void BlofeldReplica::sendAllTables(const QVector<BlofeldWaveTableModel>  * tables)
{
    uint tn = 0;
    for(auto & t : *tables){
        auto name = QString("Usr WT%2").arg(tn++);
        sendTable(&t,tn + WT_START, name);
        QThread::usleep(300000);
    }
}

void BlofeldReplica::importGlobal()
{
    RequestGlobal rqg;
    auto pmessage = rqg.getMessage(_id);
    _mout->send(pmessage);
    _patienteur.usleep(300000);

}
