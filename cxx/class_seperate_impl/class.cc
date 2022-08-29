#include <iostream>
#include "class.hh"

int Class::aaa = 1000;

void Class::public_test() {
	std::cout << "in seperate impl:" << aaa << std::endl;
}





