#ifndef FRMSYNTHCTRL_H
#define FRMSYNTHCTRL_H

#include <QPainter>
#include <QSpinBox>
#include <QGridLayout>
#include <QSplitter>
#include <QComboBox>
#include <QDial>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include "ctrlcomponent.h"


//Leaf
class ctrlleaf
    :public ctrlComponent
{
    Q_OBJECT
protected:
    QWidget * _parent;
    QWidget * _controle;
    QLabel  _lbTitre;
    QSpinBox  _sbValeur;
 public:

    ctrlleaf(   QWidget * parent,
                QWidget *enfant,
                QBoxLayout::Direction direction)
        :ctrlComponent(parent,direction),
          _parent(parent),
          _controle(enfant)
    {}

//    void addCtrl(ctrlComponent * l){}
    virtual void setLayout() =0;
    virtual void UpdatedValue(int value)=0;

private:
    virtual void deconnecter()=0;
    virtual void reconnecter()=0;
protected slots:
    virtual void ValueChanged(int p)=0;
    virtual void ValueChangedOffset(int p)=0;
    virtual void ValueChanged(bool p)=0;

    friend class ctrlcomposite;

};




#endif // FRMSYNTHCTRL_H
