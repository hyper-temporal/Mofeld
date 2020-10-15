#include "ctrlcomposite.h"



ctrlComposite::ctrlComposite(QWidget * p,
                             QBoxLayout::Direction d)
    :ctrlComponent(p,d)
{}



ctrlComposite::~ctrlComposite(){
//    foreach(ctrlComponent * fsc,_ctrls){
//        delete fsc;
//    }
}


void ctrlComposite::addCtrl(ctrlComponent *c){
    _ctrls.append(c);
}

//retourne un layout (h ou v) qui contient les layouts de chaque controle
void ctrlComposite::setLayout(){

    QBoxLayout * layout = new QBoxLayout(_direction);
    layout->setSizeConstraint(QLayout::SetMinimumSize);

    foreach(ctrlComponent *cc,_ctrls)
    {
        cc->setLayout();
        layout->addWidget(cc);
    }
    CompactLayout(layout);
    QWidget::setLayout(layout) ;

}

void ctrlComposite::show(){
    foreach(ctrlComponent * c,_ctrls){
        c->show();
    }
}

void ctrlComposite::hide(){
    foreach(ctrlComponent * c,_ctrls){
        c->hide();
    }
}

QVector<CtrlParamLeaf *> ctrlComposite::getLeafs()
{
    QVector<CtrlParamLeaf *> comps;
    foreach(ctrlComponent  * compoz, _ctrls){
        CtrlParamLeaf * ctrlL= dynamic_cast<CtrlParamLeaf *>(compoz);
        if(ctrlL != NULL)
        {
            comps.append(ctrlL);
        }
        else {
            ctrlComposite * ctrlCz= dynamic_cast<ctrlComposite *>(compoz);
            if(ctrlCz != NULL){
                comps  += ctrlCz->getLeafs();
            }
        }
    }
    return comps;
}

void ctrlSection::setLayout(){
    ctrlComposite::setLayout();
    QGroupBox *gb = new QGroupBox;
    gb->setLayout(layout());
    gb->setTitle(_nom);
//    gb->setSizePolicy(QSizePolicy::Preferred , QSizePolicy::Preferred);
    QBoxLayout * bl = new QBoxLayout(QBoxLayout::TopToBottom);
    bl->setSizeConstraint(QLayout::SetMinimumSize);
    bl->addWidget(gb);
    CompactLayout(bl);
    QWidget::setLayout(bl) ;

}
