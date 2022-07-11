#include<stdio.h>

int test2() {
	printf("in test2\n");
	return 0;
}

int test() {
	printf("in test\n");
	test2();
	return 0;
}

