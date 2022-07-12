#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("at least 2 argc\n");
		exit(1);
	}
	printf("%d\n", atoi(argv[1]));
	return 0;
}
