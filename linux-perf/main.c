#include<stdio.h>

static int test() {
	printf("in test\n");
	return 0;
}

int main(void) {
	int i = 1000000000;
	while(i-- > 0) {
		printf("hello world! from dimon");
		test();
	}

	return 0;
}
