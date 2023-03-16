#ifndef WAVETABLESELECTVUE_H
#define WAVETABLESELECTVUE_H

#include "blofeldwavetablemgrmodel.h"
#include "wtmodel.h"
#include "easylist.h"

class WaveTableSelectVue
        :public EasyList
{
    Q_OBJECT
    WTModel * _model;
public:
    WaveTableSelectVue( WTModel * m,QWidget *parent )
        :EasyList("TABLES D'ONDE",m,parent)
        , _model(m)
    {
    }
    void disconnectAll();
    void connectAll(QWidget *p);
    QLayout * getLayout(){return &_layout;}

public slots:
    void ajouterTables();
    void envoyerTables(QModelIndex index );
    void effacerTables();
    void setTable(const BlofeldWaveTableMgrModel * a){emit envoyerTables(a);}
signals:
    void envoyerTables(const BlofeldWaveTableMgrModel * a);

};
#endif // WAVETABLESELECTVUE_H
