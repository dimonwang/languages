#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>

char nonblocking_input() {
    char input_char;
    system("stty raw -echo -F /dev/tty");
    usleep(100);
    input_char = getchar();
    printf("%d\n", input_char);
    system("stty -raw echo -F /dev/tty");
}

int main() {
    /* int i; */
    /* read(stdin, &i, 1); */
    /* printf("%d\n", i); */
    /* int i2 = getchar(); */
    /* printf("%d\n", i2); */
    nonblocking_input();
    return 0;
}
