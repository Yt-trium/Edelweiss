#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <cstddef>
#include <stdexcept>

#include "array.h"

template <class T, std::size_t N>
class Vector : public Array<T, N> {
public:
    // operator
    Vector& operator+=(const Vector& v)
    {
        for (std::size_t i = 0; i < N; i++) {
            (*this)[i] += v[i];
        }
        return *this;
    }
    friend Vector operator+(Vector v1, Vector const& v2)
    {
        v1 += v2;
        return v1;
    }
    Vector& operator-=(const Vector& v)
    {
        for (std::size_t i = 0; i < N; i++) {
            (*this)[i] -= v[i];
        }
        return *this;
    }
    friend Vector operator-(Vector v1, Vector const& v2)
    {
        v1 -= v2;
        return v1;
    }

    Vector& operator*=(const T& s)
    {
        for (std::size_t i = 0; i < N; i++) {
            (*this)[i] *= s;
        }
        return *this;
    }
    friend Vector operator*(Vector v1, T const& s1)
    {
        v1 *= s1;
        return v1;
    }
    friend Vector operator*(T const& s1, Vector v1)
    {
        v1 *= s1;
        return v1;
    }
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
    friend Vector operator/(Vector v1, T const& s1)
    {
        v1 /= s1;
        return v1;
    }
    // dot
    friend T operator*(Vector const& v1, Vector const& v2)
    {
        T s = 0;
        for (std::size_t i = 0; i < N; i++) {
            s += v1[i] * v2[i];
        }

        return s;
    }
    // cross
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

protected:
};

using Vec2f = Vector<float, 2>;
using Vec3f = Vector<float, 3>;
using Vec4f = Vector<float, 4>;
using Vec2i = Vector<int, 2>;
using Vec3i = Vector<int, 3>;
using Vec4i = Vector<int, 4>;

#endif // VECTOR_H
