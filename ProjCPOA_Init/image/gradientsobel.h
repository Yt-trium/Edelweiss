#ifndef GRADIENTSOBEL_H
#define GRADIENTSOBEL_H

#include "image2grey.h"
#include "vector.h"

class GradientSobel {
public:
    GradientSobel();

    const int Sobel5x[25] = { 1, 2, 0, -2, -1,
        4, 8, 0, -8, -4,
        6, 12, 0, -12, -6,
        4, 8, 0, -8, -4,
        1, 2, 0, -2, -1 };

    const int Sobel5y[25] = { 1, 4, 6, 4, 1,
        2, 8, 12, 8, 2,
        0, 0, 0, 0, 0,
        -2, -8, -12, -8, -2,
        -1, -4, -6, -4, -1 };

    static Image2D<Vec2f> gradient33(const Image2Grey& img_in);
    static Image2D<Vec2f> gradient55(const Image2Grey& img_in);
};

#endif // GRADIENTSOBEL_H
