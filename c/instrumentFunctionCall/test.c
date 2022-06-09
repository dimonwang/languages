#include <stdio.h>
#include "instrument.h"

int mul(int i, int j) {
    return i*j;
}

int addmul(int i, int j) {
    int k1,k2;
    k1 = i+j;
    enable_instrument();
    k2=mul(i,j);
    disable_instrument();
    return k1+k2;
}

int main(void) {
    printf("main:  %p\n", main);
    printf("addmul:%p\n", addmul);
    printf("mul:   %p\n", mul);
    /* enable_instrument(); */
    int i = addmul(3,5);
    printf("result:%d\n", i);
    /* disable_instrument(); */

    return 0;
}
