#ifndef ARRANGEMENTMODEL_H
#define ARRANGEMENTMODEL_H

#include <QFile>
#include <QSettings>
#include "BlofeldMgr/arrangement.h"
#include "BlofeldMgr/blofeldreplica.h"
#include "defs.h"

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
