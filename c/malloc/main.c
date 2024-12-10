#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main(int argc, char** argv) {

    void * b = malloc(10);
    if (b == NULL) {
        printf("malloc fail\n");
        return -1;
    }

    printf("b:%p, usable:%ld\n", b, malloc_usable_size(b));
    free(b);
	return 0;
}
