#include<iostream>
#include "cppCaller.h"

extern "C" {
int cppCallerWrapper() {
	std::cout << "in cppCallerWrapper" << std::endl;
	return cppCaller(1);
}
}
