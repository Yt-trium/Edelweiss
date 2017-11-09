#ifndef IMAGE2D_H
#define IMAGE2D_H

#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>

template <class T>
class Image2D {
protected:
    T* pixels_;
    int w_;
    int h_;

public:
    // constructor
    Image2D(int w, int h)
        : w_(w)
        , h_(h)
    {
        pixels_ = new T[w * h];
    }
    ~Image2D()
    {
        delete[] pixels_;
    }

    Image2D(const Image2D& i) = delete;

    int width() const { return w_; }
    int height() const { return h_; }
};

#endif // IMAGE2D_H
