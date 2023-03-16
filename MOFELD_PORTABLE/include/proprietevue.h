#ifndef PROPRIETEVUE_H
#define PROPRIETEVUE_H


#include "easylist.h"
#include "propriete.h"
#include "proprietemodel.h"
#include "easylist.h"
#include "QCheckBox"
#include "QComboBox"
#include "QListWidget"

class ProprieteVue
        :public EasyList
{
    Q_OBJECT

    ProprieteModel * _model;
public:
    ProprieteVue( ProprieteModel * m,QWidget *parent )
        :EasyList("PROPRIETE",m,parent), _model(m)
    {
    }
    void connectAll(QWidget * parent);


public slots:
    void ajouterPropriete();
    void effacerPropriete();
    void envoyerPropriete(QModelIndex index );
signals:
    void sendPropriete(const Propriete * a);

};


#endif // PROPRIETEVUE_H
