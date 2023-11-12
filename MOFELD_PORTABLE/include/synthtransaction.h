#ifndef SYNTHTRANSACTION_H
#define SYNTHTRANSACTION_H

#include "miomgr.h"
#include "messagewriter.h"
class SynthTransaction
{
    MessageWriter * _request;
    MessageWriter * _reponse;
    int _timeLeft;
public:
    SynthTransaction();
};

#endif // SYNTHTRANSACTION_H
