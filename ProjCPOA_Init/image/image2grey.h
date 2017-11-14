#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H

#include <fstream>
#include <iostream>

#include "image2d.h"

class Image2Grey : public Image2D<unsigned char> {
public:
    /**
     * @brief Image2Grey
     * @param w
     * @param h
     */
    Image2Grey(int w, int h);
    /**
     * @brief subSample
     * @param img
     * @return
     */
    static Image2Grey* subSample(Image2Grey& img);
    /**
     * @brief smooth
     * @param img
     * @param n
     * @return
     */
    static Image2Grey* smooth(Image2Grey& img, int n);
    /**
     * @brief threshold
     * @param img
     * @param val
     * @return
     */
    static Image2Grey* threshold(Image2Grey& img, unsigned char val);

    // I/O
    /**
     * @brief save
     * @param filename
     */
    void save(std::string filename);
    /**
     * @brief load
     * @param filename
     */
    void load(std::string filename);
    /**
     * @brief operator <<
     * @param out
     * @param img
     * @return
     */
    friend std::ostream& operator<<(std::ostream& out, const Image2Grey& img);
    /**
     * @brief operator >>
     * @param in
     * @param img
     * @return
     */
    friend std::istream& operator>>(std::istream& in, Image2Grey& img);
};

#endif // IMAGE2GREY_H
