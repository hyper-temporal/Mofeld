#ifndef MIOMGR_H
#define MIOMGR_H

#include <stdexcept>

#include <QTime>
#include <QThread>
#include <RtMidi.h>

class MinMgr;
class MoutMgr;

class MIOMgr
    : public QObject
{
    Q_OBJECT
private:
    std::vector<uchar> SysexMessage;
    MinMgr * minput;
    MoutMgr * moutput;
public:
    MIOMgr();
    void setMidiInput(QString inputName);
    void setMidiOutput(QString outputName);
    void setMidiInput(int inputNum);
    void setMidiOutput(int outputNum);

    void sendSysex(std::vector< uchar > * syx);

    void ReceiveSysex(std::vector< uchar > * input);

    void writeMessage(QString path,std::vector< uchar > * content);
    std::vector< uchar > * readMessage(QString path);
signals:
    void SysexChanged(std::vector< uchar > * sxMess );
protected:
//    void run(void);
};


class MinMgr
        : public RtMidiIn
{
public:
    MinMgr( MIOMgr * pnt);
    void ChangeInput(int portnum );
private:
    static void mycallback( double deltatime, std::vector<uchar> *message, void *userData );
};


class MoutMgr
        : public RtMidiOut
{
public:
    MoutMgr();
    void ChangeOutpput(int portnum );
private:

};
#endif // MIOMGR_H
