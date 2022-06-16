#include<stdio.h>

int main(void) {
#define ARRAY_LEN 5
	int (*p)[ARRAY_LEN] = NULL;
	int arr[ARRAY_LEN] = {0,1,2,3,4};

	p = &arr;
	for (int i = 0 ; i < ARRAY_LEN; ++i) {
		printf("%d:%d\n", i, (*p)[i]);
	}
	return 0;
#undef ARRAY_LEN
}
