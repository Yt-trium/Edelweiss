#ifndef CSGTREE_H
#define CSGTREE_H

#include <set>

#include "csgnode.h"

class CsgTree
{
public:
    CsgTree();

    void addPrimitive(CsgNode *n);

private:
    std::set<CsgNode*> CsgPrimitiveSet;
};

#endif // CSGTREE_H
