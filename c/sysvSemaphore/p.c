#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SEM_PATH "/var/tmp/dimon_test"

// dimon note: the definition of union semun is absent in new version of linux kernel. 
// Define it by yourself.
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int main(){
    int ret = 0;
    key_t key = ftok(SEM_PATH, 1);
    if (key < 0) {
        printf("%d:ftok:%s", __LINE__, strerror(errno));
        return -11;
    }

    int sem_id = semget(key, 1, 0666 | IPC_CREAT);
    if (sem_id < 0) {
        printf("%d:sem_id:%d error:%s\n", __LINE__, sem_id, strerror(errno));
        return -1;
    }

    printf("sem_id:%d\n", sem_id);

    getchar();

    struct sembuf sb[1];
    sb[0].sem_num = 0;
    sb[0].sem_op = -1;
    sb[0].sem_flg = 0;//SEM_UNDO;
    if (semop(sem_id, sb, 1)) {
        printf("%d:semop:%s\n", __LINE__, strerror(errno));
        ret = -3;
        goto err;
    }

err:
    return ret;
}
