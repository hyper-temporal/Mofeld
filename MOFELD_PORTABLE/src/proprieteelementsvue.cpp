#include "proprieteelementsvue.h"
ProprieteElementsVue::ProprieteElementsVue(ProprieteModel *pr, QWidget *parent)
    :QWidget(parent),_model(pr)
{
    setWindowFlags(Qt::CustomizeWindowHint);

    _lstPropsChannel = new QListWidget();
    _lstPropsChannel->setSelectionMode(QAbstractItemView::ExtendedSelection);

    _btnPropsRemove= new QPushButton(QIcon(),"-");
    _btnPropsRemove->setText("Rem.");


    QHBoxLayout * lyH0  = new QHBoxLayout;
    lyH0->addWidget(_btnPropsRemove);

    _layout  = new QVBoxLayout;
    _layout->addWidget(_lstPropsChannel);
    _layout->addLayout(lyH0);
    setLayout(_layout);
}

void ProprieteElementsVue::connectAll(QWidget * parent){
    connect(_btnPropsRemove,SIGNAL(clicked()),this,SLOT(deleteSelected()));
    connect(this,SIGNAL(deleteProprietes(QVector<int> )),parent,SLOT(deleteProprietes(QVector<int>)));
}

void ProprieteElementsVue::deleteSelected(){
    emit deleteProprietes(getSelectedProprietesChannel());
}


QVector<int>  ProprieteElementsVue::getSelectedProprietesChannel()
{
    QVector<int> li;
    foreach(QListWidgetItem * qit, _lstPropsChannel->selectedItems())
    {
        li.append(qit->data(Qt::UserRole).toInt());
    }
    return li;
}


void ProprieteElementsVue::setModel(const Propriete * prpch)
{
    _lstPropsChannel->clear();
    foreach(Parametre pbo, *prpch->getParametres()){
        displayPropElement(pbo,_lstPropsChannel);
    }
}

void ProprieteElementsVue::displayPropElement(const Parametre &p, QListWidget * lstW) const
{
    QListWidgetItem * ad = new QListWidgetItem(*p.getNom(), lstW );
    ad->setData(Qt::UserRole,p.getID());
    ad->setText(*p.getNom());
    lstW->addItem(ad);
}
