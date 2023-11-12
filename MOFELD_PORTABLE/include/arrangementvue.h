#ifndef WARRANGEMENT_H
#define WARRANGEMENT_H

#include "arrangement.h"
#include "arrangementmodel.h"
#include "easylist.h"

class ArrangementVue
        :public EasyList
{
    Q_OBJECT
    ArrangementModel * _model;
public:
    ArrangementVue(ArrangementModel * m,QWidget *parent )
        :EasyList("ARRANGEMENT",m,parent), _model(m)
    {}
    void connectAll(QWidget *p);
public slots:
    void ajouterArrangement();
    void envoyerArrangement(QModelIndex index );
    void effacerArrangement();
signals:
    void envoyerArrangement(const Arrangement * a);

};

#endif // WARRANGEMENT_H
