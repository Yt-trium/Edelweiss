#include "image2grey.h"

Image2Grey::Image2Grey(int w, int h)
    : Image2D(w, h, '0')
{
}

Image2Grey* Image2Grey::subSample()
{
    Image2Grey i(w_ / 2, h_ / 2);
    for (std::size_t x = 0; x < w_ / 2; x++) {
        for (std::size_t y = 0; y < h_ / 2; y++) {
            // (*i)(x, y) = this->pixels_[x * 2 + y * 2 * w_];
            i(x, y) = (*this)(x * 2, y * 2);
        }
    }
    Image2Grey* iptr;
    iptr = &i;

    return iptr;
}

void Image2Grey::save(std::string filename)
{
    std::ofstream f;
    f.open(filename);
    f << (*this);
    f.close();
}

void Image2Grey::load(std::string filename)
{
    std::ifstream f;
    f.open(filename);
    f >> (*this);
    f.close();
}

/*
 Un fichier pgm ASCII a pour nombre magique P2.
 Dans les données binaires de l'image, chaque pixel
 est codé par une valeur en caractères ASCII, précédée
 et suivie par un caractère d'espacement. Aucune
 ligne ne doit dépasser 70 caractères
 */
std::ostream& operator<<(std::ostream& out, const Image2Grey& img)
{
    out << "P2" << std::endl;
    out << img.width() << " " << img.height() << std::endl;
    out << 255 << std::endl;

    std::size_t c = 0;
    for (std::size_t x = 0; x < img.width(); x++) {
        for (std::size_t y = 0; y < img.height(); y++) {
            out << img(x, y) << " ";
            if (++c > 16) {
                c = 0;
                out << std::endl;
            }
        }
        c = 0;
        out << std::endl;
    }

    return out;
}
// TODO
std::istream& operator>>(std::istream& in, Image2Grey& img)
{
    std::string tmp;
    std::size_t tw, th, m;
    in >> tmp;
    in >> tw;
    in >> th;
    in >> m;
    unsigned short ww;
    if (tmp == "P2" && tw == img.width() && th == img.height()) {
        for (std::size_t x = 0; x < img.width(); x++) {
            for (std::size_t y = 0; y < img.height(); y++) {
                // Error here
                in >> ww;
                // std::cout << ww << "-";
                img(x, y) = (unsigned char)ww;
            }
        }
    } else {
        throw std::logic_error("Image2Grey - load - load file error");
    }

    return in;
}
