#include <stdio.h>
#include <pthread.h>
#include <sys/prctl.h>
#include <unistd.h>

int main(void) {
	prctl(PR_SET_NAME, "alex");
	char proc_name[20];
	prctl(PR_GET_NAME, proc_name);
	printf("proc name:%s\n", proc_name);

	sleep(200);
	return 0;
}
