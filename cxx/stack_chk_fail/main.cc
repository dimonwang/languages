#include<stdio.h>
#include<string.h>

int main(void) {
	printf("hello world! from dimon\n");
    int *p = (int *)&p;
    // memset(p, 0, 100);
    *(p+100) = 100;
    printf("done:%d\n", *(p+100));
    printf("p:%p, &p:%p\n", p, &p);
	return 0;
}
