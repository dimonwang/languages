#include<stdio.h>

struct TEST
{
	int i;
	double d;
};

typedef struct TEST *TEST;


void test(const TEST t)
{
	t->i = 100;
	t->d = 1.1;
}

void test2(const struct TEST* t)
{
	t->i = 200;
	t->d = 2.2;
}

void printt(TEST t)
{
	printf("i:%d, d:%f\n", t->i, t->d);
}

int main(void) {
	struct TEST t;
	test(&t);
	printt(&t);

	test2(&t);
	printt(&t);
	return 0;
}
