#include <iostream>

class Father
{
    public:
        Father(){
            std::cout << "in ctor" << std::endl;
        };
    private:
        int test();
};

int main(void) {
    Father f;
    return 0;
}
