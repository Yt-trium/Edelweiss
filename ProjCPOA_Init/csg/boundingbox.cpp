#include "boundingbox.h"

float max(float a, float b) { return (a > b) ? a : b; }
float min(float a, float b) { return (a < b) ? a : b; }

BoundingBox::BoundingBox() {}

BoundingBox BoundingBox::operator+(BoundingBox b) {
  BoundingBox r;
  r.xmin = min(this->xmin, b.xmin);
  r.xmax = max(this->xmax, b.xmax);
  r.ymin = min(this->ymin, b.ymin);
  r.ymax = max(this->ymax, b.ymax);
  return r;
}

BoundingBox BoundingBox::operator^(BoundingBox b) {
  BoundingBox r;
  r.xmin = min(this->xmin, b.xmin);
  r.xmax = min(this->xmax, b.xmax);
  r.ymin = min(this->ymin, b.ymin);
  r.ymax = min(this->ymax, b.ymax);
  return r;
}

BoundingBox BoundingBox::operator-(BoundingBox b) {
  BoundingBox r;
  r.xmin = max(this->xmin, b.xmin);
  r.xmax = min(this->xmax, b.xmax);
  r.ymin = max(this->ymin, b.ymin);
  r.ymax = min(this->ymax, b.ymax);
  return r;
}

void BoundingBox::set(float xmin, float xmax, float ymin, float ymax) {
  this->xmin = xmin;
  this->xmax = xmax;
  this->ymin = ymin;
  this->ymax = ymax;
}
