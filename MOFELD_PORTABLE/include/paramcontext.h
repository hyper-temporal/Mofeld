#ifndef CONTRAINTEVUE_H
#define CONTRAINTEVUE_H

#include <QCheckBox>
#include <QComboBox>
#include <QLayout>
#include <QGroupBox>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>

#include <combotool.h>

#include <QDial>
class Parametre;

class ParamContext
        :public QWidget
{
    Q_OBJECT

    QVBoxLayout *   _layout;

    QCheckBox _cbAddToProp;

    QLabel   _lbTitre;
    QLabel  _lbMinTitle;
    QLabel  _lbMinValue;
    QLabel  _lbMaxTitle;
    QLabel  _lbMaxValue;
    QLabel  _lbValueTitle;
    QLabel  _lbValue;

    QSlider _dmin,_dmax;
    QPushButton _restriction;

    const Parametre *_parametre;

public:
    ParamContext(const Parametre *param);
    ~ParamContext();

signals:
    void restrict2Value(int,ParamContext*);
    void setPropriete(int,bool,ParamContext*);
    void setMinimum(int,int,ParamContext*);
    void setMaximum(int,int,ParamContext*);
    void updateMe(int,ParamContext*);

public slots:
    void updateForm(const Parametre *param);

private slots:
    void setMin(int value);
    void setMax(int value);
    void setPropriete(bool isprop);
    void restrict2Value();

};

#endif // CONTRAINTEVUE_H
