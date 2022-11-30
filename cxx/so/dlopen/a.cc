#include <iostream>

class A
{
    public:
        A():i(0){std::cout << "in A-ctor" << std::endl;};
        ~A(){std::cout << "in A-dtor" << std::endl;};
        int get() {
            return i;
        };
        void set(int v) {
            i = v;
        };
    private:
        int i;
};

A a;

extern "C" int test_a(int v)
{
    printf("before test_a:%d\n", a.get());
    a.set(v);
    printf("after test_a:%d\n", a.get());

    return 100;
}

