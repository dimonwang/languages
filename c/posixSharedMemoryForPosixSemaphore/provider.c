#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

#define SHM_PATH "/var_tmp_dimon_shm7"


int shm_id = 0; 


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
	printf("posix shared memory provider start.\n");
	shm_id = shm_open(SHM_PATH, O_RDWR | O_CREAT | O_EXCL, /*O_RDWR*/0777); 
	if (shm_id < 0) {
		printf("shm_open:%s\n", strerror(errno));
		return 1;
	}

	printf("shm_id:%d\n", shm_id);

	ftruncate(shm_id, sizeof(sem_t));

	char *ptr = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, 0);
	if (ptr == NULL) {
		printf("mmap failed:%s\n", strerror(errno));
		shm_unlink(SHM_PATH);
		return 2;
	}


	if (sem_init((sem_t *)ptr, 1, 0)) {
		printf("sem_init error:%s\n", strerror(errno));
		shm_unlink(SHM_PATH);
		munmap(ptr, sizeof(sem_t));
		return 3;
	}


	printf("sem:%p\n", ptr);

	exec_app("./consumer", "consumer");

	sem_wait((sem_t *) ptr);

	printf("notified\n");

	shm_unlink(SHM_PATH);
	munmap(ptr, sizeof(sem_t));
	sem_destroy((sem_t *)ptr);

	return 0;
}
