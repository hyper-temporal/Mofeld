#include "transaction.h"

Transaction::Transaction(MIOMgr * mid,Sysexable* m1,Sysexable* m2)
{
    _dump = m2;
    mid->sendSysex(m1->writeMessage());
    //Doit declencher un compteur au bout duquel on annule la transaction
}

void Transaction::NewMessageReceived(std::vector< uchar > * m){

    _dump->parseMessage(m);

}
