#ifndef INSTRUMENTVUE_H
#define INSTRUMENTVUE_H

#include "instrument.h"
#include "instrumentmodel.h"
#include "easylist.h"

class InstrumentVue:public EasyList
{
    Q_OBJECT
    InstrumentModel * _model;
public:
    InstrumentVue( InstrumentModel * m ,QWidget *parent)
        :EasyList("INSTRUMENT",m,parent), _model(m)
    {}
    void connectAll(QWidget *);
public slots:
    void ajouterInstrument();
    void effacerInstrument();
    void envoyerInstrument(QModelIndex index );
signals:
    void sendInstrument(const Instrument * a);

};


#endif // INSTRUMENTVUE_H
