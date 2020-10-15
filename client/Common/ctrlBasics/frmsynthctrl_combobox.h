#ifndef FRMSYNTHCTRL_COMBOBOX_H
#define FRMSYNTHCTRL_COMBOBOX_H

#include "../ctrlparamleaf.h"


//  -combobox
class frmSynthCtrl_combobox
    :public CtrlParamLeaf
{

public:
    frmSynthCtrl_combobox( QWidget * parent,
                           const BlofeldReplica *_synth,
                           Parametre * param,
                           QBoxLayout::Direction d = QBoxLayout::TopToBottom
                           );
    void setLayout();

    void UpdatedValueDirect(int value);
    void show(){CtrlParamLeaf::show();}
    void hide(){CtrlParamLeaf::hide();}
private:
    void directConnect();
    void reconnecter();
    void deconnecter();
    void InitData();

};

#endif // FRMSYNTHCTRL_COMBOBOX_H
