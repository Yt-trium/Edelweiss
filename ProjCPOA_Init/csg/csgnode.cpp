#include "csgnode.h"

CsgNode::CsgNode(std::string l)
{
    this->label = l;
    this->id = id_cpt++;
    this->parent = NULL;
}

CsgNode::CsgNode(const CsgNode &n)
{
    this->label = n.label;
    this->id = n.id_cpt++;
    this->parent = n.parent;
}
