#include <iostream>

class Father
{
    public:
        Father() {
            std::cout << "in Father ctor" << std::endl;
        };
        virtual ~Father() {
            std::cout << "in Father dtor" << std::endl;
        };
};


class Son: public Father
{
    public:
        Son() {
            std::cout << "in Son ctor" << std::endl;
        };
        ~Son() {
            std::cout << "in Son dtor" << std::endl;
        };
};

int main(void) {
    Father* pf = new Son;
    delete pf;

    return 0;
}
