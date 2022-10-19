#include "paramcontext.h"
#include "parametre.h"

ParamContext::ParamContext(const Parametre *param)
    : _parametre(param)
{

    _restriction.setText("Restrict");
    _dmin.setOrientation(Qt::Vertical);
    _dmax.setOrientation(Qt::Vertical);
    _cbAddToProp.setText(tr("Add2Prop"));
    _lbMinTitle.setText("min.:");
    _lbMaxTitle.setText("max.:");
    _lbValueTitle.setText("val.:");

    _lbTitre.setText(*_parametre->getNom());

    int min =_parametre->getValue(0);
    int max =_parametre->getValue(127);
    _dmin.setRange(min,max);
    _dmax.setRange(min,max);


    QHBoxLayout * lyH0 = new QHBoxLayout();
    lyH0->addWidget(&_lbTitre );
    lyH0->addWidget(&_lbValue);
    QVBoxLayout * lyV1 = new QVBoxLayout();
    lyV1->addWidget(&_dmin);
    lyV1->addWidget(&_lbMinTitle);
    lyV1->addWidget(&_lbMinValue);
    QVBoxLayout * lyV2 = new QVBoxLayout();
    lyV2->addWidget(&_dmax);
    lyV2->addWidget(&_lbMaxTitle);
    lyV2->addWidget(&_lbMaxValue);
    QHBoxLayout * lyH1 = new QHBoxLayout();
    lyH1->addLayout(lyV1);
    lyH1->addLayout(lyV2);

    QVBoxLayout *lyContrainte  = new QVBoxLayout;
    lyContrainte->addLayout(lyH0);
    lyContrainte->addWidget(&_cbAddToProp);
    lyContrainte->addLayout(lyH1);
    lyContrainte->addWidget(&_restriction);

    QGroupBox *_wContainer3   = new QGroupBox("Contrainte Paramètre");
    _wContainer3->setLayout(lyContrainte);

    _layout  = new QVBoxLayout;
    _layout->addWidget(_wContainer3);

    setLayout(_layout);
    //INITIALISATION SIGNAUX
    connect(&_cbAddToProp,SIGNAL(toggled(bool)),this,SLOT(setPropriete(bool)));
    connect(&_dmin,SIGNAL(valueChanged(int)),this,SLOT(setMin(int)));
    connect(&_dmax,SIGNAL(valueChanged(int)),this,SLOT(setMax(int)));
    connect(&_restriction,SIGNAL(clicked()),this,SLOT(restrict2Value()));

    updateForm(_parametre);
//    emit updateMe(pid,this);
}


ParamContext::~ParamContext(){

}


void ParamContext::restrict2Value()
{
    emit restrict2Value(_parametre->getID(),this);
}

void ParamContext::setPropriete(bool isprop)
{
    emit setPropriete(_parametre->getID(),isprop,this);
}

void ParamContext::setMin(int value)
{
    emit setMinimum(_parametre->getID(),value,this);
}

void ParamContext::setMax(int value)
{
    emit setMaximum(_parametre->getID(),value,this);
}


void ParamContext::updateForm(const Parametre *param)
{
    _parametre = param;

    _cbAddToProp.setChecked(_parametre->getProp());

    int min = _parametre->getContrainte()->getMinValue();
    int max = _parametre->getContrainte()->getMaxValue();

    _dmin.setValue(min);
    _dmax.setValue(max);

    _lbMinValue.setText(QString::number(min));
    _lbMaxValue.setText(QString::number(max));
    QString s = _parametre->getType()->getNameOfElement(_parametre->getValue());
    _lbValue.setText(s);
}
