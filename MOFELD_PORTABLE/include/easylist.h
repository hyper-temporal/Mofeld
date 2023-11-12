#ifndef EASYLIST_H
#define EASYLIST_H

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

#include "icategorizable.h"

class EasyList
        :public QWidget
{
    Q_OBJECT

protected:
    ICategorizable * _modelEntity;
    QSortFilterProxyModel _proxy;
    QLabel lbCollecMgrTitle;
    QVBoxLayout _layout;


    QTableView  _tvEntity;
    QPushButton _btnEntityAdd;
    QPushButton _btnEntityRemove;
    QLineEdit  _leEntity;

    QLineEdit _leNewCatName;
    QComboBox _cbCurrentCategory;
    QPushButton _btnCleanCats;

    void setupModel();

    void disconnectEList();
    void connectEList();
public:
    EasyList(QString wname, ICategorizable * m, QWidget *parent);
    int getId();
    int getSelectedRow();
    void resetCategory();
    virtual QLayout * getLayout(){return &_layout;}

private slots:
    void setCategory(int id);
    void addCategory(){
        _modelEntity->addCategory(_leNewCatName.text());
        resetCategory();
    }

};

#endif // EASYLIST_H
