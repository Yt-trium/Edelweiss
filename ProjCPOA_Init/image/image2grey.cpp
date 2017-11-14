#include "image2grey.h"

Image2Grey::Image2Grey(int w, int h)
    : Image2D(w, h, '0')
{
}

Image2Grey* Image2Grey::subSample(Image2Grey& img)
{
    std::size_t nx = img.width() / 2;
    std::size_t ny = img.height() / 2;
    Image2Grey* i = new Image2Grey(nx, ny);
    for (std::size_t x = 0; x < nx; x++) {
        for (std::size_t y = 0; y < ny; y++) {
            (*i)(x, y) = +img(x * 2, y * 2);
            // std::cout << +img(x * 2, y * 2) << " ";
        }
    }

    return i;
}

Image2Grey* Image2Grey::smooth(Image2Grey& img, int n)
{
    unsigned long average = 0;

    std::size_t nx = img.width();
    std::size_t ny = img.height();
    Image2Grey* i = new Image2Grey(nx, ny);

    for (std::size_t x = 0; x < nx; x++) {
        for (std::size_t y = 0; y < ny; y++) {
            for (int a = -n; a <= n; a++) {
                for (int b = -n; b <= n; b++) {
                    if ((x + a) < 0 || (y + b) < 0 || (x + a) > nx || (y + b) > ny)
                        average += 127;
                    else
                        average += img(x + a, y + b);
                }
            }
            (*i)(x, y) = (average / ((2 * n + 1) * (2 * n + 1)));
            average = 0;
        }
    }
    return i;
}

Image2Grey* Image2Grey::threshold(Image2Grey& img, unsigned char val)
{
    std::size_t nx = img.width();
    std::size_t ny = img.height();
    Image2Grey* i = new Image2Grey(nx, ny);

    for (std::size_t x = 0; x < nx; x++) {
        for (std::size_t y = 0; y < ny; y++) {
            if (img(x, y) < val)
                (*i)(x, y) = 0;
            else
                (*i)(x, y) = 255;
        }
    }
    return i;
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
            out << +img(x, y) << " ";
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
                in >> ww;
                img(x, y) = +(unsigned char)ww;
            }
        }
    } else {
        throw std::logic_error("Image2Grey - load - load file error");
    }

    return in;
}
