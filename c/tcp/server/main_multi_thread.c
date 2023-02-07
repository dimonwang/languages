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

#define SERVER_PORT 8888

static int server_sockfd;
int server_init()
{
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
}

void* client_reader(void* arg) {
#define BUF_LEN 128
    char buf[BUF_LEN];
    while(1) {
        memset(buf, 0, BUF_LEN);
        int client_sockfd = (int)arg;

        int count = read(client_sockfd, buf ,BUF_LEN-1);
        if (count < 0) {
            if (errno != EINTR && errno != EWOULDBLOCK && errno != EAGAIN) {
                printf("error:%d, close:%d\n", errno, client_sockfd);
                close(client_sockfd);
                return NULL;
            }
        } else if (count == 0) {
            close(client_sockfd);
            return NULL;
        }

        write(client_sockfd, buf, count);
        printf("client:%d, msg:%s\n", client_sockfd, buf);
        //todo: add the deal logic here
    }
#undef BUF_LEN
    return NULL;
}

int thread_accepts() {
    int client_len;
    int client_sockfd;
	struct sockaddr_in client_address;
    client_len = sizeof(client_address);
    client_sockfd = accept(server_sockfd,
        (struct sockaddr *)&client_address, &client_len);
    if (client_sockfd < 0) return 0;

    pthread_t t;
    pthread_create(&t, NULL, client_reader, (void*)client_sockfd);
}

void* accept_thread(void* arg) {
    while(1) {
        thread_accepts();
    }

    return NULL;
}

int main()
{
    server_init();
    pthread_t thread_info;
    pthread_create(&thread_info, NULL, accept_thread, NULL);
    while(1) {
        sleep(1);
    }
    return 0;
}
