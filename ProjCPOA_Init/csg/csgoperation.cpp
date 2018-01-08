#include "csgoperation.h"

CsgOperation::CsgOperation(std::string l, CsgOperationType op, CsgNode *n1,
                           CsgNode *n2)
    : CsgNode(l) {
  this->type = op;
  this->left = n1;
  this->right = n2;
}

CsgOperation::CsgOperation(const CsgOperation &n) : CsgNode(n) {
  this->type = n.type;
  this->left = n.left;
  this->right = n.right;
}

CsgNode *CsgOperation::getLeft() { return this->left; }

CsgNode *CsgOperation::getRight() { return this->right; }
