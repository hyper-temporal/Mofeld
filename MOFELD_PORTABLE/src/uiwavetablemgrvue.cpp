#include "uiwavetablemgrvue.h"

UIWaveTableMgrVue::UIWaveTableMgrVue(QWidget *parent)
    :QWidget(parent)
{
    _noJump.setChecked(true);
    _tableNum.setValue(WT_START);
    _waveNum.setValue(0);
    _wavetableMgr = new BlofeldWaveTableMgrModel();
    _SignalCtrl = new DSPControl(parent,editCurrentSignal());

    _frequency.setValue(1);
    _sine.setChecked(true);
    _plus.setChecked(true);

    setNames();
    arrangeLayout();

//    connect(&_normalise,SIGNAL(clicked()),this,SLOT(setNormalise()));
    connect(&_sine,SIGNAL(clicked()),this,SLOT(draw()));
    connect(&_square,SIGNAL(clicked()),this,SLOT(draw()));
    connect(&_triangle,SIGNAL(clicked()),this,SLOT(draw()));
    connect(&_ramp,SIGNAL(clicked()),this,SLOT(draw()));
    connect(&_random,SIGNAL(clicked()),this,SLOT(draw()));
    connect(_SignalCtrl,SIGNAL(everythingHasChanged()),this,SLOT(everythingHasChanged()));
    connect(_SignalCtrl,SIGNAL(updateAndJump()),this,SLOT(updateAndJump()));
    connect(&_waveNum,SIGNAL(valueChanged(int)),this,SLOT(waveSelect(int)));

//    connect(&_normalise,SIGNAL(clicked(bool)),&_cuttingEdges,SLOT(setDisabled(bool)));
//    connect(&_cuttingEdges,SIGNAL(clicked(bool)),&_normalise,SLOT(setDisabled(bool)));
    connect(&_normalise,SIGNAL(clicked()),this,SLOT(normalise()));
    connect(&_cuttingEdges,SIGNAL(clicked()),this,SLOT(cutEdges()));
    connect(&_send,SIGNAL(clicked()),this,SLOT(sendWaveTable()));

    _SignalCtrl->installEventFilter(parent);

}

int UIWaveTableMgrVue::getpos(int wavenum){
    if( wavenum<WT_START || wavenum > WT_END) return -1;
    return wavenum-WT_START;
}



QVector<double> UIWaveTableMgrVue::getSignal(){
    if(_sine.isChecked()){
        return _SignalCtrl->getSine();
    }else if (_ramp.isChecked()) {
        return _SignalCtrl->getRamp();
    }else if (_triangle.isChecked()) {
        return _SignalCtrl->getTriangle();
    }else if (_square.isChecked()) {
        return _SignalCtrl->getSquare(_ratio.value());
    }else if (_random.isChecked()) {
        return _SignalCtrl->getRandom();
    }else if (_user.isChecked()) {
        throw ("not implemented");
    }else if (_wav.isChecked()) {
        throw ("not implemented");
    }
 }

//void UIWaveTableMgrVue::setNormalise(){
//    _SignalCtrl->_normalise=_normalise.isChecked();
//}

void UIWaveTableMgrVue::draw(){
    QVector<double> vs = getSignal();
    int freq = _frequency.value();
    _SignalCtrl->fillSignal(vs,freq);
}


/*

void UIWaveTableMgrVue::opUser()
{
   _SignalCtrl->getSine(_frequency.value());
}
void UIWaveTableMgrVue::opSine()
{
   _SignalCtrl->getSine(_frequency.value());
}
void UIWaveTableMgrVue::opSquare()
{
   _SignalCtrl->getSquare(_ratio.value(),_frequency.value());
}
void UIWaveTableMgrVue::opTriangle()
{
   _SignalCtrl->getTriangle(_frequency.value());
}
void UIWaveTableMgrVue::opRamp()
{
   _SignalCtrl->getRamp(_frequency.value());
}
void UIWaveTableMgrVue::opRandom()
{
   _SignalCtrl->getRandom(_frequency.value());
}*/



SignalReal *UIWaveTableMgrVue::editSignal(){
    int currt=getpos(_tableNum.value());
    int currw=(_waveNum.value());
    return _wavetableMgr->editSignal(currt,currw);
}

void  UIWaveTableMgrVue::addSignal(QVector<double> sig )
{
    SignalReal * s0 = editSignal();
    s0->addSignal(sig);
//    setSignal();
}
void UIWaveTableMgrVue::normalise(){
    SignalReal * s0 = editSignal();
    s0->normalise();
    s0->dft();
    emit everythingHasChanged();
}

void UIWaveTableMgrVue::cutEdges(){
    SignalReal * s0 = editSignal();
    s0->normalisePeaks();
    s0->dft();
    emit everythingHasChanged();
}

void UIWaveTableMgrVue::setSignal()
{
    _SignalCtrl->setSignal(editCurrentSignal());
}

void UIWaveTableMgrVue::arrangeLayout()
{

    QHBoxLayout *lyWavePick  = new QHBoxLayout;
    lyWavePick->addWidget(&_tableNum);
    lyWavePick->addWidget(&_waveNum);
    lyWavePick->addWidget(&_send);
    lyWavePick->addWidget(&_wtName);
    QGroupBox *gbTarget = new QGroupBox("Target");
    gbTarget->setLayout(lyWavePick);
    gbTarget->setFixedWidth(220);
//    QVBoxLayout *lyDrawingPanel  = new QVBoxLayout;
//    lyDrawingPanel->addWidget(_SignalCtrl->_timeDomain);
//    lyDrawingPanel->addWidget(_SignalCtrl->_frequencyDomain);

    QHBoxLayout *lyWaveForms1  = new QHBoxLayout;
    lyWaveForms1->addWidget(&_sine);
    lyWaveForms1->addWidget(&_triangle);
    lyWaveForms1->addWidget(&_ramp);
    lyWaveForms1->addWidget(&_random);

    QHBoxLayout *lyWaveForms2  = new QHBoxLayout;
    lyWaveForms2->addWidget(&_square);
    lyWaveForms2->addWidget(&_ratio);
    lyWaveForms2->addWidget(&_wav);

    QVBoxLayout *lyWaveForms  = new QVBoxLayout;
    lyWaveForms->addLayout(lyWaveForms1);
    lyWaveForms->addLayout(lyWaveForms2);
    QGroupBox *gbWaveForms = new QGroupBox("Waveforms");
    gbWaveForms->setLayout(lyWaveForms);

    QHBoxLayout *lyOperations  = new QHBoxLayout;
    lyOperations->addWidget(&_plus);
    lyOperations->addWidget(&_minus);
    lyOperations->addWidget(&_multiplyWith);
    lyOperations->addWidget(&_multiplySelf);
    lyOperations->addWidget(&_gain);
    QGroupBox *gbOps = new QGroupBox("Operations");
    gbOps->setLayout(lyOperations);

    QHBoxLayout *lyFilters  = new QHBoxLayout;
    lyFilters->addWidget(&_frequency);
    lyFilters->addWidget(&_filterQ);
    lyFilters->addWidget(&_filterCut);
    lyFilters->addWidget(&_filterPass);
    QGroupBox *gbFilter = new QGroupBox("Filter Tool");
    gbFilter->setLayout(lyFilters);

    QHBoxLayout *lyMorphCtrls  = new QHBoxLayout;
    lyMorphCtrls->addWidget(&_noJump);
    lyMorphCtrls->addWidget(&_jumpPrevious);
    lyMorphCtrls->addWidget(&_jumpNext);
    lyMorphCtrls->addWidget(&_cbAfterMorph);
    lyMorphCtrls->addWidget(&_cbNoMorph);
    QGroupBox *gbJump = new QGroupBox("Wave Scroll");
    gbJump->setLayout(lyMorphCtrls);

    QVBoxLayout *lyLocks  = new QVBoxLayout;
    lyLocks->addWidget(&_lockPhase);
    lyLocks->addWidget(&_lockWave);
    lyLocks->addWidget(&_lockMag);

    QVBoxLayout *lyNorms  = new QVBoxLayout;
    lyNorms->addWidget(&_normalise);
    lyNorms->addWidget(&_cuttingEdges);

    QHBoxLayout *_cuttButtsScroll  = new QHBoxLayout;
    _cuttButtsScroll->addLayout(lyLocks);
    _cuttButtsScroll->addLayout(lyNorms);

    QGroupBox *gbScrollButs = new QGroupBox("B4 Scroll");
    gbScrollButs->setLayout(_cuttButtsScroll);


    QVBoxLayout *lyControlPanel  = new QVBoxLayout;
    lyControlPanel->addWidget(gbWaveForms);
    lyControlPanel->addWidget(gbOps);
    lyControlPanel->addWidget(gbFilter);
    lyControlPanel->addWidget(gbJump);
    lyControlPanel->addWidget(gbScrollButs);
    lyControlPanel->addWidget(gbTarget);
//    lyControlPanel->addWidget(&_wtName);

    QHBoxLayout *lyFinal  = new QHBoxLayout;
    lyFinal->addWidget(_SignalCtrl);
    lyFinal->addLayout(lyControlPanel);
    setLayout(lyFinal);
}



void UIWaveTableMgrVue::setNames()
{
    _wtName.setText("new wt");
    _tableNum.setRange(WT_START,WT_END);
    _tableNum.setValue(WT_START);
    _waveNum.setRange(0,WT_WAVEMAX-1);
    _ratio.setRange(0,100);
    _gain.setRange(0.0,1.0);
    _gain.setSingleStep(0.01);
    _frequency.setRange(0,WT_SAMPLESCOUNT/2);
    _filterQ.setRange(0,127);

    _send.setText("SEND");
    _sine.setText("sine");
    _triangle.setText("triangle");
    _ramp.setText("ramp");
    _square.setText("Pulse");;
    _random.setText("Random");
    _wav.setText("Wave");

    _plus.setText("+");
    _minus.setText("-");
    _multiplyWith.setText("*");
    _multiplySelf.setText("²");

    _filterCut.setText("Cut");
    _filterPass.setText("Pass");

    _noJump.setText("||");
    _jumpPrevious.setText("<<");
    _jumpNext.setText(">>");

    _lockMag.setText("Mg");
    _lockMag.setCheckable(true);
    _lockPhase.setText("Ph");
    _lockPhase.setCheckable(true);
    _lockWave.setText("T");
    _lockWave.setCheckable(true);

    _normalise.setText("NORM");
    _normalise.setCheckable(true);
    _cuttingEdges.setText("TRIM");
    _cuttingEdges.setCheckable(true);

}


SignalReal *UIWaveTableMgrVue::editCurrentSignal()
{
    return _wavetableMgr->editSignal(getpos(_tableNum.value()),_waveNum.value());
}


const SignalReal *UIWaveTableMgrVue::getCurrentSignal()
{
    return editCurrentSignal();
}

void UIWaveTableMgrVue::waveSelect(int v)
{
    setWaveNum(v);
    setSignal();
}


void UIWaveTableMgrVue::setWaveNum(int pos)
{
    if(     pos <  WT_WAVEMAX
        &&  pos >= 0
        )
    {
        _waveNum.setValue(pos );
    }
    else throw ("extremum reached");
}

void UIWaveTableMgrVue::updateAndJump()
{
    everythingHasChanged();
    onModify();
}

void UIWaveTableMgrVue::everythingHasChanged()
{
//    onModify();
    if(_cuttingEdges.isChecked()){
        editCurrentSignal()->normalisePeaks();
        editCurrentSignal()->dft();
    }
    if(_normalise.isChecked()){
        editCurrentSignal()->normalise();
        editCurrentSignal()->dft();
    }
    setSignal();
}


bool UIWaveTableMgrVue::goNextTable()
{
//    try {
        setWaveNum(_waveNum.value()+1);
        return true;
//    } catch (...) {
//        return false;
//    }
}

bool UIWaveTableMgrVue::goPreviousTable()
{
//    try {
        setWaveNum(_waveNum.value()-1);
        return true;
//    } catch (...) {
//        return false;
//    }
}

void UIWaveTableMgrVue::sendWaveTable()
{
    int tv =getpos(_tableNum.value());
    emit sendTable(_wavetableMgr->getTable(tv),_tableNum.value(),_wtName.text());
}

void UIWaveTableMgrVue::onModify(){
    try {
        const SignalReal *s0 = NULL;
        SignalReal *s1 = NULL;

        if(_jumpNext.isChecked())
        {
            if(goNextTable())
            {
                int tn = getpos(_tableNum.value());
                int wv0 =_waveNum.value()-1;
                int wv1 =_waveNum.value();
                s0 =_wavetableMgr->getSignal(tn,wv0);
                s1 =_wavetableMgr->editSignal(tn,wv1);
            }

        }
        else if(_jumpPrevious.isChecked()){
            if(goPreviousTable())
            {
                int tn = getpos(_tableNum.value());
                int wv0 =_waveNum.value()+1;
                int wv1 =_waveNum.value();
                s0 =_wavetableMgr->getSignal(tn,wv0);
                s1 =_wavetableMgr->editSignal(tn,wv1);
            }
        }
        if(s0!= NULL && s1!= NULL){
            if(_lockMag.isChecked()){
                s1->setMagnitude(s0->getValuesMg());
            }
            if(_lockPhase.isChecked()){
                s1->setPhase(s0->getValuesPh());
            }
        }
    } catch (...)
    {
        _noJump.setChecked(true);
    }
}

//SignalReal * UIWaveTableMgrVue::getCurrentSignal(){
//    int tn = getpos(_tableNum.value());
//    int wv0 =_waveNum.value();
//    s0 = _wavetableMgr->getSignal(tn,wv0);
//}
