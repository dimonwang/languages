#include <iostream>

class Father
{
public:
	void foo_test() {
		std::cout << "in Father" << std::endl;
	};
    Father() {
        std::cout << "Father ctor" << std::endl;
    };
    ~Father() {
        std::cout << "Father dtor" << std::endl;
    };
};



int main() {
    Father f;
    Father *pf = new (&f) Father;

    std::cout << "done" << std::endl;
    delete pf;
	return 0;
}
