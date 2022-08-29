#include <iostream>

using namespace std;

int test(int a, int b = 1) {
	cout << a << ", " << b << endl;
	return 0;
}

int main(void) {
	test(1);
	test(2);
	return 0;
}
