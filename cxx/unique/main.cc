#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> a = std::make_unique<int>(100);
    std::cout << *a << std::endl;

    std::cout << *a.get() << std::endl;
    std::cout << *a << std::endl;

    return 0;
}
