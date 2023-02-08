#include<stdio.h>
#include <string.h>

int main(void) {
    char in[]="wo shi       dimon  wang";
    char *pa = (char*)in;
    while(&pa) {
        char *token = strsep(&pa, " ");
        if (!token) {
            break;
        }
        if(strlen(token) == 0) {
            continue;
        }
        printf("%s\n", token);
    }

    printf("in:%s\n", in);
	return 0;
}
