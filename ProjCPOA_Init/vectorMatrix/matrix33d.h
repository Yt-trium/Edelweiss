#ifndef MATRIX33D_H
#define MATRIX33D_H

#include <cmath>
#include <iostream>

#include "array.h"
#include "vector.h"

class Matrix33d {
public:
    Matrix33d();
    // operator [][]
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
    // [rows][columns]
    Matrix33dRow operator[](std::size_t row)
    {
        if (row >= 3)
            throw std::out_of_range("Matrix33d - operator[][]");

        return Matrix33dRow(*this, row);
    }
    /*
    double* operator[](std::size_t row)
    {
        return matrix[row];
    }
    */
    // operators
    friend bool operator==(const Matrix33d& m1, const Matrix33d& m2);
    friend std::ostream& operator<<(std::ostream& out, const Matrix33d& m);
    Matrix33d& operator*=(const Matrix33d& m)
    {
        for (std::size_t i = 0; i < 3; i++) {
            for (std::size_t j = 0; j < 3; j++) {
                for (std::size_t k = 0; k < 3; k++) {
                    (*this).matrix[i][j] += (*this).matrix[i][k] * m.matrix[k][j];
                }
            }
        }
        return *this;
    }
    friend Matrix33d operator*(Matrix33d m1, Matrix33d const& m2)
    {
        m1 *= m2;
        return m1;
    }
    friend Vec3f operator*(Matrix33d const& m1, Vec3f const& v1)
    {
        Vec3f v;
        for (std::size_t i = 0; i < 3; i++) {
            for (std::size_t j = 0; j < 3; j++) {
                v[i] += m1.matrix[i][j] * v1[j];
            }
        }
        return v;
    }
    friend Vec2f operator*(Matrix33d const& m1, Vec2f const& v1_)
    {
        Vec3f v1;
        v1[0] = v1_[0];
        v1[1] = v1_[1];
        v1[2] = 1;
        Vec3f vt;
        for (std::size_t i = 0; i < 3; i++) {
            for (std::size_t j = 0; j < 3; j++) {
                vt[i] += m1.matrix[i][j] * v1[j];
            }
        }
        Vec2f v;
        v[0] = vt[0] / vt[2];
        v[1] = vt[1] / vt[2];
        return v;
    }
    // public methods
    Matrix33d inverse();
    void translateM(double x, double y);
    void rotateM(double r);
    void scaleM(double sx, double sy);
    void applyTransformation(double* x, double* y);

    // static methods
    static Matrix33d identity();
    static Matrix33d translate(double x, double y);
    static Matrix33d rotate(double r);
    static Matrix33d scale(double sx, double sy);

private:
    double matrix[3][3];
};

#endif // MATRIX33D_H
