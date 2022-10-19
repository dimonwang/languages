#include<stdio.h>

#pragma pack(1)
struct A 
{
    char a;
    char a2;
    char a3;
    char a4;
    char a5;
    int b;
} __attribute__((aligned(8))); 
#pragma pack()

__attribute__((aligned(8))) struct B
{
    char a;
    char a2;
    char a3;
    char a4;
    char a5;
    int b;
};

struct C
{
    char a;
    int b;
    long long int b2;
}  __attribute__((aligned(1))) ;

struct D
{
    char a;
    char a2;
    char a3;
    char a4;
    char a5;
    int b;
};

int main(void) {
	printf("sizeof A:%lu\n", sizeof(struct A));
	printf("sizeof B:%lu\n", sizeof(struct B));
	printf("sizeof C:%lu\n", sizeof(struct C));
	printf("sizeof D:%lu\n", sizeof(struct D));
	return 0;
}
