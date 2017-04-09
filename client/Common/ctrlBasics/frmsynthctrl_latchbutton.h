#ifndef FRMSYNTHCTRL_LATCHBUTTON_H
#define FRMSYNTHCTRL_LATCHBUTTON_H

#include "../ctrlparamleaf.h"

class frmSynthCtrl_button
    :public CtrlParamLeaf
{
    Q_OBJECT

    bool _toggleIfTrue;
public:
    frmSynthCtrl_button(
            QWidget * parent,
            const BlofeldReplica *_synth,
            Parametre *param,
            bool toggleIfTrue=true,
            QBoxLayout::Direction d = QBoxLayout::LeftToRight
            );

    void setLayout();
    void UpdatedValueDirect(int value);
    void show();
    void hide();
private:
    void directConnect();
    void reconnecter();
    void deconnecter();
    void InitData();

};


#endif // FRMSYNTHCTRL_LATCHBUTTON_H
