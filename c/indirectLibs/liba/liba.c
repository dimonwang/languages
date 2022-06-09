#include <stdio.h>
#include "lib2.h"

int liba_test() {
    printf("in %s\n", __FUNCTION__);
    lib2_test();
    return 0;
}
