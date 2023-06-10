#include <iostream>

struct A {
    int a;
    int b;
};

int main() {
    A a;
    a.a=1;
    a.b=2;
    std::cout << "a:" << a.a << ",b:" << a.b << std::endl;
    a = {};
    std::cout << "a:" << a.a << ",b:" << a.b << std::endl;

	return 0;
}
