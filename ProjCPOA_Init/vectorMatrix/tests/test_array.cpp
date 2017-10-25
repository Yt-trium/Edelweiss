#include <iostream>
#include <assert.h>

#include "array.h"

int main()
{
    std::cout << "<TEST ARRAY> BEGIN" << std::endl;

    assert(1+1==2);

    Array<int,10> a1();

    std::cout << "<TEST ARRAY> END" << std::endl;

    return 0;
}
