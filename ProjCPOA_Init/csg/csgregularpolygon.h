#ifndef CSGREGULARPOLYGON_H
#define CSGREGULARPOLYGON_H

#include "csgprimitive.h"

class CsgRegularPolygon : public CsgPrimitive
{
public:
    CsgRegularPolygon(std::string l);
    CsgRegularPolygon(const CsgRegularPolygon& n);
};

#endif // CSGREGULARPOLYGON_H
