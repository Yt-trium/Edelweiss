#ifndef CSGPRIMITIVE_H
#define CSGPRIMITIVE_H

#include "csgnode.h"
#include "matrix33d.h"

class CsgPrimitive : public CsgNode {
 public:
  CsgPrimitive(std::string l);
  CsgPrimitive(const CsgPrimitive& n);

 protected:
  Matrix33d matrix;
};

#endif  // CSGPRIMITIVE_H
