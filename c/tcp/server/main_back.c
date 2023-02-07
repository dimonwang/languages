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
#define MAX_CLIENTS_NUM 10
static int clients[MAX_CLIENTS_NUM];
static int clients_count = 0;

static int server_sockfd;
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
}

void print_clients() {
    for (int i = 0; i < MAX_CLIENTS_NUM; ++i) {
        printf("%d ", clients[i]);
    }
    printf("\n");
    printf("count:%d\n", clients_count);
}

int thread_accepts() {
    int client_len;
    int client_sockfd;
	struct sockaddr_in client_address;
    client_len = sizeof(client_address);
    if (clients_count >= MAX_CLIENTS_NUM) {
        printf("current %d clients, max is :%d", clients_count, MAX_CLIENTS_NUM);
        return 0;
    }

    client_sockfd = accept(server_sockfd,
        (struct sockaddr *)&client_address, &client_len);
    if (client_sockfd < 0) return 0;

    fcntl(client_sockfd, F_SETFL, O_NONBLOCK | fcntl(client_sockfd, F_GETFL, 0));
    clients[clients_count] = client_sockfd;
    clients_count++;
    print_clients();
}

void* accept_thread(void* arg) {
    while(1) {
        thread_accepts();
    }

    return NULL;
}

int poll_clients() {
    for (int i = 0; i < clients_count; ++i) {
#define BUF_LEN 128
        char buf[BUF_LEN];
        memset(buf, 0, BUF_LEN);
        int client_sockfd = clients[i];
 
		int count = read(client_sockfd, buf ,BUF_LEN-1);
        if (count < 0) {
            if (errno != EINTR && errno != EWOULDBLOCK && errno != EAGAIN) {
                printf("maybe closed by peer, client:%d\n", client_sockfd);
                close(client_sockfd);
                //remmove from the list
                for (int ii = i; ii < clients_count-1; ++ii) {
                    clients[ii] = clients[ii+1];
                }
                clients[clients_count-1] = 0;
                clients_count--;
                print_clients();
            }
            break;
        } else if (count == 0) {
            printf("read client:%d, get nothgin\n", client_sockfd);
            continue;
        }

		write(client_sockfd, buf, count);
        printf("client:%d, msg:%s\n", client_sockfd, buf);
	}
#undef BUF_LEN
}

int main()
{
    server_init();
    pthread_t thread_info;
    pthread_create(&thread_info, NULL, accept_thread, NULL);
    while(1) {
        poll_clients();
    }
    return 0;
}
