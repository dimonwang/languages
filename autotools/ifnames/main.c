#include <stdio.h>


int main(void) {
#ifdef USE_A
	printf("use a\n");
#elif defined(USE_B)
	printf("use b \n");
#endif 
	return 0;
}
