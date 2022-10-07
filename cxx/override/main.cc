#include <iostream>

void doIt(char *)
{
	std::cout << "char *" << std::endl;
}

void doIt(void *)
{
	std::cout << "void *" << std::endl;
}

int main() {
	//doIt(0L);
	doIt((void*)0);
	doIt((char*)0);
	return 0;
}
