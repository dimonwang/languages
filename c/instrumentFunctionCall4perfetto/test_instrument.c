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
    printf("main:  %x\n", (void*) main);
    printf("addmul:%x\n", (void*) addmul);
    printf("mul:   %x\n", (void*) mul);
    /* enable_instrument(); */
    int round = 0;
    while(round++ < 500000) {
        int i = addmul(3,5);
        printf("round:%d,result:%d\n", round, i);
        sleep(1);
    }
    /* disable_instrument(); */

    return 0;
}
