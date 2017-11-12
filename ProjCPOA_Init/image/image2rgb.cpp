#include "image2rgb.h"

Image2RGB::Image2RGB(int w, int h)
    : Image2D(w, h, Vec3uc())
{
}

void Image2RGB::save(std::string filename)
{
    std::ofstream f;
    f.open(filename);
    f << (*this);
    f.close();
}

void Image2RGB::load(std::string filename)
{
    std::ifstream f;
    f.open(filename);
    f >> (*this);
    f.close();
}

/*
 Un fichier ppm ASCII a pour nombre magique P3.
 Chaque pixel est codé en caractères ASCII,
 précédés et suivis par un caractère d'espacement.
 Aucune ligne ne doit dépasser 70 caractères.
 */
std::ostream& operator<<(std::ostream& out, const Image2RGB& img)
{
    out << "P3" << std::endl;
    out << img.width() << " " << img.height() << std::endl;
    out << 255 << std::endl;

    for (std::size_t x = 0; x < img.width(); x++) {
        for (std::size_t y = 0; y < img.height(); y++) {
            out << +img(x, y)[0] << " "
                << +img(x, y)[1] << " "
                << +img(x, y)[2] << " ";
            out << std::endl;
        }
    }

    return out;
}

std::istream& operator>>(std::istream& in, Image2RGB& img)
{
    std::string tmp;
    std::size_t tw, th, m;
    in >> tmp;
    in >> tw;
    in >> th;
    in >> m;
    unsigned short toto;
    Vec3uc ww;
    if (tmp == "P3" && tw == img.width() && th == img.height()) {
        for (std::size_t x = 0; x < img.width(); x++) {
            for (std::size_t y = 0; y < img.height(); y++) {
                /*
                in >> ww[0];
                in >> ww[1];
                in >> ww[2];
                */
                in >> toto;
                ww[0] = toto;
                in >> toto;
                ww[1] = toto;
                in >> toto;
                ww[2] = toto;
                img(x, y) = ww;
            }
        }
    } else {
        throw std::logic_error("Image2RGB - load - load file error");
    }

    return in;
}
