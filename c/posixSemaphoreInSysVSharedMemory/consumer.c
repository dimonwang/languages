#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <semaphore.h>

#define KEY_PATH "/var/tmp/sysvSemaphore"

int main(void) {
	key_t key = ftok(KEY_PATH, 1);
	int shm_id = shmget(key, sizeof(sem_t), 0666);
	if (shm_id < 0) {
		printf("shmget:%s\n", strerror(errno));
		return 1;
	}

	printf("shmid:%d\n", shm_id);

	void * ptr = shmat(shm_id, NULL, 0);
	if (ptr == NULL) {
		printf("shmat:%s\n", strerror(errno));
		return 2;
	}

	sem_post((sem_t*)ptr);
	printf("posted\n");
	

	shmdt(ptr);
	return 0;
}
