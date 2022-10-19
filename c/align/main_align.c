#include<stdio.h>

__attribute__((aligned(8))) struct A
{
    char a;
    long long int b;
};

__attribute__((aligned(4))) struct B
{
    char a;
    long long int b;
};

__attribute__((aligned(1))) struct C
{
    char a;
    long long int b;
};

struct D
{
    char a;
    long long int b;
};

int main(void) {
	printf("sizeof A:%lu\n", sizeof(struct A));
	printf("sizeof B:%lu\n", sizeof(struct B));
	printf("sizeof C:%lu\n", sizeof(struct C));
	printf("sizeof D:%lu\n", sizeof(struct D));
	return 0;
}
