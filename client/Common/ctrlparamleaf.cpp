#include "ctrlparamleaf.h"

CtrlParamLeaf::CtrlParamLeaf(
        QWidget * parent,
        QWidget *enfant,
        const BlofeldReplica *synth,
        Parametre *param,
        QBoxLayout::Direction direction)
    :CtrlValueLeaf(parent,enfant,synth,param->getType(),direction),
        _paramId(param->getID())
{
}


void CtrlParamLeaf::ctxMenu(const QPoint &pos)
{

    QMenu *menu = new QMenu;

    ParametreReAction * pAction = new ParametreReAction(_synth->getparametre(_paramId));


    connect(pAction->getContext(), SIGNAL(setPropriete(int,bool,ParamContext*)),
                _parent, SLOT(setPropriete(int,bool,ParamContext*)));
    connect(pAction->getContext(), SIGNAL(setMinimum(int,int,ParamContext*)),
                _parent, SLOT(setMinimum(int,int,ParamContext*)));
    connect(pAction->getContext(), SIGNAL(setMaximum(int,int,ParamContext*)),
                _parent, SLOT(setMaximum(int,int,ParamContext*)));    
    connect(pAction->getContext(), SIGNAL(restrict2Value(int,ParamContext*)),
                _parent, SLOT(restrictValue(int,ParamContext*)));

    connect(pAction->getContext(), SIGNAL(updateMe(int,ParamContext*)),
                _parent, SLOT(updateContext(int,ParamContext*)));



    menu->addAction(pAction);
    menu->exec(mapToGlobal(pos));

}


void CtrlParamLeaf::setProprieteVue(bool isProp){
    _isProp=isProp;
    update();
}

void CtrlParamLeaf::paintEvent(QPaintEvent *)
{
    QColor col;
    if(_isProp){
        col = QColor(250, 20, 10,64);
    }else{
        col = QColor(200, 210, 230,64);
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, _antialiased);
    painter.fillRect( rect(),col);
}



void CtrlParamLeaf::AfterConstructor(){
    _isProp = false;
    CtrlValueLeaf::init();

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(ctxMenu(const QPoint &)));

    QObject::connect(this, SIGNAL(UpdateParametre(int,int)),
                    _parent, SLOT(setParametre(int,int)));
    reconnecter();
}


void CtrlParamLeaf::ValueChanged(int p){

    try {
        int v = _valueMgr->getValueOfElement(p);
        emit(UpdateParametre( _paramId,v ));
    } catch (...){
    }
}

void CtrlParamLeaf::ValueChanged(bool p)
{
    try {
        int v;
        v = _valueMgr->getValueOfElement((int)p);
        emit(UpdateParametre( _paramId,v ));
    } catch (...) {
    }
}


void CtrlParamLeaf::ValueChangedDirect(int p){

    CtrlValueLeaf::ValueChanged(p);
}

void CtrlParamLeaf::ValueChangedDirect(bool p)
{
    CtrlValueLeaf::ValueChanged(p);
}


void CtrlParamLeaf::forMulti(){

    _isProp = false;
    CtrlValueLeaf::init();
    directConnect();
}

void CtrlParamLeaf::synchronise(){
     UpdatedValueDirect(_valueMgr->getValue());
}
