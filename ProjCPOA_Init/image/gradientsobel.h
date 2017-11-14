#ifndef GRADIENTSOBEL_H
#define GRADIENTSOBEL_H

#include "image2grey.h"
#include "vector.h"

class GradientSobel {
public:
    GradientSobel();

    /**
     * @brief gradient33
     * @param img_in
     * @return
     */
    static Image2D<Vec2f> gradient33(const Image2Grey& img_in);
    /**
     * @brief gradient55
     * @param img_in
     * @return
     */
    static Image2D<Vec2f> gradient55(const Image2Grey& img_in);
};

#endif // GRADIENTSOBEL_H
