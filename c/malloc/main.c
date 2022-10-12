#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int a[0];

    printf("a:%p\n", a);

    void * b = malloc(0);
    if (b == NULL) {
        printf("malloc fail\n");
        return -1;
    }

    printf("b:%p\n", b);
    free(b);
	return 0;
}
