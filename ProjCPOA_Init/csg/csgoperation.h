#ifndef CSGOPERATION_H
#define CSGOPERATION_H

#include "csgnode.h"

enum CsgOperationType {Union,Intersection,Complement};

class CsgOperation : public CsgNode
{
public:
    CsgOperation(std::string l, CsgOperationType op, CsgNode *n1, CsgNode *n2);
    CsgOperation(const CsgOperation& n);

    CsgOperationType type;
};

#endif // CSGOPERATION_H
