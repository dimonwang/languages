#include <iostream>

int main(void) {
    printf("naked\n");
    ::printf("from ns\n");
    return 0;
}
