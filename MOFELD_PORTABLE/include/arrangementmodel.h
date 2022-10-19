#ifndef ARRANGEMENTMODEL_H
#define ARRANGEMENTMODEL_H

#include <QFile>
#include <QSettings>
#include "arrangement.h"
#include "blofeldreplica.h"
#include <defs.h>

class ArrangementModel
        :public EntityDAO<Arrangement>
{
    Q_OBJECT

    BlofeldReplica *_synth;
public:
    ArrangementModel(BlofeldReplica *r);
    void ajouter(QString nom );
private:

 };




#endif // ARRANGEMENTMODEL_H
