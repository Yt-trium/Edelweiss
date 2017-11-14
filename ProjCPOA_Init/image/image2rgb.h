#ifndef IMAGE2RGB_H
#define IMAGE2RGB_H

#include <fstream>
#include <iostream>

#include "image2d.h"
#include "vector.h"

class Image2RGB : public Image2D<Vec3uc> {
public:
    /**
     * @brief Image2RGB
     * @param w
     * @param h
     */
    Image2RGB(int w, int h);

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
    friend std::ostream& operator<<(std::ostream& out, const Image2RGB& img);
    /**
     * @brief operator >>
     * @param in
     * @param img
     * @return
     */
    friend std::istream& operator>>(std::istream& in, Image2RGB& img);
};

#endif // IMAGE2RGB_H
