#include "../inc/Vector.hpp"
#include <iostream>
#include <cassert>
int main()
{
    Vector<int> v1;

    v1.push_back(21);
    v1.push_back(8);
    v1.push_back(573);
    assert(v1.size() == 3);
    assert(v1[0] == 21);
    assert(v1[1] == 8);
    assert(v1[2] == 573);

    Vector<char> v2;
    v2.push_back('H');
    v2.push_back('e');
    v2.push_back('l');
    v2.push_back('l');
    v2.push_back('o');
    v2.push_back('!');
    v2.push_back('!');
    assert(v2.size() == 7);
    assert(v2[6] == '!');
    assert(v2[5] == v2[6]);

    Vector<int> v3{};
    v3.push_back(1);
    v3.push_back(10);
    v3.push_back(100);

    assert(v1 != v3);

    Vector v4(v1);
    assert(v1 == v4);

    Vector<char> v5(std::move(v2));
    assert(v5[0] == 'H');
    assert(v5[4] == 'o');
    assert(v5[5] == '!');
    assert(v5[6] == '!');


    std::cout << "MY VECTOR REALIXATION EXAMPLE MAIN FUNC" << std::endl;
    return 0;
}