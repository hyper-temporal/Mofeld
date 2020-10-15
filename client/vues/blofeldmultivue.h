#ifndef BLOFELDMULTIVUE_H
#define BLOFELDMULTIVUE_H

#include "client/Common/ctrlcomposite.h"
#include "client/vues/blofeld/multi/blofeldmultislice.h"

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
    BlofeldMultiVue(QWidget *parent, const BlofeldReplica *synth);

    void synchronise();
    void SetCBBMultiNum();
    void connection(QWidget *parent);
private slots:
    void multiRequest();
    void multiSend();
    void ShowSlice(int);
signals:
    void multiRequest(int);
    void multiSend(int);
};
#endif // BLOFELDMULTIVUE_H
