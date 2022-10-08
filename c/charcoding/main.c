#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include<locale.h>

int main(void) {
	printf("%s\n", setlocale(LC_ALL, NULL));
	char * presult = setlocale(LC_ALL, "en_US.UTF-8");
	if (presult == NULL) {
		printf("setlocale failed:%s\n", strerror(errno));
	}
	printf("%s\n", setlocale(LC_ALL, NULL));

	unsigned char *mb = u8"操";
	wchar_t dst;
	printf("sizeof wchar_t: %ld, mb:%ld\n", sizeof(dst), strlen(mb));
	printf("0:%x, 1:%x, 2:%x\n", *mb, *(mb+1), *(mb+2));
	int i = -1;
	if ((i = mbtowc(&dst, mb, strlen(mb))) < 0) {
		printf("fail:%s, %d\n", strerror(errno), i);
		return -1;
	}
	

	unsigned char *pw = (unsigned char*)&dst;
	printf("0:0x%x, 1:0x%x, 2:0x%x, 3:0x%x\n", *pw, *(pw+1), *(pw+2), *(pw+3));

	return 0;
}
