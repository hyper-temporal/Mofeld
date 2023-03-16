#ifndef FRMSYNTHCTRL_LATCHBUTTON_H
#define FRMSYNTHCTRL_LATCHBUTTON_H

#include "ctrlparamleaf.h"

//  -Latch Button
class frmSynthCtrl_button
    :public CtrlParamLeaf
{
    Q_OBJECT

    bool _toggleIfTrue;
public:
    frmSynthCtrl_button(
            QWidget * parent,
            TargetProvider *_synth,
            int pnum,
            VAccessor accessor,
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
