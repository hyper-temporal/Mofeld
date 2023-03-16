#ifndef BLOFELDMULTIVUE_H
#define BLOFELDMULTIVUE_H

#include <QPushButton>
#include <QComboBox>
#include "blofeldmultislice.h"

class BlofeldMultiVue
        :public QWidget
{
    Q_OBJECT

    QPushButton *_pbImport;
    QPushButton *_pbExport;
    QComboBox   *_cbbMultiNum;

    const DumpMulti *_multiblob;
    QLayout * mainLayout;

    QVector<CtrlParamLeaf *> _controles;
    QVector<BlofeldMultiSlice * > _slices;
public:
    BlofeldMultiVue(QWidget *parent,  TargetProvider *synth);

    void synchronise();
    void SetCBBMultiNum();
    void connection(QWidget *parent);
    ValueMgr* accessor(TargetProvider *, int) ;

private slots:
    void multiRequest();
    void multiSend();
    void ShowSlice(int);
signals:
    void multiRequest(int);
    void multiSend(int);
};
#endif // BLOFELDMULTIVUE_H
