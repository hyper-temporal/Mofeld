#ifndef PROPRIETEMODEL_H
#define PROPRIETEMODEL_H


#include <QFile>
#include <QSettings>
#include "entitydao.h"
#include "propriete.h"
#include "parametre.h"
#include "targetprovider.h"


class ProprieteModel
        : public EntityDAO<Propriete>
{
    Q_OBJECT
    TargetProvider *_synth;

public:
    ProprieteModel(TargetProvider * r);
    void ajouter(QString nom );
private:
//    QStringList GetTags(Propriete a);
 };



#endif // PROPRIETEMODEL_H
