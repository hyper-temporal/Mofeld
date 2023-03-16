#include "operationModel.h"


OperationModel::OperationModel(TargetProvider* target)
    :_target(target)
{
    _bank = 0;
    _program = 0;
}

