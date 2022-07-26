#include <iostream>
#include <cxxabi.h>

class A {
    public:
        static int test(void * in) {
            return 0;
        };
        int test2(void * in) {
            return 0;
        };
};

int main() {
    A a;
    typedef int (*type0)(void *);
    std::cout << abi::__cxa_demangle(typeid(A::test).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << typeid(a.A::test).name() << std::endl;
    return 0;
}
