#ifndef CSGPRIMITIVE_H
#define CSGPRIMITIVE_H

#include "csgnode.h"

class CsgPrimitive : public CsgNode {
 public:
  CsgPrimitive(std::string l);
  CsgPrimitive(const CsgPrimitive& n);
};

#endif  // CSGPRIMITIVE_H
