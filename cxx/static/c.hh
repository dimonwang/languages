#ifndef __C_H__
#define __C_H__
#include <iostream>
#include "mytest.hh"

class Father
{
public:
    Father() {
        test(&bcd);
    };

	void foo_test() {
		std::cout << "in Father" << std::endl;
	};

private:
    static struct BCD bcd;
};
#endif
