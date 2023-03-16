#ifndef FRMSYNTHCTRLCOMPONENT_H
#define FRMSYNTHCTRLCOMPONENT_H

#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QGridLayout>


//un client construit une interface en passant des ctrlcomposite a cette classe
//ceux ci sont
class ctrlComponent:
        public QWidget
 {

protected:
    QBoxLayout::Direction  _direction;
    QLayout * _layout;
public:

    //pour ajouter des ctrl en ligne H ou V
    ctrlComponent(
            QWidget * parent,
            QBoxLayout::Direction d)
        :QWidget(parent), _direction(d)
    {}
    virtual void addCtrl( ctrlComponent * l)=0;
    virtual void setLayout()=0;
    virtual void show()=0;
    virtual void hide()=0;

    void CompactLayout(QBoxLayout *layout);


};

#endif // FRMSYNTHCTRLCOMPONENT_H
