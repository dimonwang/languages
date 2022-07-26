#include <stdio.h>

int shared_test1(){
    printf("%s:%p\n", __FUNCTION__, shared_test1);
    return 0;
}

int shared_ashiba() {
    printf("%s:%p\n", __FUNCTION__, shared_ashiba);
    return 0;
}
