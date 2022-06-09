#include <stdio.h>
#include "lib2.h"

void lib1_test() {
    printf("in %s\n", __FUNCTION__);
    lib2_test();
}
