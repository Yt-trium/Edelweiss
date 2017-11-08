#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <stdexcept>

template <class T, std::size_t N>
class Array {
public:
    // constructor
    Array()
        : length(N)
        , array{ 0, 0 }
    {
    }
    Array(T a[N])
        : length(N)
    {
        for (std::size_t i = 0; i < N; i++)
            array[i] = a[i];
    }

    // operator
    T const& operator[](std::size_t n) const
    {
        // std::cout << "T const &operator[](std::size_t n) const" << std::endl;
        if (n >= N)
            throw std::out_of_range("Array - operator[]");
        ;
        return array[n];
    }
    T& operator[](std::size_t n)

    {
        // std::cout << "T &operator[](std::size_t n)" << std::endl;
        if (n >= N)
            throw std::out_of_range("Array - operator[]");
        ;
        return array[n];
    }
    bool operator==(const Array<T, N>& a1) const
    {
        for (std::size_t i = 0; i < N; i++)
            if (a1[i] != array[i])
                return false;
        return true;
    }
    template <class T2, std::size_t N2>
    friend bool operator==(const Array<T2, N2>& a1, const Array<T2, N2>& a2);

    // getter
    const T* get_data() const { return array; }

    // swapper
    void swapArray(Array<T, N>& a) { std::swap(a.array, this->array); }

protected:
    std::size_t length;
    T array[N];
};

template <class T, std::size_t N>
bool operator==(const Array<T, N>& a1, const Array<T, N>& a2)
{
    for (std::size_t i = 0; i < N; i++)
        if (a1[i] != a2[i])
            return false;
    return true;
}

#endif // ARRAY_H
