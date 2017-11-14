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
    std::size_t w_;
    std::size_t h_;

public:
    // constructor
    Image2D(int w, int h)
        : w_(w)
        , h_(h)
    {
        pixels_ = new T[w * h];
        for (int a = 0; a < w * h; a++)
            pixels_[a] = 0;
    }
    Image2D(int w, int h, T i)
        : w_(w)
        , h_(h)
    {
        pixels_ = new T[w * h];
        for (int a = 0; a < w * h; a++)
            pixels_[a] = i;
    }
    ~Image2D()
    {
        delete[] pixels_;
    }

    // Image2D(const Image2D& i) = delete;
    /**
     * @brief width
     * @return
     */
    std::size_t width() const { return w_; }
    /**
     * @brief height
     * @return
     */
    std::size_t height() const { return h_; }
    /**
     * @brief data
     * @return
     */
    T* data() { return pixels_; }
    /**
     * @brief operator ()
     * @param i
     * @param j
     * @return
     */
    T& operator()(int i, int j) { return pixels_[i + j * w_]; }
    /**
     * @brief operator ()
     * @param i
     * @param j
     * @return
     */
    const T& operator()(int i, int j) const { return pixels_[i + j * w_]; }
    /**
     * @brief swap_pixels
     * @param im
     */
    void swap_pixels(Image2D<T>& im)
    {
        assert(im.width() == this->width() && im.height() == this->height());
        std::swap(im.pixels_, this->pixels_);
    }
    /**
     * @brief crop
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     * @return
     */
    Image2D<T>* crop(std::size_t x1, std::size_t y1, std::size_t x2, std::size_t y2)
    {
        if (x1 > x2 || y1 > y2)
            throw std::logic_error(
                "Image2D - crop - top left corner > down right corner");
        if (x1 < 0 || y1 < 0)
            throw std::out_of_range(
                "Image2D - crop - top left corner");
        if (x2 > this->width() || y1 > this->height())
            throw std::out_of_range(
                "Image2D - crop - down right corner");

        Image2D<T>* i = new Image2D<T>(x2 - x1, y2 - y1);

        std::size_t xi = 0;
        std::size_t yi = 0;

        for (std::size_t x = x1; x < x2; x++) {
            for (std::size_t y = y1; y < y2; y++) {
                (*i)(xi, yi) = this->pixels_[x + y * w_];
                yi++;
            }
            xi++;
        }
        return i;
    }
};

#endif // IMAGE2D_H
