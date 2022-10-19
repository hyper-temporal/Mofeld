#ifndef PATIENTEUR_H
#define PATIENTEUR_H

#include <QThread>


class Patienteur : QThread
{
public:
    Patienteur();

    static void usleep(unsigned long time);


};

#endif // PATIENTEUR_H
