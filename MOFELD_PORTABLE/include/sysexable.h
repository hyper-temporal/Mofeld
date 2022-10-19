#ifndef MESSAGESYSEX_H
#define MESSAGESYSEX_H

#include "messagewriter.h"
//classe capable de parser un blob pour delivrer des objets a la charge de parametres
//Le lien entre l'instrument et le parametre se constitue ainsi:
/*
    l'instanciation d'un dumpinstrument provoque l'instanciation de n parametreCom qui partage le ww avec le dumpinstrument
*/
class Sysexable: public MessageWriter
{
public:
    Sysexable(const int s);
    virtual void parseMessage(std::vector<uchar> * input);
    std::vector<uchar> * writeMessage();

protected:
    void  sysexEndCheck();
private:
     virtual void setDataContent()=0;
};

#endif // MESSAGESYSEX_H
