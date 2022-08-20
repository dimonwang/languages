#include <iostream>

class Class
{
public:
	void public_test() {
		std::cout << "in Class public_test" << std::endl;
	};

protected:
	void protected_test() {
		std::cout << "in Class protected_test" << std::endl;
	};
private:
	void private_test() {
		std::cout << "in Class private_test" << std::endl;
	};
};	
