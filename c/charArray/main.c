#include<stdio.h>

int main(void) {
    const char aaa[] = ("hello");
    const char *p = aaa+1;
    printf("aaa:%p,\n  p:%p\n", aaa, p);
	return 0;
}
