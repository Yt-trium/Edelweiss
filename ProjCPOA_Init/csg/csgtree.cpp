#include "csgtree.h"

CsgTree::CsgTree() {}

void CsgTree::addPrimitive(CsgNode *n) {
  this->CsgTreeSet.insert(n);
  this->CsgTreeMap.insert(std::pair<int, CsgNode *>(n->getid(), n));
}

void CsgTree::joinPrimitive(CsgNode *n) {
  std::set<CsgNode *>::iterator it;
  CsgOperation *op = static_cast<CsgOperation *>(n);

  it = this->CsgTreeSet.find(op->getRight());
  this->CsgTreeSet.erase(*it);

  it = this->CsgTreeSet.find(op->getLeft());
  this->CsgTreeSet.erase(*it);

  this->addPrimitive(n);
}

CsgNode *CsgTree::getNode(unsigned int id) {
  CsgNode *n;
  n = this->CsgTreeMap.find(id)->second;
  return n;
}

Image2RGB CsgTree::drawInImage() {
  Image2RGB i(1, 1);
  return i;
}
