 #include <QtGui>

#include "blofeldEditorVue.h"

BlofeldEditorVue::BlofeldEditorVue(QWidget * par, TargetProvider *synth)
    :lyOscillators(synth,par),
    lyEnveloppes(synth,par),
    lyMatrix(synth,par),
    lyFiltersFXs(synth,par),
    lyArpeggio(synth, par)
{



    _editorParams  = new QTabWidget();
    _editorParams->addTab(&lyOscillators, tr("OSCILLATORS"));
    _editorParams->addTab(&lyEnveloppes, tr("ENVELOPPES & LFOS"));
    _editorParams->addTab(&lyMatrix, tr("MATRIX & MODIFIERS"));
    _editorParams->addTab(&lyFiltersFXs, tr("FILTERS & FX"));
    _editorParams->addTab(&lyArpeggio, tr("ARP"));


    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(_editorParams);
    setLayout(mainLayout);
    setWindowFlags(Qt::CustomizeWindowHint);

    initControls();
}

BlofeldEditorVue::~BlofeldEditorVue()
{
    delete mainLayout;
}

CtrlParamLeaf * BlofeldEditorVue::GetCtrl(int id)
{
    if(id<_controles.size())
        return _controles[id];
    else return NULL;
}


void BlofeldEditorVue::updatethis(const Parametre * p){
    try{
        int pid = p->getID();
        CtrlParamLeaf * ct = GetCtrl(pid);
        if(ct == NULL) return;

        ct->UpdatedValue(p->getValue());
        ct->setProprieteVue(p->getProp());

        if(pid == 93 ){
            lyFiltersFXs.updateForm(0,p->getValue());
        }
        else if(pid == 109){
            lyFiltersFXs.updateForm(1,p->getValue());
        }
    }
    catch(...){}
}



void BlofeldEditorVue::initControls()
{
    QVector<CtrlParamLeaf *> leaves ;
    leaves+= lyOscillators.getLeafs();
    leaves+= lyEnveloppes.getLeafs();
    leaves+= lyMatrix.getLeafs();
    leaves+= lyFiltersFXs.getLeafs();
    leaves+= lyArpeggio.getLeafs();
    _controles = leaves;

    std::sort(_controles.begin(),_controles.end(),sortControls);

    foreach( CtrlParamLeaf * leafs, _controles)
    {
        leafs->AfterConstructor();
    }
}


