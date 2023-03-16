#ifndef MIOMGR_H
#define MIOMGR_H

#include <stdexcept>


#include <QString>
#include <RtMidi.h>

class MIOMgr;


class MidiReceiver{
public:
    virtual void receive(std::vector<unsigned char> *message)=0;
};

class IMidiIn{
public:
    virtual ~IMidiIn() = default;
    virtual void openPort(MidiReceiver *)=0;
};


class IMidiOut{
public:
    virtual ~IMidiOut() = default;
    virtual void send(const std::vector<unsigned char> *message)=0;
    virtual void openPort()=0;
};

class MockIn : public IMidiIn
{
public:
    void openPort(MidiReceiver *){}
};


class MockOut : public IMidiOut{
public:
    void send(const std::vector<unsigned char> *message)     {}
     void openPort(){}
};



class Minput final
        :public IMidiIn
{
    int _port;
    RtMidiIn _api;
    MidiReceiver * _receiver;
public:
    Minput( int port=-1);
    Minput(const Minput& o);
    Minput(const Minput&& o);
    ~Minput();
    void openPort(MidiReceiver *mr)final;
    void reopenPort();
    void closePort();
private:
    static void mycallback( double deltatime, std::vector<unsigned char> *message, void *userData );
};


class Moutput final
        :public IMidiOut
{
    int _port;
    std::string _name;
    RtMidiOut _api;
public:
    Moutput(const Moutput& o);
    Moutput(const Moutput&& o);
    Moutput(int port=-1);
    ~Moutput();
    void send(const std::vector<unsigned char> *);
    void openPort()final;
private:

};
class MIOMgr
{
private:
    std::vector<unsigned char> SysexMessage;
    std::vector<IMidiIn*>  minputs;
    std::vector<IMidiOut*>  moutputs;

public:
    MIOMgr();
    ~MIOMgr();
    std::vector<std::pair<QString,int>> getPortsIn(std::string name );
    std::vector<std::pair<QString,int>> getPortsOut(std::string name );
    IMidiIn *getinput(int id){ return minputs[id];}
    IMidiOut *getoutput(int id){return moutputs[id];}
    IMidiIn *getMockIn(){  minputs.push_back(new MockIn()); return minputs.back();}
    IMidiOut *getMockOut(){ moutputs.push_back(new MockOut()); return moutputs.back();}

    void sendSysex(std::vector< unsigned char > * syx);
    void receive(std::vector< unsigned char > * input);
    void writeMessage(QString path,std::vector< unsigned char > * content);
    std::vector< unsigned char > * readMessage(QString path);
};


#endif // MIOMGR_H
