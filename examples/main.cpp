#include "../inc/Vector.hpp"
#include <iostream>
#include <cassert>
#include <string>
int main()
{
    //Empty vector 
    Vector<int> e;
    assert(e.size() == 0);


    //Casuals usage test
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

    Vector<long> multi;
    for (size_t i = 0; i < 1000; i++)
    {
        multi.push_back(i);
    }
    assert(multi.size() == 1000);

    for (size_t i = 0; i < 1000; i++)
    {
        assert(multi[i] == i);
    }
    
    Vector<std::string> str_vec;
    str_vec.push_back("Some");
    str_vec.push_back("string !!!!");
    assert(str_vec[0] == "Some");
    assert(str_vec[1] == "string !!!!");


    //Copy constructor
    Vector v4(v1);
    assert(v1 == v4);

    //Move constructor
    Vector<char> v5(std::move(v2));
    assert(v5[0] == 'H');
    assert(v5[4] == 'o');
    assert(v5[5] == '!');
    assert(v5[6] == '!');
    assert(v2.size() == 0);

    //Self-assignment test
    Vector<int> self;
    self.push_back(100);
    self.push_back(200);
    self = self;
    assert(self.size() == 2);


    //Copy independence
    Vector<int> cp1;
    cp1.push_back(82);
    Vector<int> cp2(cp1);    
    cp2[0] = 999;
    assert(cp1[0] == 82);
    assert(cp2[0] == 999);

    std::cout << "VECTOR REALIXATION EXAMPLE MAIN FUNC" << std::endl;
    return 0;
}