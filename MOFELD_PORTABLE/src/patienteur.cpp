#include "patienteur.h"
Patienteur::Patienteur()
{
}

void Patienteur::usleep(unsigned long time){

    QThread::usleep(time);
}
