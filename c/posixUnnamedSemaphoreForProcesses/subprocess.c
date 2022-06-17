#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	printf("post start\n");

	sem_post(&semid);

	printf("post done\n");


	return 0;
}
