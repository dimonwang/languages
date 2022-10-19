#include<stdio.h>

#pragma pack(8)
struct A
{
    char a;
    long long int b;
};

#pragma pack(4)
struct B
{
    char a;
    long long int b;
};

#pragma pack(1)
struct C
{
    char a;
    long long int b;
};

#pragma pack()
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
