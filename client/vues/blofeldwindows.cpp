#include "blofeldwindows.h"
using namespace OperationProps;

BlofeldViews::BlofeldViews(QWidget *par):QWidget(par)
{

    _synth = new BlofeldReplica();
    _wtEditor = new UIWaveTableMgrVue(this);

    connect(_wtEditor,SIGNAL(sendTable(const BlofeldWaveTableModel*,int,QString)),
            _synth,SLOT(sendTable(const BlofeldWaveTableModel*,int,QString)));

    connect(_synth,SIGNAL(updateArrangement(const Arrangement *)),
            this, SLOT(updateView(const Arrangement *)));
    connect(_synth,SIGNAL(updateInstrument(const Instrument*)),
            this, SLOT(updateView(const Instrument *)));
    connect(_synth,SIGNAL(updateParametre(const Parametre*)),
            this, SLOT(updateView(const Parametre * )));
    connect(_synth,SIGNAL(syncMulti()),
            this, SLOT(updateMultiView()));


    _OperationModel = new OperationModel(_synth);
    _CommonVue = new OperationVue(_OperationModel,_synth,this);

    _multi = new BlofeldMultiVue(this,_synth);
    _editor = new BlofeldEditorVue(this,_synth,_synth->editInstrument());


    _arrModel = new ArrangementModel(_synth);
    _instruModel = new InstrumentModel(_synth);
    _proprieteModel = new ProprieteModel(_synth);

    _wtModel =new WTModel(_wtEditor->getModel());
    _wtVue = new WaveTableSelectVue(_wtModel,this);
    _wtVue->connectAll(this);

    _arrVue = new ArrangementVue(_arrModel,this);
    _propsVue= new ProprieteVue( _proprieteModel,this );
    _instruVue = new InstrumentVue(_instruModel,this);
    _propsElementVue = new ProprieteElementsVue(_proprieteModel,this);

    _arrVue->connectAll(this);
    _instruVue->connectAll(this);
    _propsVue->connectAll(this);
    _propsElementVue->connectAll(this);

    QHBoxLayout *lyV3  = new QHBoxLayout;
    lyV3->addWidget(_propsElementVue);
    lyV3->addWidget(_propsVue);
    QHBoxLayout *lyV4  = new QHBoxLayout;
    lyV4->addWidget(_instruVue);
    lyV4->addWidget(_arrVue);
    lyV4->addWidget(_wtVue);
    QVBoxLayout *lyV5  = new QVBoxLayout;
    lyV5->addLayout(lyV3);
    lyV5->addLayout(lyV4);
    _wTargetCtrl=new QWidget(this);
    _wTargetCtrl->setLayout(lyV5);
    QAction *quitAction = new QAction(tr("E&xit"), this);
    quitAction->setShortcuts(QKeySequence::Quit);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(this, SIGNAL(updateStyle(QString)), par, SLOT(updateStyle(QString)));

    addAction(quitAction);
    _synth->importArrangement();
}
BlofeldViews::~BlofeldViews()
{
    delete _synth;
}


void BlofeldViews::closeEvent(QCloseEvent *)
{
    _instruVue->close();
    _propsElementVue->close();
    _propsVue->close();
    _wtVue->close();
    _arrVue->close();
    _CommonVue->close();
    _multi->close();
    _editor->close();
}

void BlofeldViews::updateView(const Arrangement * a){
    updateInstrumentView();
}

void BlofeldViews::updateView(const Instrument * i){
    updateInstrumentView();
}

void BlofeldViews::updatePElements()
{
    const Propriete * prpch = _synth->getProprieteChannel();
    _propsElementVue->setModel(prpch);
}

void BlofeldViews::updateView(int pid)
{
    updateView(_synth->getparametre(pid));
}

void BlofeldViews::updateView(const Parametre * p)
{
    _editor->updatethis(p);
    updatePElements();
}

void BlofeldViews::updateView(const Propriete * p)
{
    updateInstrumentView();
}


void BlofeldViews::updateInstrumentView()
{
    Instrument * e = _synth->editInstrument();
    foreach(Parametre   pa , *e->getParametres()){
        _editor->updatethis(&pa);
    }
    updatePElements();

    QString s;
    try {
       e->getName();
    } catch (...) {
    }
    if(s!=""){
        _CommonVue->UpdateInstruName(s);
    }else{
        _CommonVue->UpdateInstruName("NEW INSTRUMENT");
    }
}



void BlofeldViews::deleteProprietes(QVector<int> propIdsChannel)
{
    foreach(int id, propIdsChannel){
        _synth->setPropriete(id,false);
    }
    updateInstrumentView();
}

void BlofeldViews::UpdateChannel(int ch)
{
    _synth->ChangeEditedChannel(ch);
    _CommonVue->UpdateChannel();
    updateInstrumentView();
}

void BlofeldViews::Reimport(){
    _synth->importInstrument();
}


void BlofeldViews::ImportInstrument(int bank, int pgm)
{
    _synth->importInstrument(bank,pgm);
}

void BlofeldViews::ReGenerate()
{
    _synth->Regenerate();
    updateInstrumentView();
}


void BlofeldViews::SetInstrumentName(QString s){
    _synth->setInstrumentName(s);
}

void BlofeldViews::recevoirTables(const BlofeldWaveTableMgrModel *m){
    int wnum =80;
    foreach (BlofeldWaveTableModel wt, *m->getTables())
    {
        _synth->sendTable(&wt,wnum++,wt.getName());
    }
}

void BlofeldViews::recevoirArrangement(const Arrangement *a)
{
    _synth->MixArrangement(a);
    updateInstrumentView();
    updateMultiView();
}

void BlofeldViews::recevoirInstrument(const Instrument * i){
    _synth->MixInstrument(i);
    updateInstrumentView();
}

void BlofeldViews::recevoirPropriete(const Propriete *p){
    _synth->MixPropriete(p);
    updateInstrumentView();
}

void BlofeldViews::setParametre( int pid , int v)
{
    try {
        _synth->MixParametre(_synth->getChCurrent(),pid,v);
        updateView(pid);
    } catch (...) {
    }
}

void BlofeldViews::setMinimum(int pid,int value,ParamContext *pc)
{
    Parametre *p = _synth->editParam(pid);
    p->editContrainte()->updateMin(p->getValue(value));
    setParametre(p->getID(),p->getValue());
    pc->updateForm(p);
}

void BlofeldViews::setMaximum(int pid,int value,ParamContext *pc)
{
    Parametre *p = _synth->editParam(pid);
    p->editContrainte()->updateMax(p->getValue(value));
    setParametre(p->getID(),p->getValue());
    pc->updateForm(p);
}

void BlofeldViews::restrictValue(int pid,ParamContext *pc)
{
    const Parametre *p= _synth->getparametre(pid);
    _synth->editParam(pid)->editContrainte()->restrict2Value(p->getValue());
    pc->updateForm(p);
}

void BlofeldViews::setPropriete(int pid,bool isprop,ParamContext *pc){
    _synth->setPropriete(pid,isprop);
    const Parametre *p= _synth->getparametre(pid);
    setParametre(p->getID(),p->getValue());
    pc->updateForm(p);
}

void BlofeldViews::updateContext(int pid, ParamContext *pc)
{
    const Parametre *p= _synth->getparametre(pid);
    pc->updateForm(p);
}

void BlofeldViews::multiRequest(int num){
    _synth->multiRequest(num);
}

void BlofeldViews::multiSend(int num){
    _synth->multiSend(num);
}

void BlofeldViews::updateMultiView()
{
    _multi->synchronise();
}
