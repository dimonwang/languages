#include <stdio.h>
#include "instrument.h"
#include <unistd.h>

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
    initialize();
    printf("main:  %x\n", main);
    printf("addmul:%x\n", addmul);
    printf("mul:   %x\n", mul);
    /* enable_instrument(); */
    int round = 5000;
    while(round-- > 0) {
        int i = addmul(3,5);
        printf("result:%d\n", i);
        sleep(1);
    }
    /* disable_instrument(); */

    return 0;
}
