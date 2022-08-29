#include<iostream>

 extern "C" {
void* test() {
    std::cout << "in test" << std::endl;
    return NULL;
}
}
