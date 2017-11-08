#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <cmath>
#include <stdexcept>

#include "array.h"

template<class T, std::size_t N>
class Vector : public Array<T,N>
{
public:
    // operator
    Vector&  operator+= (const Vector& v)
    {
        for(std::size_t i = 0;i<N;i++)
        {
            (*this)[i] += v[i];
        }
        return *this;
    }
    friend Vector operator+ (Vector v1, Vector const &v2)
    {
        v1 += v2;
        return v1;
    }
    Vector&  operator-= (const Vector& v)
    {
        for(std::size_t i = 0;i<N;i++)
        {
            (*this)[i] -= v[i];
        }
        return *this;
    }
    friend Vector operator- (Vector v1, Vector const &v2)
    {
        v1 -= v2;
        return v1;
    }
    Vector&  operator*= (const T& s)
    {
        for(std::size_t i = 0;i<N;i++)
        {
            (*this)[i] *= s;
        }
        return *this;
    }
    friend Vector operator* (Vector v1, T const &s1)
    {
        v1 *= s1;
        return v1;
    }
    Vector&  operator/= (const T& s)
    {
        if(s == 0)
            throw std::overflow_error("Vector - operator/ - divide by zero exception");

        for(std::size_t i = 0;i<N;i++)
        {
            (*this)[i] /= s;
        }
        return *this;
    }
    friend Vector operator/ (Vector v1, T const &s1)
    {
        v1 /= s1;
        return v1;
    }

protected:

};

#endif // VECTOR_H
