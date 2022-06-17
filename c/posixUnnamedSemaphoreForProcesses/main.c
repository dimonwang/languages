#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

//#define SEM_PATH "/var/tmp/dimon"

//key_t key_type = 0;

sem_t semid;

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

int main(void) {
//	key_t key_type = ftok(SEM_PATH, 1);
//	if (key_type < 0) {
//		printf("ftok:%s\n", strerror(errno));
//		return 1;
//	}

	if (sem_init(&semid, 1, 0)) {
		printf("sem_init:%s\n", strerror(errno));
		return 2;
	}

	exec_app("./subprocess", "subprocess");

	while(1) {
		sem_wait(&semid);
		printf("posted\n");
	}

	sem_destroy(&semid);

	return 0;
}
