#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

static void sig_handler(int v)
{
	printf("%d signal catched\n", v);
}

int main(void) {
	printf("hello world! from dimon");
	struct sigaction siga;
	siga.sa_handler = sig_handler;
	siga.sa_flags = 0;
	memset(&siga.sa_mask, 0, sizeof(sigset_t));
	sigaction(SIGALRM, &siga, NULL);

	sleep(100);
	printf("sleep done\n");
	return 0;
}
