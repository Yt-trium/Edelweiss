#include "csgnode.h"

CsgNode::CsgNode(std::string l) {
  this->label = l;
  this->id = id_cpt++;
  this->parent = NULL;
}

CsgNode::CsgNode(const CsgNode &n) {
  this->label = n.label;
  this->id = n.id_cpt++;
  this->parent = n.parent;
}

CsgNode *CsgNode::getParent() { return this->parent; }

unsigned int CsgNode::getid() { return this->id; }

std::string CsgNode::getLabel() { return this->label; }

BoundingBox CsgNode::getBbox() { return this->bbox; }
