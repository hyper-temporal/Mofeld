#ifndef CTRLPARAMLEAF_H
#define CTRLPARAMLEAF_H

#include <QMenu>
#include "ctrlvalueleaf.h"

//Type
class CtrlParamLeaf
    :public CtrlValueLeaf
{
    Q_OBJECT
protected:

    bool _isProp;
    bool _floatBased;
    bool _antialiased;
    int _frameNo;
    int _pixH, _pixV;

    const int _paramId;
    void paintEvent(QPaintEvent *event);
    void addCtrl(ctrlComponent * l){}

 public:

    CtrlParamLeaf(   QWidget * parent,
                QWidget * enfant,
                const BlofeldReplica *synth,
                Parametre *param,
                QBoxLayout::Direction direction);

    virtual void setLayout() =0;
    void AfterConstructor();
    int getParamId() const{return _paramId;}
    void UpdatedValue(int value){
        deconnecter();
        UpdatedValueDirect(value);
        reconnecter();
    }

    virtual void UpdatedValueDirect(int value )=0;
    void synchronise();

public slots:

    void setProprieteVue(bool isProp);

private:
    void forMulti();
    void initForInstrument(void);
    virtual void deconnecter()=0;
    virtual void reconnecter()=0;
    virtual void directConnect()=0;
protected slots:
    virtual void ValueChanged(int p);
    virtual void ValueChangedOffset(int p){}
    virtual void ValueChanged(bool p);

    virtual void ValueChangedOffsetDirect(int p){}
    virtual void ValueChangedDirect(int p);
    virtual void ValueChangedDirect(bool p);

    void ctxMenu(const QPoint &);

signals:
    void UpdateParametre(int pid, int value);
    void refreshContrainte(int pid);

    friend class ctrlcomposite;
    friend class BlofeldInstrumentVue;
    friend class BlofeldMultiVue;
    friend class frmFX;
};
#endif // CTRLPARAMLEAF_H
