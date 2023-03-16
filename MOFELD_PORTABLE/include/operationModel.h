#ifndef BLOFELDCOMMONMODEL_H
#define BLOFELDCOMMONMODEL_H

#include "targetprovider.h"

#include "defs.h"
//sert a la visualisation des contraintes
class OperationModel
{
    TargetProvider * _target;
    int _bank;
    int _program;

public:

    OperationModel(TargetProvider* target);

    MixPropParams *getMixsPars(){return _target->getTarget()->editMixPars();}
    void setFlex(Meth_flexibility met){getMixsPars()->_meth_flex=met;}
    void setAuthProp(bool st){getMixsPars()->_modify_Props=st;}
    void setAuthStuff(bool st){getMixsPars()->_modify_Stuff=st;}
    void setAuthContrainte(bool st){getMixsPars()->_modify_Contr=st;}
    void setAuthValue(bool st){getMixsPars()->_modify_Val=st;}

private:
    friend class OperationVue;

};


#endif // BLOFELDCOMMONMODEL_H
