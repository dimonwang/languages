#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

#define SERVER_PORT 8888

static int server_sockfd;
#define MAX_CLIENT_NUM 10
static int clients[MAX_CLIENT_NUM];
static int clients_count = 0;

int server_init()
{
    memset(clients, 0, sizeof(clients));

    server_sockfd = 0;

	int server_len,client_len;
	struct sockaddr_in server_address;
 
	unlink("server_socket");
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int one = 1;
    setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, (const void*)&one, sizeof(one));
    fcntl(server_sockfd, F_SETFL, O_NONBLOCK | fcntl(server_sockfd, F_GETFL, 0));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons(SERVER_PORT);
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
	listen(server_sockfd, 1);

    return server_sockfd;
}

void client_reader(int arg) {
#define BUF_LEN 128
    char buf[BUF_LEN];
    memset(buf, 0, BUF_LEN);
    int client_sockfd = arg;

    int count = read(client_sockfd, buf ,BUF_LEN-1);
    if (count < 0) {
        if (errno != EINTR && errno != EWOULDBLOCK && errno != EAGAIN) {
            printf("error:%d, close:%d\n", errno, client_sockfd);
            close(client_sockfd);
            return;
        }
    } else if (count == 0) {
        close(client_sockfd);
        return;
    }

    write(client_sockfd, buf, count);
    printf("client:%d, msg:%s\n", client_sockfd, buf);
    //todo: add the deal logic here
#undef BUF_LEN
}

int thread_accepts() {
    int client_len;
    int client_sockfd;
	struct sockaddr_in client_address;
    client_len = sizeof(client_address);
    client_sockfd = accept(server_sockfd,
        (struct sockaddr *)&client_address, &client_len);
    if (client_sockfd < 0) return -1;

    return client_sockfd;
}

int check_fd_fine(int fd) {
    struct stat _stat;
    int ret = -1;
    errno = 0;
    fcntl(fd, F_GETFL);
    if (errno != 0){
       return -1;
    }

    return 0;
}

int server_main()
{
    fd_set rfds;
    fd_set efds;
    struct timeval tv;
    int retval=0;

    FD_ZERO(&rfds);
    FD_ZERO(&efds);
    FD_SET(server_sockfd, &rfds);
    FD_SET(server_sockfd, &efds);

    int maxfd = server_sockfd;
    for (int i = 0; i < clients_count;) {
        if(check_fd_fine(clients[i]) != 0) {
            close(clients[i]);
            for(int ii = i; ii < clients_count - 1; ++ii) {
                clients[ii] = clients[ii+1];
            }
            clients[clients_count--] = 0;
        } else {
            FD_SET(clients[i], &rfds);
            FD_SET(clients[i], &efds);
            maxfd = maxfd > clients[i] ? maxfd : clients[i];
            ++i;
        }
    }

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    retval = select(maxfd+1, &rfds, NULL, &efds, &tv);
    if (retval == -1){
       perror("select()");
       for (int i = 0; i < MAX_CLIENT_NUM; ++i) {
           printf("%d ", clients[i]);
       }
       printf("\n");
       printf("clients_count:%d\n", clients_count);
       /* return -1; */
    }
    else if (retval) {
        if (FD_ISSET(server_sockfd, &rfds)) {
            int client = thread_accepts();
            if (client > 0) {
                if (clients_count < MAX_CLIENT_NUM) {
                    clients[clients_count++] = client;
                } else {
                    close(client);
                }
            }
        }

        for (int i = 0; i < clients_count; ++i) {
            if(FD_ISSET(clients[i], &rfds)) {
                //todo: read from socket
                client_reader(clients[i]);
            }
        }

        if (FD_ISSET(server_sockfd, &efds)) {
            printf("server socket exception\n");
        }

        for (int i = 0; i < clients_count;) {
            if(FD_ISSET(clients[i], &efds)) {
                printf("close fd:%d\n", clients[i]);
                close(clients[i]);
                for (int ii = i; ii < clients_count-1; ++ii) {
                    clients[ii] = clients[ii+1];
                }
                clients[clients_count--] = 0;
            } else {
                ++i;
            }
        }
    }
}

int main()
{
    server_init();
    while(1) {
        if (server_main() < 0) {
            break;
        }
    }
    return 0;
}
