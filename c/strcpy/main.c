#include<stdio.h>
#include <string.h>

int main(void) {
    char a[128] = "12345";
    strncpy(a, "8", strlen("8")+1);
    /* strcpy(a, "8"); */
    printf("%s\n", a);
	return 0;
}
