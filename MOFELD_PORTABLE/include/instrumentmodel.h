#ifndef INSTRUMENTMODEL_H
#define INSTRUMENTMODEL_H


#include <QAbstractTableModel>
#include "instrument.h"
#include "blofeldreplica.h"

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
