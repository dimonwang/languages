#include <iostream>

static int init()
{
    printf("init a\n");
    extern int b;
    return b;
}

int a = init();
