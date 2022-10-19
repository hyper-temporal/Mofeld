#ifndef WARRANGEMENT_H
#define WARRANGEMENT_H

#include "arrangement.h"
#include "arrangementmodel.h"
#include "easylist.h"
#include "blofeldreplica.h"
class ArrangementVue
        :public EasyList
{
    Q_OBJECT
    ArrangementModel * _model;
//    QWidget * _parent;
public:
    ArrangementVue(ArrangementModel * m,QWidget *parent )
        :EasyList("ARRANGEMENT",m,parent), _model(m)
    {
        setupModel();
        setLayout(_layout);
    }
    void connectAll(QWidget *p);
    QLayout * getLayout(){return _layout;}
public slots:
    void ajouterArrangement();
    void envoyerArrangement(QModelIndex index );
    void effacerArrangement();
signals:
    void envoyerArrangement(const Arrangement * a);

};

#endif // WARRANGEMENT_H
