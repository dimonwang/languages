#include<stdio.h>

int main(void) {
	printf("%d\n", sizeof("xxxxxxxx"));
	printf("a:%d\n", sizeof('a'));
	printf("a+1:%d\n", sizeof('a'+1));
	printf("char:%d\n", sizeof(char));
	return 0;
}
