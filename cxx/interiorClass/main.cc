#include <iostream>

class Outer
{
    public:
        class Inner
        {
            public:
                static void istatic() {
                    std::cout << "in istatic" << std::endl;
                }
        };
};

int main(void) 
{
    ::Outer::Inner::istatic();
    return 0;
}
