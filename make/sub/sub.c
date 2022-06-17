#include <stdio.h>
#include "sub.h"
#include "sub2.h"

int test(void) {
	printf("hello world! from sub\n");
	test2();
	return 0;
}
