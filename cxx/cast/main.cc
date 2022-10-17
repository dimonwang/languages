#include <iostream>

class Father
{
public:
	void foo_test() {
		std::cout << "in Father" << std::endl;
	};
    virtual ~Father(){};
};

class Son: public Father
{
    public:
        void foo_test() {
            std::cout << "in Son" << std::endl;
        };
};

int main() {
    Son s;
    s.Father::foo_test();
    s.foo_test();
    std::cout << "====================================" << std::endl;
    Father *f = new Son;

    Son *ps = dynamic_cast<Son*>(f);
    if (ps == NULL) {
        std::cout << "dynamic_cast error" << std::endl;
        goto finished;
    }
    ps->foo_test();
    f->foo_test();

finished:
    delete f;

	return 0;
}
