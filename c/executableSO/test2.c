#include <stdio.h>
#include <stdlib.h>

int test2(void) {
    printf("ss in %s:%p\n", __FUNCTION__, test2);
    return 0;
}

