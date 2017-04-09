#ifndef WTMODEL_H
#define WTMODEL_H


#include <QFile>
#include <QSettings>
#include "wtDrawer_LIB/blofeldwavetablemgrmodel.h"
#include "defs.h"
#include "BlofeldMgr/blofeldreplica.h"

class WTModel
        :public EntityDAO<BlofeldWaveTableMgrModel>
{
    Q_OBJECT
    BlofeldWaveTableMgrModel *_edited;
public:
    WTModel( BlofeldWaveTableMgrModel *edited);
    void ajouter(QString nom );
private:

 };
#endif // WTMODEL_H
