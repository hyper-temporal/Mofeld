#ifndef PROPRIETEMODEL_H
#define PROPRIETEMODEL_H


#include <QFile>
#include <QSettings>
#include "entitydao.h"
#include "propriete.h"
#include "parametre.h"
#include "blofeldreplica.h"

class ProprieteModel
        : public EntityDAO<Propriete>
{
    Q_OBJECT
    BlofeldReplica *_synth;

public:
    ProprieteModel(BlofeldReplica * r);
    void ajouter(QString nom );
private:
//    QStringList GetTags(Propriete a);
 };



#endif // PROPRIETEMODEL_H
