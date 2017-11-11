#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H

#include <fstream>
#include <iostream>

#include "image2d.h"

class Image2Grey : public Image2D<unsigned char> {
protected:
    unsigned char pixels_;
    std::size_t w_;
    std::size_t h_;

public:
    Image2Grey(int w, int h);

    Image2Grey* subSample();

    // I/O
    void save(std::string filename);
    void load(std::string filename);
    friend std::ostream& operator<<(std::ostream& out, const Image2Grey& img);
    friend std::istream& operator>>(std::istream& in, Image2Grey& img);
};

#endif // IMAGE2GREY_H
