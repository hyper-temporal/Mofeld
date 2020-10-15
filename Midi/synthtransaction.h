#ifndef SYNTHTRANSACTION_H
#define SYNTHTRANSACTION_H

#include "miomgr.h"
#include "Messaging/messagewriter.h"
class SynthTransaction
{
    MessageWriter * _request;
    MessageWriter * _reponse;
    int _timeLeft;
public:
    SynthTransaction();
};

// la taille du message recu est comparé a la taille des mots attendus (equivalent du switch sur la taille)
//  si la taille correspond le message est parsé
//  si pas Exception alors la structure est envoyé au sender
//  si pas de sender la structure est adressé par la methode d'adressage de la transaction
//  message de parametre: transaction permanente, methode d'adressage particuliere
//  message instrument: transaction initiée pour le canal d'un device particulier
//  le message correspondant a une position dans une banque doit avoir un sender
/*
    la transaction fait intervenir un envoi de requete + dump retour compatible
    lorsqu'on emet la requete on sait a qui on veut adresser le retour, on peut donc indiquer le sender qui recevra le dump valide

*/
/*
    SENDER : pointeur vers une structure equivalente a la structure extraite et possedan une methode receive ()
    types de sender:
        -   rqINSTRUMENT + channel,
        -   rqGLOBAL + device,
*/
/*
    gestion du temps :
    on a un thread permanent qui toutes les n ms vient decrementer le temps des transactions en cours
    si une transaction non permanente est arrivée a expirtation elle est annulee

*/
#endif // SYNTHTRANSACTION_H
