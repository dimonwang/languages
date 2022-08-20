#include "class.hh"

class subClass: public Class
{
public:
	int subClass_public_test() {
		public_test();
		std::cout << "in subClass_public_test" << std::endl;
		protected_test();
		return 0;
	}
};
