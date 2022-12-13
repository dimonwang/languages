#include <iostream>
#include "test.h"

int main(void) {
    printf("naked\n");
    ::printf("from ns\n");
    dimon::test();
    return 0;
}
