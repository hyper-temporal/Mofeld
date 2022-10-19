#ifndef OPERATIONVUE_H
#define OPERATIONVUE_H

#include <QWidget>
#include <QLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QGroupBox>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include "operationModel.h"
#include "combotool.h"

class OperationVue:
        public QWidget
{
    Q_OBJECT

    QBoxLayout *   _layout;

    QComboBox   *cbb_channel,
                *cbb_Bank,
                *cbb_Program;
    QLineEdit *le_instrumentName;

    QCheckBox   *chb_importProp,
                *chb_importStuff,
                *chb_importValues,
                *chb_importContrainte;


    QGroupBox   *gb_GlobalCtrl,
                *gb_PropAndStuff,
                *gb_PropertyMethod_ch,
                *gb_PropertyMethod_instru;

    QRadioButton    *rb_force,
                    *rb_replace,
                    *rb_weak;

    QLineEdit *le_qssPath;
    QPushButton *btn_layoutUpdate;
    //TODO a implementer
    QLabel * lb_InstrumentName;
    QLineEdit *le_InstrumentNameEdit;
    QPushButton *pb_reImport,
                *pb_reGenerate;
    QPushButton *pb_sendMultiState;

    OperationModel *_model;
public:

    OperationVue(OperationModel *opMod,BlofeldReplica *_synth, QWidget *parent);
    ~OperationVue();
    void UpdateInstruName(QString s){le_instrumentName->setText(s);}

    void UpdateChannel();


private:
    void SetCbbBank();
    void SetCbbChannel();
    void SetCbbProgram();

private slots:
    void on_pbStyle_clicked();
    void on_cbBank_currentIndexChanged(int index);
    void on_cbPrgm_currentIndexChanged(int index);

    void SetCurrentOp_ch_Force();
    void SetCurrentOp_ch_Replace();
    void SetCurrentOp_ch_Weak();

    void setAuthProp();
    void setAuthStuff();
    void setAuthValue();
    void setAuthContrainte();

 signals:
    void updateStyle(QString s);
    void setPropriete_Channel();
    void setPropriete_Instrument();
    void Reimport();
    void Regenerate();
    void setChannel(int ch);
    void importInstrument(int bk,int pg);
};

#endif // OPERATIONVUE_H
