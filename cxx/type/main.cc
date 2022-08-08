#include <iostream>
#include <typeinfo>

int test(int a) {return 0;}
class A{};
int main(void) {
	std::cout << typeid(test).name() << std::endl;
	std::cout << typeid(A).name() << std::endl;
	A a;

	std::cout << typeid(a).name() << std::endl;
	return 0;
}
