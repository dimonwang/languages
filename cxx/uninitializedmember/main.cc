#include <iostream>

class Mem
{
    public:
        Mem():b(0) {
            std::cout << "in Mem" << std::endl;
        };
        int get() {
            return b;
        };
    private:
        int b;
};

class Father
{
public:
    Father(){};
	void show() {
		std::cout << "in Father:" << a << ", mem:" << m.get() << std::endl;
	};

private:
    int a;
    Mem m;
};

Father gf;

int main() {
    Father f;
    std::cout << "--stack--" << std::endl;
    f.show();

    std::cout << "--global--" << std::endl;
    gf.show();
	return 0;
}
