#include <iostream>
#include <assert.h>

#include "array.h"

int main()
{
    std::cout << "<TEST ARRAY> BEGIN" << std::endl;

    assert(1 + 1 == 2);

    Array<int, 10> a1;

    int toto[3] = {1, 2, 8};
    Array<int, 3> a2(toto);
    std::cout << a2[0] << " - " << a2[1] << " - " << a2[2] << std::endl;
    // std::cout << a2[3] << std::endl; // std::out_of_range
    a2[0]++;
    std::cout << a2[0] << " - " << a2[1] << " - " << a2[2] << std::endl;

    Array<int, 3> a3;
    a3[0] = 1;
    a3[1] = 2;
    a3[2] = 8;

    std::cout << "a2 == a3 : " << (a2 == a3) << std::endl;
    if (a2 == a3)
        return false;

    a3[0]++;
    std::cout << "a2 == a3 : " << (a2 == a3) << std::endl;
    if (!(a2 == a3))
        return false;

    std::cout << "<TEST ARRAY> END" << std::endl;

    return 0;
}
