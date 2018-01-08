#ifndef CSGTREE_H
#define CSGTREE_H

#include <set>

#include "csgprimitive.h"

class CsgTree
{
public:
    CsgTree();

    void addPrimitive(CsgPrimitive p);

private:
    std::set<CsgPrimitive> CsgPrimitiveSet;
};

#endif // CSGTREE_H
