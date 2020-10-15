#ifndef EASYLIST_H
#define EASYLIST_H

#include "client/vues/edition/draggable.h"
#include <QGroupBox>
#include <QLayout>
#include <QLabel>
#include <QTableView>
#include <QItemSelection>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include  <QSortFilterProxyModel>
#include  <QHeaderView>

#include "genericity/entitydao.h"
#include "BlofeldMgr/arrangement.h"
#include "BlofeldMgr/instrument.h"
#include "BlofeldMgr/propriete.h"

class EasyList
        :public QWidget
{
    Q_OBJECT

protected:
//    Ui::frmCollectionMgnt ui;
    ICategorizable * _modelEntity;
//    QWidget * _parent;
    QSortFilterProxyModel * _proxy;
    QLabel *lbCollecMgrTitle;
    QVBoxLayout *   _layout;


    QTableView  *   _tvEntity;
    QPushButton *   _btnEntityAdd;
    QPushButton *   _btnEntityRemove;
    QLineEdit   *   _leEntity;

    QLineEdit * _leNewCatName;
    QComboBox * _cbCurrentCategory;
    QPushButton * _btnCleanCats;


    void connectEList();
    void disconnectAll();
public:
    EasyList(QString wname, ICategorizable * m, QWidget *parent);
    void setupModel();
    int getId();
    int getSelectedRow();
    void resetCategory();
    virtual QLayout * getLayout(){return _layout;}

private slots:
    void setCategory(int id);
    void addCategory(){ _modelEntity->addCategory(_leNewCatName->text()); resetCategory();}

};

#endif // EASYLIST_H
