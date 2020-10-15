#include "blofeldmultivue.h"

BlofeldMultiVue::BlofeldMultiVue(QWidget *parent,const BlofeldReplica *synth)
{
    _multiblob  = synth->getDumpMulti();

    int pGlobalVol=23;
    int pTempo=24;

    ctrlComposite * block1 = new ctrlComposite(parent, QBoxLayout::LeftToRight );
    block1->addCtrl(new frmSynthCtrl_rotary( parent, synth ,_multiblob->getParametre(pGlobalVol),0,QBoxLayout::LeftToRight));
    block1->addCtrl(new frmSynthCtrl_combobox( parent, synth ,_multiblob->getParametre(pTempo),QBoxLayout::LeftToRight));

    ctrlComposite * block2 = new ctrlComposite(parent, QBoxLayout::LeftToRight );
    for(int i(0);i<16;i++){
        QString s =  "part "+ QString::number(i+1);
        auto slice = new BlofeldMultiSlice(synth,_multiblob,i,s,parent);
        slice->hide();
        _slices.append(slice);
        block2->addCtrl(slice);
    }
    block1->setLayout();
    block2->setLayout();

    foreach( CtrlParamLeaf * leaf, block1->getLeafs())
    {
        _controles.append(leaf);
        leaf->forMulti();
    }
    foreach( CtrlParamLeaf * leaf, block2->getLeafs())
    {
        _controles.append(leaf);
        leaf->forMulti();
    }

    _pbImport = new QPushButton("Import");
    _pbExport = new QPushButton("Export");
    SetCBBMultiNum();
    QHBoxLayout *lyh0 = new QHBoxLayout;
    lyh0->addWidget(_pbImport);
    lyh0->addWidget(_pbExport);
    lyh0->addWidget(_cbbMultiNum);
    lyh0->addWidget(block1);

    QGroupBox *gb = new QGroupBox("GENERAUX");
    gb->setLayout(lyh0);

    QVBoxLayout *lyh1 = new QVBoxLayout;
    lyh1->addWidget(gb);
    lyh1->addWidget(block2);

    QGroupBox *gb1 = new QGroupBox("MULTI");
    gb1->setLayout(lyh1);

    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(gb1);

    mainLayout->setSpacing(1);
    mainLayout->setContentsMargins(1, 0, 0, 0);
    setWindowFlags(Qt::CustomizeWindowHint);

    setLayout(mainLayout);
    connection(parent);
    hide();

    connect( _cbbMultiNum , SIGNAL( currentIndexChanged(int)), this , SLOT(ShowSlice(int)));
}


void BlofeldMultiVue::SetCBBMultiNum(){

    _cbbMultiNum = new QComboBox(this);
//    disconnect(_cbbMultiNum,SIGNAL(currentIndexChanged(int)),0,0);
    _cbbMultiNum->setModel( new ComboTool( BlofeldTypesEnum::getInstance().GetEnum(BLOT_STANDARD)));
}

void BlofeldMultiVue::connection( QWidget * parent)
{
    connect (_pbImport,SIGNAL(clicked()),this,SLOT(multiRequest()));
    connect(_pbExport,SIGNAL(clicked()),this,SLOT(multiSend()));
    connect (this,SIGNAL(multiRequest(int)),parent,SLOT(multiRequest(int)));
    connect(this,SIGNAL(multiSend(int)),parent,SLOT(multiSend(int)));
//    connect(_cbbMultiNum,SIGNAL(currentIndexChanged(int)),parent,SLOT(ImportInstrument(int,int)));
}
void BlofeldMultiVue::multiRequest()
{
    emit multiRequest(_cbbMultiNum->currentIndex());
}
void BlofeldMultiVue::multiSend()
{
    emit multiSend(_cbbMultiNum->currentIndex());
}

void BlofeldMultiVue::ShowSlice(int sn)
{
    foreach (BlofeldMultiSlice * comp , _slices) {
        comp->hide();
    }
    if(sn<_slices.count())
        _slices[sn]->show();
    else
        qInfo("bunk");

}


void BlofeldMultiVue::synchronise(){

    foreach(CtrlParamLeaf *cpl, _controles){
        cpl->synchronise();
    }
}
