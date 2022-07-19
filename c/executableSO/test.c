#include <stdio.h>
#include <stdlib.h>

const char ldpath[] __attribute__((section(".interp"))) = "/lib64/ld-linux-x86-64.so.2";

int test(void) {
    printf("ss in %s:%p\n", __FUNCTION__, test);
    return 0;
}

int main(void) {
    test();
    exit(0);
    /* return 0; */
}
