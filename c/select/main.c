#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define file_name "/var/tmp/dimon"

int main(void) {
    int fd = open(file_name, O_RDWR | O_NONBLOCK | O_SYNC);
    if (fd < 0) {
        printf("fd:%d, msg:%s\n", fd, strerror(errno));
        exit(1);
    }

    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    int retval = select(fd+1, &rfds, NULL, NULL, &tv);
    if (retval < 0) {
        printf("select()\n");
    } else if (retval) {
       printf("Data is available now.\n");
    } else {
        printf("interrupted or timed out\n");
    }

    /* FD_ISSET(0, &rfds) will be true. */
    if (FD_ISSET(fd, &rfds)) {
           printf("FD_ISSET\n");
    } else {
       printf("No data within five seconds.\n");
    }

    close(fd);
    return 0;
}
