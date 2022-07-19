#include <stdio.h>
#include <stdlib.h>
#include "test2.h"

const char ldpath[] __attribute__((section(".interp"))) = "/lib64/ld-linux-x86-64.so.2";

int test(void) {
    printf("ss in %s:%p\n", __FUNCTION__, test);
    test2();
    return 0;
}

int main(void) {
    test();
    exit(0);
    /* return 0; */
}
