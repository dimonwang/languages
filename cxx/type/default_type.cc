#include <iostream>

using namespace std;

template<typename T>
class A
{
	public:
	T a;
	void test() {
		cout << "T" << endl;
	}
};

template<>
class A<int>
{
	public:
	int a = 1;
	void test(){
		cout << "int" << endl;
	}
};

template<>
class A<char>
{
	public:
	int a = 1;
	void test(){
		cout << "char" << endl;
	}
};

int main() {
	A<typeof('a')> a;	
	a.test();
	return 0;
}
