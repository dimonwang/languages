#include <iostream>

class A
{
    public:
        A(){std::cout << "in A-ctor" << std::endl;};
        ~A(){std::cout << "in A-dtor" << std::endl;};
};

A a;

extern "C" int test_a()
{
    printf("hello test_a\n");
    return 100;
}

