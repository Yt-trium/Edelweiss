#ifndef CSGTREE_H
#define CSGTREE_H

#include <map>
#include <set>

#include "csgnode.h"

class CsgTree {
 public:
  CsgTree();

  void addPrimitive(CsgNode *n);
  void joinPrimitive(CsgNode *n);

  CsgNode *getNode(unsigned int id);

 private:
  std::set<CsgNode *> CsgTreeSet;
  std::map<unsigned int, CsgNode *> CsgTreeMap;
};

#endif  // CSGTREE_H
