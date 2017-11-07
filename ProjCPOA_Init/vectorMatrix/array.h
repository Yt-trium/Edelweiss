#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <stdexcept>

template<class T, std::size_t N>
class Array
{
public:
    Array();
    Array(T a[N]);

    // operator
    T const &operator[](std::size_t n) const
    {
        // std::cout << "const T &operator[](std::size_t n) const" << std::endl;
        if (n >= N)
            throw std::out_of_range("Array - operator[]");;
        return array[n];
    }
    T &operator[](std::size_t n)
    {
        // std::cout << "T &operator[](std::size_t n)" << std::endl;
        if (n >= N)
            throw std::out_of_range("Array - operator[]");;
        return array[n];
    }
    bool operator==(const Array<T, N> &a1)
    {
        for (int i = 0; i < N; i++)
            if (a1[i] != array[i])
                return false;
        return true;
    }

private:
    T array[N];
    std::size_t length;
};

template<class T, std::size_t N>
Array<T, N>::Array()
    : length(N)
{
    for (int i = 0; i < N; i++)
        array[i] = 0;
}

template<class T, std::size_t N>
Array<T, N>::Array(T a[N])
    : length(N)
{
    for (int i = 0; i < N; i++)
        array[i] = a[i];
}


#endif // ARRAY_H
