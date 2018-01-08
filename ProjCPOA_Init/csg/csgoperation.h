#ifndef CSGOPERATION_H
#define CSGOPERATION_H

#include "csgnode.h"

enum CsgOperationType {Union,Intersection,Complement};

class CsgOperation : public CsgNode
{
public:
    CsgOperation();
    CsgOperationType type;
};

#endif // CSGOPERATION_H
