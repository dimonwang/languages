#include<stdio.h>

extern int *a;

int main(void) {
	printf("%d\n", *a);
	return 0;
}
