#include<iostream>

using namespace std;

class A {
    public:
        int ccc(int a, int b) {
            cout << "in ccc" << endl;
            return 0;
        };
};

typedef int (A::*pFunc)(int, int);

int callBack(pFunc func) {
    A a;
    return (a.*func)(1,2);
}

int main(void) {
    // callBack([](int a, int b) ->int { 
            // cout << "a:" << a << ",b:" << b << endl; 
            // return 0;
            // });
    callBack(&A::ccc);
    return 0;
}
