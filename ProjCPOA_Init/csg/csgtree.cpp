#include "csgtree.h"

CsgTree::CsgTree()
{

}

void CsgTree::addPrimitive(CsgNode *n)
{
    this->CsgPrimitiveSet.insert(n);
}
