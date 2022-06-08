#include <stdio.h>
#include <math.h>

void test_cos(void) {
	printf("in test shared lib, cos:%f\n", cos(0.5f));
}
