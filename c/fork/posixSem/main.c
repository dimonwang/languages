#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


sem_t semid;

int main(void) {
	if (sem_init(&semid, 1, 0)) {
		printf("sem_init:%s\n", strerror(errno));
		return 2;
	}

	pid_t pid = fork();
	if (pid == 0) {
		printf("child process is running\n");
		sem_post(&semid);
		printf("posted\n");
		return 1;
	} else {
		printf("child %d is created by parent\n", pid);
	}

	sem_wait(&semid);
	printf("waited\n");


	sem_destroy(&semid);

	return 0;
}
