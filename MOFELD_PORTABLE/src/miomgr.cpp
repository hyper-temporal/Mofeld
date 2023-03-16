#include "miomgr.h"



MIOMgr::MIOMgr()
{
    RtMidiIn mis ;
    for(int i = 0; i< mis.getPortCount(); ++i){
        minputs.push_back(new Minput(i));
    }
    RtMidiOut mos ;
    for(int i = 0; i< mos.getPortCount(); ++i){
        moutputs.push_back(new Moutput(i));
    }
}

MIOMgr::~MIOMgr(){
    for(auto d : minputs){
        delete d;
    }
    for(auto d : moutputs){
        delete d;
    }
    moutputs.clear();
    minputs.clear();
}


std::vector<std::pair<QString,int>> MIOMgr::getPortsIn(std::string name ){
    RtMidiIn tempin;
    std::vector<std::pair<QString,int>> ret;
    ret.reserve(tempin.getPortCount());
    auto qstr = QString::fromStdString(name);
    for(unsigned int i=0;i<tempin.getPortCount();i++){
        auto pstr = QString::fromStdString(tempin.getPortName(i));
        if(pstr.contains(qstr,Qt::CaseInsensitive)){
            ret.push_back({pstr,i});
        }
    }
    return ret;
}

std::vector<std::pair<QString,int>> MIOMgr::getPortsOut(std::string name ){
    RtMidiOut tempout;
    std::vector<std::pair<QString,int>> ret;
    ret.reserve(tempout.getPortCount());
    auto qstr = QString::fromStdString(name);
    for(unsigned int i=0;i<tempout.getPortCount();i++){
        auto pstr = QString::fromStdString(tempout.getPortName(i));
        if(pstr.contains(qstr,Qt::CaseInsensitive)){
            ret.push_back({pstr,i});
        }
    }
    return ret;
}




void Minput::mycallback( double deltatime, std::vector< uchar > * message, void *userData )
{
    unsigned int nBytes = message->size();

    if ( nBytes > 0 )
    {
        MidiReceiver * temp = (MidiReceiver*)userData;
        temp->receive(message);
    }
}

Minput::Minput(  int port )
    :_port(port)
{
}


Minput::Minput(const Minput &&o )
    :Minput(o._port)
{
}

Minput::Minput( const Minput& o )
    :Minput(o._port)
{
}

Minput::~Minput()
{
    closePort();
}

void Minput::openPort( MidiReceiver * pnt)
{
    _receiver = pnt;
    reopenPort();

}
void Minput::reopenPort()
{
    try {
        closePort();
        _api.openPort(_port);
        _api.ignoreTypes( false, true, true );
        _api.setCallback( mycallback,(void*)_receiver );
    } catch (...) {
        std::cerr << "input couldn' t be opened check if another app is using it" << std::endl;
    }

}

void Minput::closePort( )
{
    if(_api.isPortOpen()){
        _api.cancelCallback();
        _api.closePort();
    }
}



Moutput::Moutput( int port)
    :_port(port)
{

}
Moutput::~Moutput()
{
    if(_api.isPortOpen()){
        _api.closePort();
    }
}
void Moutput::send(const std::vector<uchar> *v ){
    _api.sendMessage(v);
}

void Moutput::openPort(){
    try {
        if(_api.isPortOpen()){
            _api.closePort();
        }
        _api.openPort(_port);
    }catch (...) {
        std::cerr << "MIDI output couldn' t be opened! check if another app is using it" << std::endl;
    }
}

Moutput::Moutput(const Moutput&& o )
    :Moutput(o._port)
{
}

Moutput::Moutput(const Moutput& o )
    :Moutput(o._port)
{
}
