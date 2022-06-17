#include <stdio.h>


int test(void) {
#ifdef USE_A
	printf("use a\n");
#elif defined(USE_C)
	printf("use b \n");
#endif 
	return 0;
}
