#include <iostream>

class Father
{
    public:
        Father(){
            std::cout << "in Father ctor" << std::endl;
        };
        virtual int test_p(){
            std::cout << "in Father test_p" << std::endl;
            return 0;
        };
};

class Son : protected Father
{
    public:
        Son() {
            std::cout << "in Son ctor" << std::endl;
        };
        int test_p() {
            std::cout << "in Son test_p" << std::endl;
            return 0;
        };
};


int main(void) {
    Father *pf = new Son;
    pf->test_p();
    delete pf;

    return 0;
}
