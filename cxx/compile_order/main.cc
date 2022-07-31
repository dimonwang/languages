#include <iostream>
#include "test.hh"

using namespace std;

extern int aaa();

int main(void) {
	aaa();
	cout << "in main after test" << endl;
	Test::ashiba();
	return 0;
}
