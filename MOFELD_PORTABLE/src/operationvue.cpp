#include "operationvue.h"
using namespace OperationProps;

OperationVue::OperationVue(OperationModel *opMod,BlofeldReplica *synth,  QWidget * parent):
    QWidget(parent),_model(opMod)
{

    le_instrumentName = new  QLineEdit;
    chb_importProp = new QCheckBox("Propriété");
    chb_importStuff  =new QCheckBox("Stuff");
    chb_importContrainte = new QCheckBox("Contraintes");
    chb_importValues = new QCheckBox("Values");

    rb_force = new QRadioButton("Force");
    rb_replace = new QRadioButton("Replace");
    rb_weak = new QRadioButton("Weak");

    pb_reImport = new QPushButton("Import");
    pb_reGenerate = new QPushButton("Generate");
    pb_sendMultiState = new QPushButton("Multi Tx");

    le_qssPath = new QLineEdit();
    btn_layoutUpdate = new QPushButton("8=<(o_o)>");

//    _contrainteVue = new ContrainteVue(synth,parent);
//    connect(_contrainteVue,SIGNAL(updateProprietes(const Propriete*)),
//            parent,SLOT(updateView(const Propriete*)));

    SetCbbChannel();
    SetCbbBank();
    SetCbbProgram();

    _layout  = new QHBoxLayout;

    QHBoxLayout *lySelectCh  = new QHBoxLayout;
    lySelectCh->addWidget(cbb_channel);
    lySelectCh->addWidget(cbb_Bank);
    lySelectCh->addWidget(cbb_Program);
    lySelectCh->addWidget(le_instrumentName);
    QHBoxLayout *lyActCh  = new QHBoxLayout;
    lyActCh->addWidget(pb_reImport);
    lyActCh->addWidget(pb_reGenerate);
    lyActCh->addWidget(pb_sendMultiState);

    QVBoxLayout *lyCommon  = new QVBoxLayout;
    lyCommon->addLayout(lySelectCh);
    lyCommon->addLayout(lyActCh);
    gb_GlobalCtrl = new QGroupBox("Global");
    gb_GlobalCtrl->setLayout(lyCommon);


//    QSpacerItem* spacer = new QSpacerItem(100,100, QSizePolicy::Preferred, QSizePolicy::Preferred);
//    spacer->setAlignment(Qt::AlignVCenter);


    QHBoxLayout *lyPropAndStuff  = new QHBoxLayout;
    lyPropAndStuff->addWidget(chb_importProp);
    lyPropAndStuff->addWidget(chb_importStuff);
//    lyPropAndStuff->addSpacerItem(spacer);
    lyPropAndStuff->addWidget(chb_importContrainte);
    lyPropAndStuff->addWidget(chb_importValues);

    gb_PropAndStuff = new QGroupBox("Overwrite Flags");
    gb_PropAndStuff->setLayout(lyPropAndStuff);


    QHBoxLayout *lyMethod1 = new QHBoxLayout;
    lyMethod1->addWidget(rb_force);
    lyMethod1->addWidget(rb_replace);
    lyMethod1->addWidget(rb_weak);
    gb_PropertyMethod_ch = new QGroupBox("Modif Channel");
    gb_PropertyMethod_ch->setLayout(lyMethod1);

    QVBoxLayout *lyAuthorize  = new QVBoxLayout;
    lyAuthorize->addWidget(gb_PropAndStuff);
    lyAuthorize->addWidget(gb_PropertyMethod_ch);

    QHBoxLayout *lyStyle = new QHBoxLayout;
    lyStyle->addWidget(btn_layoutUpdate);
    lyStyle->addWidget(le_qssPath);

    _layout->addWidget(gb_GlobalCtrl);
    _layout->addLayout(lyAuthorize);
//    _layout->addWidget(_contrainteVue);
    _layout->addLayout(lyStyle);

    _layout->setSpacing(1);
    _layout->setContentsMargins(1,0,0,0);

    setLayout(_layout);

    connect (le_instrumentName,SIGNAL(textChanged(QString)),parent,SLOT(SetInstrumentName(QString)));
    connect(cbb_channel,SIGNAL(currentIndexChanged(int)),parent,SLOT(UpdateChannel(int)));
    connect(this,SIGNAL(importInstrument(int,int)),parent,SLOT(ImportInstrument(int,int)));
    connect(pb_reImport,SIGNAL(clicked()),parent,SLOT(Reimport()));
    connect(pb_reGenerate,SIGNAL(clicked()),parent,SLOT(ReGenerate()));
    connect(this,SIGNAL(updateStyle(QString)),parent,SIGNAL(updateStyle(QString)));
    connect(btn_layoutUpdate,SIGNAL(clicked()),this,SLOT(on_pbStyle_clicked()));
    connect(cbb_Bank,SIGNAL(currentIndexChanged(int)),this,SLOT(on_cbBank_currentIndexChanged(int)));
    connect(cbb_Program,SIGNAL(currentIndexChanged(int)),this,SLOT(on_cbPrgm_currentIndexChanged(int)));
    connect(rb_force,SIGNAL(clicked()),this,SLOT(SetCurrentOp_ch_Force()));
    connect(rb_replace,SIGNAL(clicked()),this,SLOT(SetCurrentOp_ch_Replace()));
    connect(rb_weak,SIGNAL(clicked()),this,SLOT(SetCurrentOp_ch_Weak()));

    connect(chb_importProp,SIGNAL(clicked()),this,SLOT(setAuthProp()));
    connect(chb_importStuff,SIGNAL(clicked()),this,SLOT(setAuthStuff()));
    connect(chb_importValues,SIGNAL(clicked()),this,SLOT(setAuthValue()));
    connect(chb_importContrainte,SIGNAL(clicked()),this,SLOT(setAuthContrainte()));
    //    connect(pb_sendMultiState,SIGNAL(clicked()),parent,SLOT(SendMulti()));

}

OperationVue::~OperationVue(){
    delete cbb_channel;
    delete cbb_Bank;
    delete cbb_Program;
//    delete _contrainteVue;
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

void OperationVue::on_pbStyle_clicked()
{
    emit updateStyle(le_qssPath->text());
}

void OperationVue::SetCurrentOp_ch_Force(){
    _model->setFlex(meth_Force);
}
void OperationVue::SetCurrentOp_ch_Replace(){
    _model->setFlex(meth_Replace);
}
void OperationVue::SetCurrentOp_ch_Weak(){
    _model->setFlex(meth_Weak);
}

void OperationVue::setAuthProp(){
    _model->setAuthProp(chb_importProp->isChecked());
}
void OperationVue::setAuthStuff(){
    _model->setAuthStuff(chb_importStuff->isChecked());
}
void OperationVue::setAuthContrainte(){
    _model->setAuthContrainte(chb_importContrainte->isChecked());
}
void OperationVue::setAuthValue(){
    _model->setAuthValue(chb_importValues->isChecked());
}

void OperationVue::UpdateChannel(){

    const MixPropParams * mp = _model->getMixsPars();
    chb_importProp->setChecked(mp->_modify_Props);
    chb_importStuff->setChecked(mp->_modify_Stuff);
    chb_importContrainte->setChecked(mp->_modify_Contr);
    chb_importValues->setChecked(mp->_modify_Val);

    switch(mp->_meth_flex)
    {
        case meth_Replace:
            rb_replace->setChecked(true);
            break;
        case meth_Force:
            rb_force->setChecked(true);
            break;
        case meth_Weak:
            rb_weak->setChecked(true);
            break;
        default:break;
    }

}

