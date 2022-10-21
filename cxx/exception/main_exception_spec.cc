#include <iostream>

int test() throw(int, char) {

    std::cout << "in test" << std::endl;
    static int i = 0;
    if (i % 2 == 0) {
        throw 1;
    }

    throw '2';
}

int main(void) {
    try {
        test();
    } catch(int i) {
        std::cout << "in main:" << i << std::endl;
    } catch(char j) {
        std::cout << "in main:" << j << std::endl;
    }

    return 0;
}
