#include<stdio.h>
#include<string.h>
int main(void) {
    int a = 10;
    a = a < 100 ? ++a : --a;
    printf("%d\n", a);
	return 0;
}
