#ifndef FRMFX_H
#define FRMFX_H

#include "client/Common/ctrlcomposite.h"
#include "defs.h"
class frmFX:
        public ctrlSection
{
    QVector<CtrlParamLeaf*> _leaves;
public:
    frmFX(const BlofeldReplica *synth, Instrument *instru,int fxNum, QString n, QWidget *parent);
    void setFX( int fxNum, int fxType);
    void hideAll();
private:
    static void leafModif(CtrlParamLeaf * leaf, QWidget * w, QString s);
    static void leafModif(CtrlParamLeaf * leaf, QString s);
    void initFX(int fxNum);
    void setFX_Chorus();
    void setFX_Flanger();
    void setFX_Phaser();
    void setFX_Overdrive();
    void setFX_TripleFX();
    void setFX_Delay();
    void setFX_ClckDelay();
    void setFX_Reverb();

};

#endif // FRMFX_H
