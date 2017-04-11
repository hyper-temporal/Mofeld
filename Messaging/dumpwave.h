#ifndef BLOXSIGNAL_H
#define BLOXSIGNAL_H

#include "blofable.h"


#include "SignalProc/bufferspec.h"
#include "wtDrawer_LIB/blofeldwavetablemodel.h"

class DumpWave:public BufferSpec,public Blofable
{
public:
    DumpWave();
    void setMessage(const SignalReal *sr);
    std::vector<uchar> *getMessage(int macid, int tableid, int waveid);
    void  setEmbeddedName(QString name);

private:
    void setAdressContent();
    void setDataContent();
    void setChecksum();
};


#endif // BLOXSIGNAL_H
