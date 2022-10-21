#include <iostream>

class A
{
};
class B
{
};
int main() {
    int a = 65;
    float b = static_cast<float> (a);
    char c = static_cast<char> (a);
    // int *pa = static_cast<int*> (a);
    char* pc = &c;
    int *pa = reinterpret_cast<int*> (pc);
    std::cout << "a:" << a << std::endl;
    std::cout << "b:" << b << std::endl;
    std::cout << "c:" << c << std::endl;
    std::cout << "pc:" << pc << std::endl;
    std::cout << "pa:" << pa << std::endl;
    printf("%p,%p\n",pc, pa);
    A *pca = new A;
    B *pcb = reinterpret_cast<B*>(pca);
    delete pca;
	return 0;
}
