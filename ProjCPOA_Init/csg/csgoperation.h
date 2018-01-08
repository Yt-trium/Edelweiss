#ifndef CSGOPERATION_H
#define CSGOPERATION_H

#include "csgnode.h"

enum CsgOperationType { Union, Intersection, Complement };

class CsgOperation : public CsgNode {
 public:
  CsgOperation(std::string l, CsgOperationType op, CsgNode *n1, CsgNode *n2);
  CsgOperation(const CsgOperation &n);

  CsgNode *getLeft();
  CsgNode *getRight();

 protected:
  CsgOperationType type;
  CsgNode *left;
  CsgNode *right;
};

#endif  // CSGOPERATION_H
