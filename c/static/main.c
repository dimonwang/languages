#include <stdio.h>

int *pSt = NULL;

void test() {
	static int i = 100;

	pSt = &i;
	
	printf("b i:%d\n", i);
	i++;
	printf("a i:%d\n", i);
}

int main() {
	test();
	printf("*pSt:%d\n", *pSt);
	*pSt += 1;
	printf("*pSt:%d\n", *pSt);
	return 0;
}
