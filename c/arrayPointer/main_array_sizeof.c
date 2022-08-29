#include <stdio.h>

int main(void) {
	int a[20];
	printf("a: %d, &a: %d\n", sizeof(a), sizeof(&a));
	return 0;
}
