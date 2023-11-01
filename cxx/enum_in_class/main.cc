#include <iostream>

class Father
{
public:
    enum A {
        FIRST=110UL,
        SECOND
    };
	void foo_test() {
		std::cout << "in Father" << std::endl;
	};
    enum A aa;
};

int main() {
    Father a;
    std::cout << a.aa << std::endl;
	return 0;
}
