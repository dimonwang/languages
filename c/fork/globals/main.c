#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int globals = 11;
int main(void) {
	printf("init global:%d\n", globals);
	pid_t pid = fork();
	if (pid == 0) {
		printf("child process is running\n");
		globals = 22;
		printf("posted\n");
		return 1;
	} else {
		printf("child %d is created by parent\n", pid);
	}

	sleep(5);
	
	printf("global:%d\n", globals);


	return 0;
}
