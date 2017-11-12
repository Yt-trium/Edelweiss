#ifndef IMAGE2RGB_H
#define IMAGE2RGB_H

#include <fstream>
#include <iostream>

#include "image2d.h"
#include "vector.h"

class Image2RGB : public Image2D<Vec3uc> {
public:
    Image2RGB(int w, int h);

    // I/O
    void save(std::string filename);
    void load(std::string filename);
    friend std::ostream& operator<<(std::ostream& out, const Image2RGB& img);
    friend std::istream& operator>>(std::istream& in, Image2RGB& img);
};

#endif // IMAGE2RGB_H
