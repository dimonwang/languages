#include<stdio.h>
#include<string.h>

static void test() __attribute__((weakref("test_ref")));

int main(void) {
    printf("%x\n", test);
    if (test)
        test();
	return 0;
}
