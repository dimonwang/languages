#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>

void timerHandle(union sigval v) {
    printf("%s\n", __FUNCTION__);
}

void timerInit(int sec, int usec)
{
    timer_t timerid;
    struct sigevent evp;
    memset(&evp, 0, sizeof(struct sigevent)); 
    evp.sigev_value.sival_int = 111;
    evp.sigev_notify = SIGEV_THREAD;
    evp.sigev_notify_function = timerHandle;
 
    if (timer_create(CLOCK_REALTIME, &evp, &timerid) == -1)
    {
        perror("fail to timer_create");
        exit(-1);
    }
 
    struct itimerspec it;
    it.it_interval.tv_sec = sec;
    it.it_interval.tv_nsec = usec*1000;
    it.it_value.tv_sec = sec;
    it.it_value.tv_nsec = usec*1000;
    if (timer_settime(timerid, 0, &it, NULL) == -1)
    {
        perror("fail to timer_settime");
        exit(-1);
    }
}

int main(void) {
    timerInit(1,0);
    while(1) {
        sleep(100);
    }

	return 0;
}
