#include "easylist.h"

EasyList::EasyList(QString wname ,ICategorizable * m,QWidget *parent)
    :_modelEntity(m),QWidget(parent)
{
//    ui.setupUi(this);
    lbCollecMgrTitle = new QLabel;
    lbCollecMgrTitle->setText(wname);
    setWindowFlags(  Qt::WindowStaysOnTopHint);
//    setWindowFlags(Qt::CustomizeWindowHint |  Qt::WindowStaysOnTopHint);
}

int EasyList::getSelectedRow(){
    QItemSelectionModel *selectionModel = _tvEntity->selectionModel();
    QModelIndexList indexes = selectionModel->selectedRows();
    QModelIndex index;

    foreach (index, indexes) {
        int row = _proxy->mapToSource(index).row();
        return row;
    }
    throw("aucune selection");
}

int EasyList::getId()
{
    int id;
    QItemSelectionModel *selectionModel = _tvEntity->selectionModel();
    QModelIndexList indexes = selectionModel->selectedRows();
    QModelIndex index, i;

    foreach (index, indexes) {
        int row = _proxy->mapToSource(index).row();
        i = _modelEntity->index(row, 2, QModelIndex());
        QVariant varName = _modelEntity->data(i, Qt::DisplayRole);
        id = varName.toInt();
        //retourner le premier trouvé
        return id;
    }
    return (-1);
}

void EasyList::setupModel(){


    _proxy = new QSortFilterProxyModel(this);
    _proxy->setSourceModel(_modelEntity);
    _proxy->setDynamicSortFilter(true);
//        configuration du proxy
            _proxy->setFilterKeyColumn(0);
            _proxy->sort(0, Qt::AscendingOrder);
    _tvEntity = new QTableView();
    _tvEntity->setModel(_proxy);
    _tvEntity->setSelectionBehavior(QAbstractItemView::SelectRows);
    _tvEntity->horizontalHeader()->setStretchLastSection(true);
//        _tvEntity->horizontalHeader()->hide();
    _tvEntity->verticalHeader()->hide();
    _tvEntity->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _tvEntity->setSelectionMode(QAbstractItemView::SingleSelection);
    _tvEntity->setSortingEnabled(true);
    _tvEntity->setColumnHidden(2, true);
    QSize buttonSize(30,20);
    _leEntity = new QLineEdit;
    _btnEntityAdd = new QPushButton(QIcon(),"+");
    _btnEntityAdd->setText("+");
    _btnEntityAdd->setFixedSize(buttonSize);

    _btnEntityRemove = new QPushButton(QIcon(),"-");
    _btnEntityRemove->setText("-");
    _btnEntityRemove->setFixedSize(buttonSize);

    _leNewCatName = new QLineEdit;
    _cbCurrentCategory = new  QComboBox;
    _btnCleanCats= new QPushButton(QIcon(),"+"); ;
    _btnCleanCats->setText("+");
    _btnCleanCats->setFixedSize(buttonSize);

    QHBoxLayout *lyMethod1 = new QHBoxLayout;
    lyMethod1->addWidget(_leEntity);
    lyMethod1->addWidget(_btnEntityRemove);
    lyMethod1->addWidget(_btnEntityAdd);

    QHBoxLayout *lyMethod2 = new QHBoxLayout;
    lyMethod2->addWidget(_cbCurrentCategory);
    lyMethod2->addWidget(_leNewCatName);
    lyMethod2->addWidget(_btnCleanCats);

    _layout = new QVBoxLayout;
    _layout->addWidget(lbCollecMgrTitle);
    _layout->addWidget(_tvEntity);
    _layout->addLayout(lyMethod1);
    _layout->addLayout(lyMethod2);

    _cbCurrentCategory->addItems(_modelEntity->getCatsName());

    setWindowTitle(*(_modelEntity->getTypeName()));

}

void EasyList::resetCategory(){
    disconnectAll();
    _cbCurrentCategory->clear();
    _cbCurrentCategory->addItems(_modelEntity->getCatsName());
    connectEList();
}

void EasyList::setCategory(int id){
    _modelEntity->setCategory(id);
}

void EasyList::connectEList(){
    connect(_btnCleanCats,SIGNAL(clicked()),
            this,SLOT(addCategory()));

    connect(_cbCurrentCategory,SIGNAL(currentIndexChanged(int)),
            this,SLOT(setCategory(int)));
}

void EasyList::disconnectAll(){
    disconnect(_btnCleanCats,SIGNAL(clicked()), 0,0);

    disconnect(_cbCurrentCategory,SIGNAL(currentIndexChanged(int)),0,0);
}

