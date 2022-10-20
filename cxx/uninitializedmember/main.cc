#include <iostream>

class Father
{
public:
    Father(){};
	void show() {
		std::cout << "in Father:" << a << std::endl;
	};

private:
    int a;
};

int main() {
    Father f;
    f.show();

	return 0;
}
