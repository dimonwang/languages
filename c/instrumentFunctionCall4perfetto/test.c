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

void d123456789flg(){}

int main(void) {
    printf("main:  %x\n", main);
    printf("addmul:%x\n", addmul);
    printf("mul:   %x\n", mul);
    /* enable_instrument(); */
    int i = addmul(3,5);
    printf("result:%d\n", i);
    /* disable_instrument(); */

    return 0;
}