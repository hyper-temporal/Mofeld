#include "mwavetableeditor.h"

MWaveTableEditor::MWaveTableEditor(BlofeldWaveTableMgrModel *bwte,QWidget *par)
    :QWidget(par),_globalView(bwte->editTable(0))

{
}
