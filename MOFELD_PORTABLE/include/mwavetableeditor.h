#ifndef MWAVETABLEEDITOR_H
#define MWAVETABLEEDITOR_H

#include "blofeldwavetablemgrmodel.h"
#include "uiwavetablemgrvue.h"
#include "msoundprintervue.h"

class MWaveTableEditor
        :public  QWidget
{

    Q_OBJECT

    UIWaveTableMgrVue _detailView;
    MSoundPrinterVue _globalView;
public:
    MWaveTableEditor(BlofeldWaveTableMgrModel *bwte, QWidget *par);
    QWidget *getDetail(){return &_detailView;}
    QWidget *getGlobal(){return &_globalView;}
};

#endif // MWAVETABLEEDITOR_H
