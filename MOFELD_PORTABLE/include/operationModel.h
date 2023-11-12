#ifndef BLOFELDCOMMONMODEL_H
#define BLOFELDCOMMONMODEL_H

#include "targetprovider.h"

#include "defs.h"

class OperationModel
{
    TargetProvider * _target;
    int _bank;
    int _program;

public:

    OperationModel(TargetProvider* target);

private:
    friend class OperationVue;

};


#endif // BLOFELDCOMMONMODEL_H
