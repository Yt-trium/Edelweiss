#include "matrix33d.h"

Matrix33d::Matrix33d()
{
    for (std::size_t i = 0; i < 3; i++)
        for (std::size_t j = 0; j < 3; j++)
            matrix[i][j] = 0.0;
}

std::ostream& operator<<(std::ostream& out, const Matrix33d& m)
{
    out << m.matrix[0][0] << '\t' << m.matrix[0][1] << '\t' << m.matrix[0][2] << std::endl;
    out << m.matrix[1][0] << '\t' << m.matrix[1][1] << '\t' << m.matrix[1][2] << std::endl;
    out << m.matrix[2][0] << '\t' << m.matrix[2][1] << '\t' << m.matrix[2][2] << std::endl;
    return out;
}

Matrix33d Matrix33d::inverse()
{
    double det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2])
        - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
        + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    double invdet = 1 / det;

    Matrix33d inv; // inverse of matrix m
    inv[0][0] = (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) * invdet;
    inv[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) * invdet;
    inv[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) * invdet;
    inv[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) * invdet;
    inv[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) * invdet;
    inv[1][2] = (matrix[1][0] * matrix[0][2] - matrix[0][0] * matrix[1][2]) * invdet;
    inv[2][0] = (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]) * invdet;
    inv[2][1] = (matrix[2][0] * matrix[0][1] - matrix[0][0] * matrix[2][1]) * invdet;
    inv[2][2] = (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]) * invdet;

    return inv;
}

Matrix33d Matrix33d::identity()
{
    Matrix33d id;
    id[0][0] = 1.0;
    id[1][1] = 1.0;
    id[2][2] = 1.0;
    return id;
}

Matrix33d Matrix33d::translate(double x, double y)
{
    Matrix33d mt = Matrix33d::identity();
    mt[0][2] = x;
    mt[1][2] = y;
    return mt;
}

Matrix33d Matrix33d::rotate(double r)
{
    Matrix33d mr = Matrix33d::identity();
    mr[0][0] = cos(r);
    mr[0][1] = -sin(r);
    mr[1][0] = sin(r);
    mr[1][1] = cos(r);
    return mr;
}

Matrix33d Matrix33d::scale(double sx, double sy)
{
    Matrix33d ms = Matrix33d::identity();
    ms[0][0] = sx;
    ms[1][1] = sy;
    return ms;
}
