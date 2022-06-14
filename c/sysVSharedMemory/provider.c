#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

static pid_t exec_app (const char* file_name, const char* app_name)
{
    pid_t pid = 0;

    if ((pid = vfork ()) > 0) {
        fprintf (stderr, "new child, pid: %d.\n", pid);
    }
    else if (pid == 0) {
        execl (file_name, app_name, NULL);
        perror ("execl");
        _exit (1);
    }
    else {
        perror ("vfork");
    }

    return pid;
}

#define KEY_PATH "/var/tmp/sysvSemaphore"

int main(void) {
	key_t key = ftok(KEY_PATH, 1);
	int shm_id = shmget(key, 1, IPC_CREAT | 0777);
	if (shm_id < 0) {
		printf("shmget:%s\n", strerror(errno));
		shmctl(shm_id, IPC_RMID, NULL);
		return 1;
	}

	printf("shmid:%d\n", shm_id);

	void * ptr = shmat(shm_id, NULL, 0);
	if (ptr == NULL) {
		printf("shmat:%s\n", strerror(errno));
		shmctl(shm_id, IPC_RMID, NULL);
		return 2;
	}

	printf("before:%d\n", *(char*)ptr);
	getchar();
	printf("after:%d\n", *(char*)ptr);

	shmdt(ptr);
	shmctl(shm_id, IPC_RMID, NULL);
	return 0;
}
