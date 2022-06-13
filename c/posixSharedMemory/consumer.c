#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

#define SHM_PATH "/var_tmp_dimon_shm4"

int shm_id = 0; 

int main(void) {
	printf("posix shared memory consumer start.\n");
	shm_id = shm_open(SHM_PATH, O_RDWR | O_CREAT /*| O_EXCL*/, O_RDWR); 
	if (shm_id < 0) {
		printf("shm_open:%s\n", strerror(errno));
		return 1;
	}

	printf("shm_id:%d\n", shm_id);
	ftruncate(shm_id, sizeof(char));

	char *ptr = mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, 0);
	if (ptr == NULL) {
		printf("mmap failed:%s\n", strerror(errno));
		shm_unlink(SHM_PATH);
		return 2;
	}

//	shm_unlink(SHM_PATH);

	printf("preset content:%d\n", *ptr);

	*ptr = 101;

	printf("result content:%d\n", *ptr);

	munmap(ptr, sizeof(char));

	return 0;
}
