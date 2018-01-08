#ifndef CSGDISK_H
#define CSGDISK_H

#include "csgprimitive.h"

class CsgDisk : public CsgPrimitive
{
public:
    CsgDisk(std::string l);
    CsgDisk(const CsgDisk& n);
};

#endif // CSGDISK_H
