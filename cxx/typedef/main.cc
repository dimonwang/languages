#include <iostream>

class Father
{
public:
	void foo_test() {
		std::cout << "in Father" << std::endl;
	};
};

class Son: Father
{
public:
	void foo_test() {
		this->Father::foo_test();
		std::cout << "in Son" << std::endl;
	};
};

typedef Son sc;

class sc;

int main() {
	sc s;
	s.foo_test();
	return 0;
}
