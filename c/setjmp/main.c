#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf env;

void call_setjmp()
{
    int i;
    i = setjmp(env);

    switch (i) {
        case 0:
            printf("Finished initialization of env\n");
            break;
        case 10:
            printf("Hit 10\n");
            break;
        case 20:
            printf("Hit 20\n");
            break;
        default:
            printf("Hit nothing useful\n");
    }
}

void call_longjmp(int val)
{
    longjmp(env, val);
}

int main()
{
    printf("sizeof jmp_buf:%ld\n", sizeof(jmp_buf));
    call_setjmp();
    call_longjmp(10);
    call_longjmp(20);
    call_longjmp(30);

    return 0;
}

