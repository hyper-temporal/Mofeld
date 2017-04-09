#include "uiwavetablemgrvue.h"

UIWaveTableMgrVue::UIWaveTableMgrVue(QWidget *parent)
    :QWidget(parent)
{
    _noJump.setChecked(true);
    _tableNum.setValue(WT_START);
    _waveNum.setValue(0);
    _wavetableMgr = new BlofeldWaveTableMgrModel();
    _SignalCtrl = new DSPControl(this,editCurrentSignal());

    _frequency.setValue(1);
    _sine.setChecked(true);
    _plus.setChecked(true);

    setNames();
    arrangeLayout();

    connect(&_sine,SIGNAL(clicked()),this,SLOT(drawSine()));
    connect(&_square,SIGNAL(clicked()),this,SLOT(drawSquare()));
    connect(&_triangle,SIGNAL(clicked()),this,SLOT(drawTriangle()));
    connect(&_ramp,SIGNAL(clicked()),this,SLOT(drawRamp()));
    connect(&_random,SIGNAL(clicked()),this,SLOT(drawRandom()));
    connect(_SignalCtrl,SIGNAL(everythingHasChanged()),this,SLOT(everythingHasChanged()));
    connect(&_waveNum,SIGNAL(valueChanged(int)),this,SLOT(waveSelect(int)));

    connect(&_send,SIGNAL(clicked()),this,SLOT(sendWaveTable()));
}
void UIWaveTableMgrVue::drawSine()
{
   _SignalCtrl->drawSine(_frequency.value());
}
void UIWaveTableMgrVue::drawSquare()
{
   _SignalCtrl->drawSquare(_ratio.value(),_frequency.value());
}
void UIWaveTableMgrVue::drawTriangle()
{
   _SignalCtrl->drawTriangle(_frequency.value());
}
void UIWaveTableMgrVue::drawRamp()
{
   _SignalCtrl->drawRamp(_frequency.value());
}
void UIWaveTableMgrVue::drawRandom()
{
   _SignalCtrl->drawRandom(_frequency.value());
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
    gbTarget->setFixedWidth(200);

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
    lyMorphCtrls->addWidget(&_lockPhase);
    lyMorphCtrls->addWidget(&_lockMag);
    lyMorphCtrls->addWidget(&_normalise);
    QGroupBox *gbJump = new QGroupBox("Wave Scroll");
    gbJump->setLayout(lyMorphCtrls);

    QVBoxLayout *lyControlPanel  = new QVBoxLayout;
    lyControlPanel->addWidget(gbWaveForms);
    lyControlPanel->addWidget(gbOps);
    lyControlPanel->addWidget(gbFilter);
    lyControlPanel->addWidget(gbJump);
    lyControlPanel->addWidget(gbTarget);

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

    _lockMag.setText("MAGN");
    _lockMag.setCheckable(true);
    _lockPhase.setText("PHASE");
    _lockPhase.setCheckable(true);
    _normalise.setText("NORM");
    _normalise.setCheckable(true);
}


SignalReal *UIWaveTableMgrVue::editCurrentSignal()
{
    return _wavetableMgr->editSignal(_tableNum.value()-WT_START,_waveNum.value());
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


void UIWaveTableMgrVue::setWaveNum(int v)
{
    if(     v <  WT_WAVEMAX
        &&  v >= 0
        )
    {
        _waveNum.setValue(v );
    }
    else throw ("extremum reached");
}


void UIWaveTableMgrVue::everythingHasChanged()
{
    try {
        if(_jumpNext.isChecked())
        {
            goNextTable();
        }
        else if(_jumpPrevious.isChecked()){
            goPreviousTable();
        }

    } catch (...)
    {
        _noJump.setChecked(true);
    }
    setSignal();

}

void UIWaveTableMgrVue::goNextTable()
{
    setWaveNum(_waveNum.value()+1);
}

void UIWaveTableMgrVue::goPreviousTable()
{
    setWaveNum(_waveNum.value()-1);
}

void UIWaveTableMgrVue::sendWaveTable()
{
    int tv =_tableNum.value()-WT_START;
    emit sendTable(_wavetableMgr->getTable(tv),_tableNum.value(),_wtName.text());
}

