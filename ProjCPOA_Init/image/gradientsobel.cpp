#include "gradientsobel.h"

GradientSobel::GradientSobel()
{
}
Image2D<Vec2f> GradientSobel::gradient33(const Image2Grey& img_in)
{
}

Image2D<Vec2f> GradientSobel::gradient55(const Image2Grey& img_in)
{
    Vec2f z;
    Image2D<Vec2f> i(img_in.width(), img_in.height(), z);

    for (std::size_t x = 0; x < img_in.width(); x++) {
        for (std::size_t y = 0; y < img_in.height(); y++) {
            i(x, y)[0] = (float)img_in(x, y);
            i(x, y)[1] = (float)img_in(x, y);
        }
    }

    // Sobel5x
    // Sobel5y
    return i;
}
