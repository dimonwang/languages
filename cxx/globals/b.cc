#include <iostream>

static int init()
{
    printf("init b\n");
    return 100;
}

int b = init();

