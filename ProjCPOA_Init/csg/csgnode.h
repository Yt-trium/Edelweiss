#ifndef CSGNODE_H
#define CSGNODE_H

#include <string>

#include "../vectorMatrix/vector.h"
#include "boundingbox.h"

class CsgNode {
 public:
  CsgNode(std::string l);
  CsgNode(const CsgNode &n);

  virtual bool Intersect(Vec2f v) = 0;
  virtual bool intersectBBox(Vec2f v) = 0;

  CsgNode *getParent();
  unsigned int getid();
  std::string getLabel();
  BoundingBox getBbox();

 protected:
  CsgNode *parent;
  unsigned int id;
  std::string label;
  BoundingBox bbox;

 private:
  static int id_cpt;
};

#endif  // CSGNODE_H
