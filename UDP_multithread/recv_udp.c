#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define LISTEN_PORT 8889

void *listen_udp(void *args);

int main(void) {
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, listen_udp, NULL);
	
	for (int i = 0; i < 5; i++) {
		sleep(1);
		printf("Main Thread Working...\n");
	}

	pthread_join(thread_id, NULL);

	printf("Exiting Program...\n");
	return 0;
}

void *listen_udp(void *args) {
	int sock;
	int i;
	struct sockaddr_in addr;

	char buf[100];

	sock = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(LISTEN_PORT);
	addr.sin_addr.s_addr = INADDR_ANY;

	bind(sock, (struct sockaddr*) &addr, sizeof(addr));

	while (1) {
		recv(sock, buf, sizeof(buf), 0);

		if (strlen(buf) <= 1) {
			break;
		}

		printf("%s\n", buf);
	}

	close(sock);
}
