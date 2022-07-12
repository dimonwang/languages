#include<stdio.h>

int main () {
    char * const cptr;
    const char *ptr = NULL;
    ptr = "dimon";
    ptr ++ ;
    printf("%s\n", ptr);

    cptr = "dimon";
    cptr ++;
    printf("%s\n", cptr);
    return 0;
}
