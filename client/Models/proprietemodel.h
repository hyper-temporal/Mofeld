#ifndef PROPRIETEMODEL_H
#define PROPRIETEMODEL_H


#include <QFile>
#include <QSettings>
#include "genericity/entitydao.h"
#include "BlofeldMgr/propriete.h"
#include "BlofeldMgr/parametre.h"
#include "BlofeldMgr/blofeldreplica.h"

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
