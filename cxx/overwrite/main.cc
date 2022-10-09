#include <iostream>

class Father
{
public:
	void foo_test() {
		std::cout << "in Father" << std::endl;
	};
};

class Son: public Father
{
public:
	void foo_test() {
		// this->Father::foo_test();
		std::cout << "in Son" << std::endl;
	};
};


int main() {
	Son s;
	s.foo_test();
    ((Father*)&s)->foo_test();
    (&s)->foo_test();
	return 0;
}
