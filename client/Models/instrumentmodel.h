#ifndef INSTRUMENTMODEL_H
#define INSTRUMENTMODEL_H


#include <QAbstractTableModel>
#include "BlofeldMgr/instrument.h"
#include "BlofeldMgr/blofeldreplica.h"

class InstrumentModel :
        public EntityDAO<Instrument>
{
    Q_OBJECT
    BlofeldReplica *_synth;

public:
    InstrumentModel(BlofeldReplica *r);
    void ajouter(QString nom );
private:
 };



#endif // INSTRUMENTMODEL_H
