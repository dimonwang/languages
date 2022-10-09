#include<iostream>

#pragma optimize("", off)

class A
{
    public:
        virtual void op() {
            std::cout << "in A op" << std::endl;
        }
    // private:
        // int i;
};

class B : public A
{
    public:
        void op() {
            std::cout << "in B op" << std::endl;
        }
};

int main(void) {
	B b;
    b.op();
    A &bb = b;
    bb.op();
    std::cout <<"sizeof A:" << sizeof(A) << std::endl;
    std::cout <<"sizeof B:" << sizeof(B) << std::endl;
    return 0;
}
