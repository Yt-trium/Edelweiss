#ifndef GRADIENTSOBEL_H
#define GRADIENTSOBEL_H

#include "image2grey.h"
#include "vector.h"

class GradientSobel {
public:
    GradientSobel();

    static Image2D<Vec2f> gradient33(const Image2Grey& img_in);
    static Image2D<Vec2f> gradient55(const Image2Grey& img_in);
};

#endif // GRADIENTSOBEL_H
