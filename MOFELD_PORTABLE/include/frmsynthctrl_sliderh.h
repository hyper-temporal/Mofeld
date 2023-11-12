#ifndef FRMSYNTHCTRL_SLIDERH_H
#define FRMSYNTHCTRL_SLIDERH_H

#include "ctrlparamleaf.h"

class frmSynthCtrl_Slider
    :public CtrlParamLeaf
{
public:
    frmSynthCtrl_Slider(
                        QWidget * parent,
                        TargetProvider *synth,
                         int pnum,
                        VAccessor accessor,
                        Qt::Orientation o = Qt::Vertical,
                        QBoxLayout::Direction d= QBoxLayout::TopToBottom
                          );

    virtual void setLayout();
    QLayout * getLayout();
    void UpdatedValueDirect(int value);
    void show();
    void hide();

private:
    void directConnect();
    void reconnecter();
    void deconnecter();
    void InitData();

protected slots:
    void ValueChanged(int v);
};


#endif // FRMSYNTHCTRL_SLIDERH_H
