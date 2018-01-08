#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "boundingbox.h"

float max(float a, float b);
float min(float a, float b);

class BoundingBox {
 private:
  float xmin, xmax, ymin, ymax;

 public:
  BoundingBox();

  BoundingBox operator+(BoundingBox b);
  BoundingBox operator^(BoundingBox b);
  BoundingBox operator-(BoundingBox b);

  void set(float xmin, float xmax, float ymin, float ymax);
};

#endif  // BOUNDINGBOX_H
