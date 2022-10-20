#include <iostream>

class Father
{
public:
    class Inner {
        private:
            int a;
        public:
            void set(int i) {
                this->a = i;
            };
            int get() {
                return a;
            };
    };
	void foo_test() {
		std::cout << "out:" << aa << ", inner:" << inn.get() << std::endl;
	};
    void set (int i) {
        this->aa = i;
        this->inn.set(i+1);
    };
private:
    int aa;
    Inner inn;
};

int main() {
    Father f;
    f.set(100);
    f.foo_test();
	return 0;
}
