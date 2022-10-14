#include <iostream>

class Father
{
public:
    enum {
        FIRST=110UL,
        SECOND
    };
	void foo_test() {
		std::cout << "in Father" << std::endl;
	};
};

int main() {
    int a = Father::FIRST;
    std::cout << a << std::endl;
    std::cout << Father::SECOND << std::endl;
	return 0;
}
