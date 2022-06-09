#include <stdio.h>

#include "test.h"
#undef test

int main(void) {
    test();
    return 0;
}
