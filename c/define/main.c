#include <stdio.h>

#include "test.h"
#define my_test test_1
#undef my_test

int main(void) {
    my_test();
    return 0;
}
