#include "gradientsobel.h"

GradientSobel::GradientSobel()
{
}

Image2D<Vec2f> GradientSobel::gradient33(const Image2Grey& img_in)
{
    Vec2f z;
    Image2D<Vec2f> i(img_in.width(), img_in.height(), z);
    return i;
}

Image2D<Vec2f> GradientSobel::gradient55(const Image2Grey& img_in)
{
    Vec2f z;
    Image2D<Vec2f> i(img_in.width(), img_in.height(), z);

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

    for (std::size_t x = 0; x < img_in.width(); x++) {
        for (std::size_t y = 0; y < img_in.height(); y++) {
            if (x > 2 && y > 2) {
                i(x, y)[0] = 0;
                for (std::size_t x_ = -2; x_ < 3; x_++) {
                    for (std::size_t y_ = -2; y_ < 3; y_++) {
                        i(x, y)[0] += (float)(img_in(x + x_, y + y_) * Sobel5x[x + y * 5]);
                        i(x, y)[1] += (float)(img_in(x + x_, y + y_) * Sobel5y[x + y * 5]);
                    }
                }
            } else {

                i(x, y)[0] = (float)img_in(x, y);
                i(x, y)[1] = (float)img_in(x, y);
            }
        }
    }
    return i;
}
