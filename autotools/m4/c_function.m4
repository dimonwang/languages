divert(-1)
define(helloworld,
`int main(void) {
	printf("hello $1");
	return 0;
}')

divert(0)dnl
helloworld(`dimon')
