#include <iostream>

using namespace std;

class A {
    public:
        A() {
            cout << "A contruct" << endl;
        };
        ~A() {
            cout << "A destruction" << endl;
        };
};

int main(void) {
	A a;

    a.~A();
    cout << "flag" << endl;
	return 0;
}
