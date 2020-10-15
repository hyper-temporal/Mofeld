#ifndef BLOXSIGNAL_H
#define BLOXSIGNAL_H

#include "blofable.h"


#include "SignalProc/bufferspec.h"
#include "wtDrawer_LIB/blofeldwavetablemodel.h"

//TO DO : trouver comment remplacer le mecanisme d'heritage a la compilation
// pour un autre mecanisme avec une seule classe qui construit des objets configurable au runtime
//et dans lequel on injecte des dependances dynamiquement: presentation de l'interface a
//le fait de pouvoir emmetre sa structure au sein d'un message avec une adresse de destination vers un objet connu communicant
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
