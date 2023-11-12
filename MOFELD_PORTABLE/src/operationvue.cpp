#include "operationvue.h"


OperationVue::OperationVue(OperationModel *opMod,
        QWidget * parent,
        std::vector<std::pair<QString, int> > &bids):
    QWidget(parent),_model(opMod)
{

    SetCbbBlofeldIds(bids);
    le_instrumentName = new  QLineEdit;

    SetCbbChannel();
    SetCbbBank();
    SetCbbProgram();

    _layout  = new QHBoxLayout;

    QHBoxLayout *lySelectCh  = new QHBoxLayout;
    lySelectCh->addWidget(cbb_bids);
    lySelectCh->addWidget(cbb_channel);
    lySelectCh->addWidget(cbb_Bank);
    lySelectCh->addWidget(cbb_Program);
    lySelectCh->addWidget(le_instrumentName);

    QVBoxLayout *lyCommon  = new QVBoxLayout;
    lyCommon->addLayout(lySelectCh);
    gb_GlobalCtrl = new QGroupBox("Global");
    gb_GlobalCtrl->setLayout(lyCommon);

    _layout->addWidget(gb_GlobalCtrl);
    _layout->setSpacing(1);
    _layout->setContentsMargins(1,0,0,0);

    setLayout(_layout);
    connect(cbb_bids,SIGNAL(currentIndexChanged(int))
            ,parent,SLOT(setSynthId(int)));

    connect (le_instrumentName,SIGNAL(textChanged(QString)),
             parent,SLOT(SetInstrumentName(QString)));
    connect(cbb_channel,SIGNAL(currentIndexChanged(int)),
            parent,SLOT(UpdateChannel(int)));
    connect(this,SIGNAL(importInstrument(int,int)),
            parent,SLOT(ImportInstrument(int,int)));
//    connect(pb_reImport,SIGNAL(clicked()),
//            parent,SLOT(Reimport()));
//    connect(pb_reGenerate,SIGNAL(clicked()),
//            parent,SLOT(ReGenerate()));

    connect(cbb_Bank,SIGNAL(currentIndexChanged(int)),
            this,SLOT(on_cbBank_currentIndexChanged(int)));
    connect(cbb_Program,SIGNAL(currentIndexChanged(int)),
            this,SLOT(on_cbPrgm_currentIndexChanged(int)));
}

OperationVue::~OperationVue(){
    delete cbb_channel;
    delete cbb_Bank;
    delete cbb_Program;
    delete cbb_bids;
}
void OperationVue::SetCbbBlofeldIds(std::vector<std::pair<QString,int>> &ids){
    cbb_bids = new QComboBox(this);
    disconnect(cbb_bids,SIGNAL(currentIndexChanged(int)),0,0);
    for(auto id : ids){
        cbb_bids->addItem(std::get<0>(id),std::get<1>(id));
    }
}
void OperationVue::SetCbbChannel(){
    cbb_channel = new QComboBox(this);
    disconnect(cbb_channel,SIGNAL(currentIndexChanged(int)),0,0);
    cbb_channel->setModel( new ComboTool( BlofeldTypesEnum::getInstance().GetEnum(BLOT_CHANNEL)));
}

void OperationVue::SetCbbBank(){
    cbb_Bank = new QComboBox(this);
    disconnect(cbb_Bank,SIGNAL(currentIndexChanged(int)),0,0);
    cbb_Bank->setModel( new ComboTool( BlofeldTypesEnum::getInstance().GetEnum(BLOT_BANK)));
}

void OperationVue::SetCbbProgram(){

    cbb_Program = new QComboBox(this);
    disconnect(cbb_Program,SIGNAL(currentIndexChanged(int)),0,0);
    cbb_Program->setModel( new ComboTool( BlofeldTypesEnum::getInstance().GetEnum(BLOT_STANDARD)));
}


void OperationVue::on_cbBank_currentIndexChanged(int index)
{
    emit importInstrument(index,cbb_Program->currentIndex());
}


void OperationVue::on_cbPrgm_currentIndexChanged(int index)
{
    emit importInstrument(cbb_Bank->currentIndex(),index);
}

