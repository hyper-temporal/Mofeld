#ifndef ARRANGEMENTMODEL_H
#define ARRANGEMENTMODEL_H

#include <QFile>
#include <QSettings>
#include "arrangement.h"
#include "targetprovider.h"
#include <defs.h>

class ArrangementModel
        :public EntityDAO<Arrangement>
{
    Q_OBJECT

    TargetProvider *_synth;
public:
    ArrangementModel(TargetProvider *r);
    void ajouter(QString nom );
private:

 };




#endif // ARRANGEMENTMODEL_H
