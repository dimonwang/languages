#include <iostream>

class Test
{
    public:
        Test(){};
        void b2();
        void print();
};

void Test::print()
{
    std::cout << "ok" << std::endl;
}

int main() {

    Test a;
    a.print();
	return 0;
}
