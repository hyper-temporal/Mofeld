#ifndef INSTRUMENTMODEL_H
#define INSTRUMENTMODEL_H


#include <QAbstractTableModel>
#include "instrument.h"
#include "targetprovider.h"

class InstrumentModel :
        public EntityDAO<Instrument>
{
    Q_OBJECT
    TargetProvider *_synth;

public:
    InstrumentModel(TargetProvider *r);
    void ajouter(QString nom );
private:
 };



#endif // INSTRUMENTMODEL_H
