#include <iostream>

int main(void) {
    int a =1;
    int&& aa =1;
    int&& h2 = std::move(a);
    int&& h3 = std::move(h2);
    h2 =11;
    std::cout << "aa:" << aa << std::endl;
    std::cout << "a:" << a << std::endl;
    std::cout << "h2:" << h2 << std::endl;
    std::cout << "h3:" << h3 << std::endl;
    return 0;
}
