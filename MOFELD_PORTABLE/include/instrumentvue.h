#ifndef INSTRUMENTVUE_H
#define INSTRUMENTVUE_H

#include "instrument.h"
#include "instrumentmodel.h"
#include "easylist.h"
#include "blofeldreplica.h"

class InstrumentVue:public EasyList
{
    Q_OBJECT

//    Instrument _edition;
    InstrumentModel * _model;
public:
    InstrumentVue( InstrumentModel * m ,QWidget *parent)
        :EasyList("INSTRUMENT",m,parent), _model(m)
    {
        setupModel();
        setLayout(_layout);
    }
    void connectAll(QWidget *);
public slots:
    void ajouterInstrument();
    void effacerInstrument();
    void envoyerInstrument(QModelIndex index );
signals:
    void envoyerInstrument(const Instrument * a);

};


#endif // INSTRUMENTVUE_H
