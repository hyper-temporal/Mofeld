#include "easylist.h"

#include <arrangement.h>
#include <instrument.h>
#include <propriete.h>
#include <draggable.h>

EasyList::EasyList(
        QString wname ,
        ICategorizable * m,
        QWidget *parent)
    :QWidget(parent)
    ,_modelEntity(m)
    ,_proxy(this)
    ,lbCollecMgrTitle()
    ,_btnEntityAdd(QIcon(),"+")
   , _btnEntityRemove(QIcon(),"-")
    ,_btnCleanCats(QIcon(),"+")

{
    lbCollecMgrTitle.setText(wname);
    setWindowFlags(  Qt::WindowStaysOnTopHint);
    setupModel();
    setLayout(&_layout);
}

int EasyList::getSelectedRow(){
    QItemSelectionModel *selectionModel = _tvEntity.selectionModel();
    QModelIndexList indexes = selectionModel->selectedRows();
    QModelIndex index;

    foreach (index, indexes) {
        int row = _proxy.mapToSource(index).row();
        return row;
    }
    throw("aucune selection");
}

int EasyList::getId()
{
    int id;
    QItemSelectionModel *selectionModel = _tvEntity.selectionModel();
    QModelIndexList indexes = selectionModel->selectedRows();
    QModelIndex index, i;

    foreach (index, indexes) {
        int row = _proxy.mapToSource(index).row();
        i = _modelEntity->index(row, 2, QModelIndex());
        QVariant varName = _modelEntity->data(i, Qt::DisplayRole);
        id = varName.toInt();
        return id;
    }
    return (-1);
}

void EasyList::setupModel()
{
    _proxy.setSourceModel(_modelEntity);
    _proxy.setDynamicSortFilter(true);
    _proxy.setFilterKeyColumn(0);
    _proxy.sort(0, Qt::AscendingOrder);
    _tvEntity.setModel(&_proxy);
    _tvEntity.setSelectionBehavior(QAbstractItemView::SelectRows);
    _tvEntity.horizontalHeader()->setStretchLastSection(true);
    _tvEntity.verticalHeader()->hide();
    _tvEntity.setEditTriggers(QAbstractItemView::NoEditTriggers);
    _tvEntity.setSelectionMode(QAbstractItemView::SingleSelection);
    _tvEntity.setSortingEnabled(true);
    _tvEntity.setColumnHidden(2, true);
    QSize buttonSize(30,20);
    _btnEntityAdd.setText("+");
    _btnEntityAdd.setFixedSize(buttonSize);

    _btnEntityRemove.setText("-");
    _btnEntityRemove.setFixedSize(buttonSize);

    _btnCleanCats.setText("+");
    _btnCleanCats.setFixedSize(buttonSize);

    QHBoxLayout *lyMethod1 = new QHBoxLayout;
    lyMethod1->addWidget(&_leEntity);
    lyMethod1->addWidget(&_btnEntityRemove);
    lyMethod1->addWidget(&_btnEntityAdd);

    QHBoxLayout *lyMethod2 = new QHBoxLayout;
    lyMethod2->addWidget(&_cbCurrentCategory);
    lyMethod2->addWidget(&_leNewCatName);
    lyMethod2->addWidget(&_btnCleanCats);

    _layout.addWidget(&lbCollecMgrTitle);
    _layout.addWidget(&_tvEntity);
    _layout.addLayout(lyMethod1);
    _layout.addLayout(lyMethod2);

    _cbCurrentCategory.addItems(_modelEntity->getCatsName());

    setWindowTitle(*(_modelEntity->getTypeName()));
    setLayout(&_layout);
}

void EasyList::resetCategory(){
    disconnectEList();
    _cbCurrentCategory.clear();
    _cbCurrentCategory.addItems(_modelEntity->getCatsName());
    connectEList();
}

void EasyList::setCategory(int id){
    _modelEntity->setCategory(id);
}
void EasyList::disconnectEList(){
    disconnect(&_btnCleanCats,SIGNAL(clicked()));
    disconnect(&_cbCurrentCategory,SIGNAL(currentIndexChanged(int)));
}

void EasyList::connectEList(){
    connect(&_btnCleanCats,SIGNAL(clicked()),
            this,SLOT(addCategory()));

    connect(&_cbCurrentCategory,SIGNAL(currentIndexChanged(int)),
            this,SLOT(setCategory(int)));
}


