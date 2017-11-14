#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>

#include "array.h"

template <class T, std::size_t N>
class Vector : public Array<T, N> {
public:
    // operator
    /**
     * @brief operator +=
     * @param v
     * @return
     */
    Vector& operator+=(const Vector& v)
    {
        for (std::size_t i = 0; i < N; i++) {
            (*this)[i] += v[i];
        }
        return *this;
    }
    /**
     * @brief operator +
     * @param v1
     * @param v2
     * @return
     */
    friend Vector operator+(Vector v1, Vector const& v2)
    {
        v1 += v2;
        return v1;
    }
    /**
     * @brief operator -=
     * @param v
     * @return
     */
    Vector& operator-=(const Vector& v)
    {
        for (std::size_t i = 0; i < N; i++) {
            (*this)[i] -= v[i];
        }
        return *this;
    }
    /**
     * @brief operator -
     * @param v1
     * @param v2
     * @return
     */
    friend Vector operator-(Vector v1, Vector const& v2)
    {
        v1 -= v2;
        return v1;
    }
    /**
     * @brief operator *=
     * @param s
     * @return
     */
    Vector& operator*=(const T& s)
    {
        for (std::size_t i = 0; i < N; i++) {
            (*this)[i] *= s;
        }
        return *this;
    }
    /**
     * @brief operator *
     * @param v1
     * @param s1
     * @return
     */
    friend Vector operator*(Vector v1, T const& s1)
    {
        v1 *= s1;
        return v1;
    }
    /**
     * @brief operator *
     * @param s1
     * @param v1
     * @return
     */
    friend Vector operator*(T const& s1, Vector v1)
    {
        v1 *= s1;
        return v1;
    }
    /**
     * @brief operator /=
     * @param s
     * @return
     */
    Vector& operator/=(const T& s)
    {
        if (s == 0)
            throw std::overflow_error(
                "Vector - operator/ - divide by zero exception");

        for (std::size_t i = 0; i < N; i++) {
            (*this)[i] /= s;
        }
        return *this;
    }
    /**
     * @brief operator /
     * @param v1
     * @param s1
     * @return
     */
    friend Vector operator/(Vector v1, T const& s1)
    {
        v1 /= s1;
        return v1;
    }
    /**
     * @brief operator * (dot)
     * @param v1
     * @param v2
     * @return
     */
    friend T operator*(Vector const& v1, Vector const& v2)
    {
        T s = 0;
        for (std::size_t i = 0; i < N; i++) {
            s += v1[i] * v2[i];
        }

        return s;
    }
    /**
     * @brief operator ^ (cross)
     * @param v1
     * @param v2
     * @return
     */
    friend Vector operator^(Vector const& v1, Vector const& v2)
    {
        Vector<T, N> v;
        if (N == 3) {
            v[0] = (T)(v1[1] * v2[2]) - (T)(v1[2] * v2[1]);
            v[1] = (T)(v1[2] * v2[0]) - (T)(v1[0] * v2[2]);
            v[2] = (T)(v1[0] * v2[1]) - (T)(v1[1] * v2[0]);
        } else
            throw std::logic_error(
                "Vector - operator^ - cross in other than 3 dimensions");

        return v;
    }

    template <class T2, std::size_t N2>
    /**
     * @brief operator <<
     * @param out
     * @param v
     * @return
     */
    friend std::ostream& operator<<(std::ostream& out, const Vector<T2, N2>& v);

protected:
};

template <class T, std::size_t N>
std::ostream& operator<<(std::ostream& out, const Vector<T, N>& v)
{
    out << "(";

    for (std::size_t i = 0; i < N - 1; i++)
        out << v[i] << ",";
    out << v[N - 1];

    out << ")";
    return out;
}

using Vec2f = Vector<float, 2>;
using Vec3f = Vector<float, 3>;
using Vec4f = Vector<float, 4>;
using Vec2i = Vector<int, 2>;
using Vec3i = Vector<int, 3>;
using Vec4i = Vector<int, 4>;
using Vec3uc = Vector<unsigned char, 3>;

#endif // VECTOR_H
