#include <iostream>
#include <exception>
#include <csignal>

int test() 
{
    printf("in test\n");
    return 1/0;
}

void handler(int a)
{
    printf("in handler\n");

    // without this, the program will deathly loop.
    exit (1);
}

int main() {
    signal(SIGFPE, handler);
    try {
        test();
    } catch(...) {
        // printf("get Exception:%s\n", e.what());
        printf("get Exception\n");
    }

	return 0;
}
