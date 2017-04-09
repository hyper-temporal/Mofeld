#ifndef PARAMETREREACTION_H
#define PARAMETREREACTION_H

#include <QWidgetAction>
#include "./edition/paramcontext.h"

class CtrlParamLeaf;

class ParametreReAction
        : public QWidgetAction {

public:
    ParametreReAction (const Parametre *param) :
      QWidgetAction (NULL)
    {
        pParamVue=new ParamContext( param);
        setDefaultWidget(pParamVue);
    }

    ParamContext * getContext ()
    {
        return pParamVue;
    }

private:
    ParamContext * pParamVue;

};

#endif // PARAMETREREACTION_H
