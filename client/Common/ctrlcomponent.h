#ifndef FRMSYNTHCTRLCOMPONENT_H
#define FRMSYNTHCTRLCOMPONENT_H

#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QGridLayout>


class ctrlComponent:
        public QWidget
 {

protected:
    QBoxLayout::Direction  _direction;
    QLayout * _layout;
public:

    ctrlComponent(QWidget * parent, QBoxLayout::Direction d)
        :QWidget(parent), _direction(d)
    {}
    virtual void addCtrl( ctrlComponent * l)=0;
    virtual void setLayout()=0;
    virtual void show()=0;
    virtual void hide()=0;

    void CompactLayout(QBoxLayout *layout);


};

#endif // FRMSYNTHCTRLCOMPONENT_H
