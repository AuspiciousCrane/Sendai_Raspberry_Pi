#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define LISTEN_PORT 8889
#define MSG_SIZE 100

void *listen_udp(void *args);

int main(void) {
	int pipe_handle[2];
	char msgbuf[MSG_SIZE];

	if (pipe(pipe_handle) < 0) {
		exit(0);
	}

	pthread_t thread_id;
	pthread_create(&thread_id, NULL, listen_udp, pipe_handle[1]);
	
	while(1) {
		read(pipe_handle[0], msgbuf, MSG_SIZE);

		if (strlen(msgbuf) <= 1) {
			break;
		}

		printf("%s\n", msgbuf);
	}

	pthread_join(thread_id, NULL);

	printf("Exiting Program...\n");
	return 0;
}

void *listen_udp(void *args) {
	int sock;
	int i;
	int writer = args;
	struct sockaddr_in addr;

	char buf[100];

	sock = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(LISTEN_PORT);
	addr.sin_addr.s_addr = INADDR_ANY;

	bind(sock, (struct sockaddr*) &addr, sizeof(addr));

	while (1) {
		recv(sock, buf, sizeof(buf), 0);

		write(writer, buf, MSG_SIZE);

		if (strlen(buf) <= 1) {
			break;
		}
	}

	close(sock);
}
