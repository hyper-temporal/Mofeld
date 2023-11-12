#include "blofeldwindows.h"
#include "paramcontext.h"


void BlofeldViews::initWTEditor(QWidget *parent)
{
    _wtEditor.installEventFilter(parent);
    connect(parent,SIGNAL(k_Drawers4Phase()),
            &_wtEditor,SLOT(setDrawModePhase()));
    connect(parent,SIGNAL(k_Drawers4Mag()),
            &_wtEditor,SLOT(setDrawModeMagnitude()));
    connect(parent,SIGNAL(k_Drawers4RotationPH(bool)),
            &_wtEditor,SLOT(setDrawModeRotationPH(bool)));
    connect(parent,SIGNAL(k_Drawers4RotationMG(bool)),
            &_wtEditor,SLOT(setDrawModeRotationMG(bool)));
    connect(parent,SIGNAL(k_Drawers4RotationT(bool)),
            &_wtEditor,SLOT(setDrawModeRotationT(bool)));
    _wtVue.connectAll(this);
}

void BlofeldViews::initMidiIO(QWidget *parent){

    _wtVue.connectAll(this);
    _arrVue.connectAll(this);
    _instruVue.connectAll(this);
    _propsVue.connectAll(this);
    _propsElementVue.connectAll(this);

    QHBoxLayout *lyV3 = new QHBoxLayout();
    lyV3->addWidget(&_propsElementVue);
    lyV3->addWidget(&_propsVue);
    QHBoxLayout *lyV4 = new QHBoxLayout();
    lyV4->addWidget(&_instruVue);
    lyV4->addWidget(&_arrVue);
    lyV4->addWidget(&_wtVue);
    QVBoxLayout *lyV5 = new QVBoxLayout();
    lyV5->addLayout(lyV3);
    lyV5->addLayout(lyV4);
    //    _wTargetCtrl=new QWidget(parent);
    //    _wTargetCtrl->setLayout(lyV5);

    setLayout(lyV5);
    //    setLayout(lyV5);
    quitAction.setShortcuts(QKeySequence::Quit);
    connect(&quitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
//    connect(this, SIGNAL(updateStyle(QString)), parent, SLOT(updateStyle(QString)));

    addAction(&quitAction);
    //_tp.getTarget()->importArrangement();
   // _CommonVue->UpdateChannel();

    initWTEditor(parent);

    connect(&_CommonVue,SIGNAL(synthSelectChanged(int)),
            this,SLOT(setSynthId(int)));


    setSynthId(0);
}

BlofeldViews::BlofeldViews(QWidget *parent)
    :QWidget(parent)
    ,quitAction(tr("E&xit"), this)
    ,_tp(this)
    ,_editor(this,&_tp)
    ,_OperationModel(&_tp)
    ,_CommonVue(&_OperationModel,this,_tp.getBids())
    ,_wtEditor(&_tp,parent)
    ,_wtModel(_wtEditor.getModel())
    ,_wtVue(&_wtModel,this)
    ,_arrModel(&_tp)
    ,_instruModel(&_tp)
    ,_proprieteModel(&_tp)
    ,_arrVue (&_arrModel,this)
    ,_propsVue ( &_proprieteModel,this )
    ,_instruVue  (&_instruModel,this)
    ,_propsElementVue  (&_proprieteModel,this)
    ,_multi(this, &_tp)
{
    installEventFilter(this);
    initWTEditor(parent);

    _arrVue.connectAll(this);
    _instruVue.connectAll(this);
    _propsVue.connectAll(this);
    _propsElementVue.connectAll(this);

    QHBoxLayout *lyV3  = new QHBoxLayout;
    lyV3->addWidget(&_propsElementVue);
    lyV3->addWidget(&_propsVue);
    QHBoxLayout *lyV4  = new QHBoxLayout;
    lyV4->addWidget(&_instruVue);
    lyV4->addWidget(&_arrVue);
    lyV4->addWidget(&_wtVue);
    QVBoxLayout *lyV5  = new QVBoxLayout;
    lyV5->addLayout(lyV3);
    lyV5->addLayout(lyV4);
    //    _wTargetCtrl=new QWidget(par);
    //    _wTargetCtrl->setLayout(lyV5);

    setLayout(lyV5);
    quitAction.setShortcuts(QKeySequence::Quit);
    connect(&quitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
//    connect(this, SIGNAL(updateStyle(QString)), parent, SLOT(updateStyle(QString)));

    addAction(&quitAction);
    //_tp.getTarget()->importArrangement();
   // _CommonVue->UpdateChannel();
    connect(&_CommonVue,SIGNAL(synthSelectChanged(int)),
            this,SLOT(setSynthId(int)));
    _tp.getTarget()->importGlobal();
    setSynthId(0);

}

BlofeldViews::~BlofeldViews()
{}

void BlofeldViews::closeEvent(QCloseEvent *)
{
    _instruVue.close();
    _propsElementVue.close();
    _propsVue.close();
    _wtVue.close();
    _arrVue.close();
    _CommonVue.close();
    _editor.close();
//    _multi.close();

}

void BlofeldViews::updateView(const Arrangement * a){
    updateInstrumentView();
}

void BlofeldViews::updateView(const Instrument * i){
    updateInstrumentView();
}

void BlofeldViews::updatePElements()
{
    const Propriete * prpch = _tp.getTarget()->getProprieteChannel();
    //    const Propriete * prpch = _tp.getTarget()->getChannel()->getProprieteChannel();
    //    _propsVue->editThat(prpch);
    _propsElementVue.setModel(prpch);
}

void BlofeldViews::updateView(int pid)
{
    updateView(_tp.getTarget()->getparametre(pid));
}

void BlofeldViews::updateView(const Parametre * p)
{
    _editor.updatethis(p);
    updatePElements();
}

void BlofeldViews::updateView(const Propriete * p)
{
    //    foreach (Parametre par, p.getParametres()) {
    //       updateView(par.getID());
    //    }
    //    updatePElements();
    updateInstrumentView();

}


void BlofeldViews::updateInstrumentView()
{
    Instrument * e = _tp.getTarget()->editInstrument();
    //    _instruVue->editThat(e);
    for(const Parametre& pa : *e->getParametres()){
        _editor.updatethis(&pa);
    }
    updatePElements();
    _CommonVue.UpdateInstruName(e->getName());
}

void BlofeldViews::updateMultiView()
{
       _multi.synchronise();
}

void BlofeldViews::deleteProprietes(QVector<int> propIdsChannel)
{
    foreach(int id, propIdsChannel){
        _tp.getTarget()->setPropriete(id,false);
    }
    updateInstrumentView();
}

void BlofeldViews::UpdateChannel(int ch)
{
    _tp.getTarget()->ChangeEditedChannel(ch);
    updateInstrumentView();
    _patienteur.usleep(50000);
}

void BlofeldViews::Reimport(){
    auto& instru = _tp.getTarget()->getIMessage();
    auto m = instru.getMessage(0,0);
    QFile f( "./SYX/"+ _CommonVue.getInstruName()+".syx" );
    f.open( QIODevice::WriteOnly );
    f.write( (char *)m->data(),m->size()  );
    f.close();
 }


void BlofeldViews::ImportInstrument(int bank, int pgm)
{
    _tp.getTarget()->importInstrument(bank,pgm);
}

void BlofeldViews::ReGenerate()
{
    _tp.getTarget()->Regenerate();
    updateInstrumentView();
}


void BlofeldViews::SetInstrumentName(QString s){
    _tp.getTarget()->setInstrumentName(s);
}

void BlofeldViews::recevoirTables(const BlofeldWaveTableMgrModel *m){
    int wnum =80;
    throw "check first pleez";
    foreach (BlofeldWaveTableModel wt, *m->getTables())
    {
        _tp.getTarget()->sendTable(&wt,wnum++,wt.getName());
    }
}

void BlofeldViews::recevoirArrangement(const Arrangement *a)
{
    _tp.getTarget()->MixArrangement(a);
}

void BlofeldViews::recevoirInstrument(const Instrument * i){
    _tp.getTarget()->setInstrument(*i);
}

void BlofeldViews::recevoirPropriete(const Propriete *p){
    _tp.getTarget()->MixPropriete(p);
}

void BlofeldViews::setParametre( int pid , int v)
{

    _tp.getTarget()->MixParametre(_tp.getTarget()->getChCurrent(),pid,v);
    updateView(pid);
    _patienteur.usleep(5000);

}

void BlofeldViews::setMinimum(int pid,int value,ParamContext *pc)
{
    Parametre *p = _tp.getTarget()->editParam(pid);
    p->editContrainte()->updateMin(p->getValue(value));
    setParametre(p->getID(),p->getValue());
    pc->updateForm(p);
}

void BlofeldViews::setMaximum(int pid,int value,ParamContext *pc)
{
    Parametre *p = _tp.getTarget()->editParam(pid);
    p->editContrainte()->updateMax(p->getValue(value));
    setParametre(p->getID(),p->getValue());
    pc->updateForm(p);
}

void BlofeldViews::restrictValue(int pid,ParamContext *pc)
{
    const Parametre *p= _tp.getTarget()->getparametre(pid);
    _tp.getTarget()->editParam(pid)->editContrainte()->restrict2Value(p->getValue());
    pc->updateForm(p);
}

void BlofeldViews::setPropriete(int pid,bool isprop,ParamContext *pc){
    _tp.getTarget()->setPropriete(pid,isprop);
    const Parametre *p= _tp.getTarget()->getparametre(pid);
    setParametre(p->getID(),p->getValue());
    pc->updateForm(p);
}

void BlofeldViews::updateContext(int pid, ParamContext *pc)
{
    const Parametre *p= _tp.getTarget()->getparametre(pid);
    pc->updateForm(p);
}

void BlofeldViews::multiRequest(int num){
    _tp.getTarget()->multiRequest(num);
}

void BlofeldViews::multiSend(int num){
    _tp.getTarget()->multiSend(num);
}



void BlofeldViews::setSynthId(int bid){
    _tp.setTarget(bid);
    if(_tp.getTarget() == nullptr)
        return;
    Reimport();
}


