#include <stdio.h>

extern void * test();

int main(void) {
    void * a = test();
    int* ab = test();
    return 0;
}
