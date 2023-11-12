#ifndef MESSAGESYSEX_H
#define MESSAGESYSEX_H

#include "messagewriter.h"

class Sysexable
        : public MessageWriter
{
public:
    Sysexable(const int s);
    virtual void parseMessage(std::vector<uchar> * input);
    std::vector<uchar> * writeMessage();

protected:
    void  sysexEndCheck();

};

#endif // MESSAGESYSEX_H
