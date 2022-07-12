#include<stdio.h>
#include<stdlib.h>

long long main_base=0;
long long offsets = 0;

int test() 
{
#define MAX_LEN 1024
	char str[MAX_LEN];
	memset(str, 0, MAX_LEN);
	snprintf(str,MAX_LEN-1,  "addr2line -Cfie ./main %p", (void*)test - (void*)offsets);
	printf("cmd:%s\n",str);
	printf("test:%p\n",test);
	system(str);
#undef MAX_LEN
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("only:%d args\n", argc);
		exit(1);
	}

	main_base = atoi(argv[1]);
	printf("main_base:%p\n", main_base);

	offsets = (long long)main - main_base;
	printf("main_offset:%p\n", (void *)offsets);

	printf("%p\n", main);

	test();
	return 0;
}
