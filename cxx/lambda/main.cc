#include<iostream>

using namespace std;

typedef int (*pFunc)(int,int);

int callBack(pFunc func) {
    return func(1,2);
}

class A {
    public:
        static int ccc(int a, int b) {
            cout << "in ccc" << endl;
            return 0;
        };
};

int main(void) {
    callBack([](int a, int b) ->int { 
            cout << "a:" << a << ",b:" << b << endl; 
            return 0;
            });
    A a;
    callBack(A::ccc);
    return 0;
}
