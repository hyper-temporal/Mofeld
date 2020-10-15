#include "miomgr.h"

//MIOMgr::MIOMgr(QObject * par)
//    :QThread(par)
MIOMgr::MIOMgr()
{
    minput=new MinMgr(this);
    moutput=new MoutMgr();
}
void MIOMgr::setMidiInput(QString inputName){
    RtMidiIn tempin;
    for(unsigned int i=0;i<tempin.getPortCount();i++){
        QString s = QString::fromStdString(tempin.getPortName(i));
        //if(s==inputName)
        if( s.contains(inputName,Qt::CaseInsensitive)){
            setMidiInput(i);
            break;
        }
    }
}
void MIOMgr::setMidiOutput(QString outputName){
    RtMidiOut tempOut;
    for(unsigned int i=0;i<tempOut.getPortCount();i++){
        QString s = QString::fromStdString(tempOut.getPortName(i));

//        if(QString::fromStdString(tempOut.getPortName(i))==outputName)
        if( s.contains(outputName,Qt::CaseInsensitive)){
            setMidiOutput(i);
            break;
        }
    }
}


void MIOMgr::setMidiInput(int inputNum)
{

    try{
        minput->ChangeInput(inputNum);
    }
    catch(const std::runtime_error & e){
        //throw std::runtime_error("erreur peripherique midi");
    }
}
void MIOMgr::setMidiOutput(int outputNum)
{
    try{
            moutput->ChangeOutpput(outputNum);
    }
    catch(const std::runtime_error & e)
    {
        //throw std::runtime_error("erreur peripherique midi");
    }
}




void MIOMgr::sendSysex(std::vector<uchar> * syx)
{
    try{
        moutput->sendMessage(syx);
    }
    catch (const std::exception & e) {
        throw std::runtime_error("Le message n'a pas été envoyé");
    }
}



void MIOMgr::ReceiveSysex(std::vector< uchar > * input){

    unsigned int nBytes = input->size();
    std::vector< uchar > * v  = new std::vector< uchar >;
    for( unsigned int i=0; i<nBytes;i++)
    {
        v->push_back( input->at(i));
    }
    emit SysexChanged(v);
}


void MinMgr::mycallback( double deltatime, std::vector< uchar > * message, void *userData )
{
    unsigned int nBytes = message->size();

    if ( nBytes > 0 )
    {
        MIOMgr * temp = (MIOMgr*)userData;
        temp->ReceiveSysex(message);
    }
}

MinMgr::MinMgr( MIOMgr * pnt ):RtMidiIn()
{
    ignoreTypes( false, false, false );
    setCallback( mycallback,(void*)pnt );
}

void MinMgr::ChangeInput(int portnum )
{
    try{
        closePort();
        openPort(portnum);
    }
    catch(const std::exception & e)
    {
        throw std::runtime_error("erreur peripherique midi");
    }
}

MoutMgr::MoutMgr( ):RtMidiOut()
{
}

void MoutMgr::ChangeOutpput(int portnum )
{
    try{
        closePort();
        openPort(portnum);
    }
    catch(const std::runtime_error & e)
    {
        throw std::runtime_error("erreur peripherique midi");
    }
}
