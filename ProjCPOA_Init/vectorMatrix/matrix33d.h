#ifndef MATRIX33D_H
#define MATRIX33D_H

#include <cmath>
#include <iostream>

#include "array.h"
#include "vector.h"

class Matrix33d {
public:
    Matrix33d();

    // proxy class for operator [][]
    class Matrix33dRow {
        friend class Matrix33d;

    public:
        double const& operator[](std::size_t col) const
        {
            if (col >= 3)
                throw std::out_of_range("Matrix33d - operator[][]");

            return parent.matrix[row][col];
        }
        double& operator[](std::size_t col)
        {
            if (col >= 3)
                throw std::out_of_range("Matrix33d - operator[][]");

            return parent.matrix[row][col];
        }

    private:
        Matrix33dRow(Matrix33d& parent_, std::size_t row_)
            : parent(parent_)
            , row(row_)
        {
        }

        Matrix33d& parent;
        std::size_t row;
    };
    // operator
    // [rows][columns]
    Matrix33dRow operator[](std::size_t row)
    {
        if (row >= 3)
            throw std::out_of_range("Matrix33d - operator[][]");

        return Matrix33dRow(*this, row);
    }
    friend std::ostream& operator<<(std::ostream& out, const Matrix33d& m);
    // public methods
    Matrix33d inverse();

    // static methods
    static Matrix33d identity();
    static Matrix33d translate(double x, double y);
    static Matrix33d rotate(double r);
    static Matrix33d scale(double sx, double sy);

private:
    double matrix[3][3];
};

#endif // MATRIX33D_H
