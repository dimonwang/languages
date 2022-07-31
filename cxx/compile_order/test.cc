#include <iostream>
#include "test_fake.hh"

using namespace std;

int aaa(void) {
	cout << "in aaa" << endl;
	Test::ashiba();
	return 0;
}
