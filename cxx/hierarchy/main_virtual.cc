#include <iostream>

class Father
{
    public:
        Father(){
            std::cout << "in father ctor" << std::endl;
            cnt = 1;
        };
        ~Father(){
            std::cout << "in father dtor" << std::endl;
        };
        int cnt;
};

class Son : virtual public Father
{
    public:
        Son(){
            std::cout << "in son ctor" << std::endl;
        };
        ~Son(){
            std::cout << "in son dtor" << std::endl;
        };
    private:
};

class GrandSon : public Son, virtual public Father
{
    public:
        GrandSon(){
            std::cout << "in grandson ctor" << std::endl;
        };
        ~GrandSon() {
            std::cout << "in grandson dtor" << std::endl;
        };
};

int main(void) {
    GrandSon gs;
    std::cout << &gs.Son::Father::cnt << std::endl;
    std::cout << &gs.Father::cnt << std::endl;
    return 0;
}
