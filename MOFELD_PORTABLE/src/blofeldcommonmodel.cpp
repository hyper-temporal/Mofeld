#include "operationModel.h"

using namespace OperationProps;

OperationModel::OperationModel(BlofeldReplica *sy)
    :_synth(sy)
{
    _bank = 0;
    _program = 0;
}

