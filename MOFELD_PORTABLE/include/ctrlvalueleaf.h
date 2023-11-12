#ifndef CTRLVALUELEAF_H
#define CTRLVALUELEAF_H


#include <QMenu>
#include "ctrlleaf.h"
#include "targetprovider.h"


class CtrlValueLeaf
        :public ctrlleaf
{
    Q_OBJECT

protected:
    int _pid;
    VAccessor _accessor ;
    TargetProvider* _target;
 public:

    CtrlValueLeaf(QWidget * parent,
                QWidget * enfant,
                int pid,
                QBoxLayout::Direction direction,
                TargetProvider * prov,
                VAccessor accessor);

    void addCtrl(ctrlComponent * ){}
    virtual void setLayout() =0;
    virtual void UpdatedValueDirect(int value)=0;
    void show();
    void hide();
protected:
    void init(void);

private:
    virtual void deconnecter()=0;
    virtual void reconnecter()=0;
protected slots:
    virtual void ValueChanged(int p);
    virtual void ValueChangedOffset(int p){}
    virtual void ValueChanged(bool p);


    friend class ctrlcomposite;
};
#endif // CTRLVALUELEAF_H
