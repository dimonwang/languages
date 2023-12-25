#include<stdio.h>
int xtrace(const char* format, ...)
{
    printf(format);
    return 0;
}

int main(void) {
    int age = 100;
    int tag = "nidaye";

    xtrace("%d, %s\n", age, tag);
	return 0;
}
