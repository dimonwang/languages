#include <stdio.h>
#include "instrument.h"
#include <unistd.h>

int mul(int i, int j) {
    printf("%s:%p\n", __FUNCTION__, (void*) mul);
    return i*j;
}

int addmul(int i, int j) {
    printf("%s\n", __FUNCTION__);
    int k1,k2;
    k1 = i+j;
    //enable_instrument();
    k2=mul(i,j);
    //disable_instrument();
    return k1+k2;
}


int main(void) {
    printf("%s\n", __FUNCTION__);
    initialize();
    printf("main:  %018p\n", (void*) main);
    printf("flag:  %018p\n", (void*) d123456789flg);
    printf("addmul:%p\n", (void*) addmul);
    printf("mul:   %p\n", (void*) mul);
    enable_instrument();
    int round = 0;
    while(round++ < 5) {
        int i = addmul(3,5);
        printf("round:%d,result:%d\n", round, i);
        sleep(1);
    }
    disable_instrument();
    deinitialize();

    return 0;
}
