#ifndef TRANSACTION_H
#define TRANSACTION_H


#include "Midi/miomgr.h"
#include "sysexable.h"
#include "Time/patienteur.h"

class Transaction:QObject
{
    Q_OBJECT

    MIOMgr * _midimag;
    Sysexable * _request;
    Sysexable * _dump;
public:
    Transaction(MIOMgr * mid,Sysexable* m1,Sysexable* m2);
public slots:
    void NewMessageReceived(std::vector< uchar > *);
};

#endif // TRANSACTION_H
