#include "csgoperation.h"

CsgOperation::CsgOperation(std::string l, CsgOperationType op, CsgNode *n1, CsgNode *n2)
    : CsgNode(l)
{

}

CsgOperation::CsgOperation(const CsgOperation &n)
    : CsgNode(n)
{

}
