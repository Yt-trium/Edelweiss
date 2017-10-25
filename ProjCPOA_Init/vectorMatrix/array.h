#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

template<class T, std::size_t N>
class Array
{
public:
    Array();

private:
    T array[N];
    std::size_t length;
};


template<class T, std::size_t N>
Array<T,N>::Array()
: length(N)
{
    for(int i=0;i<N;i++)
        array[i]=0;
}


#endif // ARRAY_H
