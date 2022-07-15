#include <stdio.h>
#include <limits.h>

int main(void) {
    long long  a = 0x812345678;//LLONG_MAX;
	printf("p:%p\n", a);
	printf("x:%#lx\n", a);
	return 0;
}
