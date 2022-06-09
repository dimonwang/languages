#include <stdio.h>

int liba_test() {
    printf("in %s\n", __FUNCTION__);
    return 0;
}

int liba_test_unused() {
    printf("in %s\n", __FUNCTION__);
    return 0;
}
