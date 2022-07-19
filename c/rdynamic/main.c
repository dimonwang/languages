#include<stdio.h>

static void static_func() {
    printf("%s\n", __FUNCTION__);
}

void normal_func() {
    printf("%s\n", __FUNCTION__);
}

int main(void) {
	printf("hello world\n");
    static_func();
    normal_func();
	return 0;
}
