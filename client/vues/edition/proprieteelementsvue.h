#ifndef PROPRIETEELEMENTSVUE_H
#define PROPRIETEELEMENTSVUE_H


//#include "client/vues/edition/draggable.h"
#include <QGridLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QComboBox>
#include <QListWidget>

#include "client/Models/proprietemodel.h"
#include "BlofeldMgr/blofchannel.h"

class ProprieteElementsVue
        :public QWidget
{
    Q_OBJECT

    QBoxLayout  * _layout;

    ProprieteModel * _model;
    QListWidget  *_lstPropsChannel;
    QPushButton  *_btnRandomise;
    QPushButton  *_btnFix;
    QPushButton  *_btnPropsRemove;
public:
    ProprieteElementsVue(ProprieteModel * pr,QWidget *parent);
    void setModel(const Propriete *prpch);
    void displayPropElement(const Parametre & p,QListWidget * lst)const;
    QLayout * getLayout(){return _layout;}
    void connectAll(QWidget * parent);

signals:
    void deleteProprietes(QVector<int> );
private slots:
    void deleteSelected();

private:
    QVector<int> getSelectedProprietesChannel();

};

#endif // PROPRIETEELEMENTSVUE_H
