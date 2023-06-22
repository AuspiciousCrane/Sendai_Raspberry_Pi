#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

#define LISTEN_PORT 8889
#define MSG_SIZE 128

void *listen_udp(void *args);
void *create_shared_memory(size_t size);

int main(void) {
	void* shmem = create_shared_memory(MSG_SIZE);
	memcpy(shmem, "", sizeof(""));	

	pthread_t thread_id;
	pthread_create(&thread_id, NULL, listen_udp, shmem);
	
	while(1) {
		if (strcmp(shmem, "") == 0) {
			continue;
		} else if (strlen(shmem) <= 1) {
			break;
		} else {
			printf("%s\n", shmem);
			memcpy(shmem, "", sizeof(""));	
		}
	}

	printf("Waiting for recv thread to join...\n");
	pthread_join(thread_id, NULL);

	printf("Exiting Program...\n");
	return 0;
}

void *listen_udp(void *args) {
	int sock;
	int i;
	void* shmem = args;
	struct sockaddr_in addr;

	char buf[100];

	sock = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(LISTEN_PORT);
	addr.sin_addr.s_addr = INADDR_ANY;

	bind(sock, (struct sockaddr*) &addr, sizeof(addr));

	while (1) {
		recv(sock, buf, sizeof(buf), 0);
		memcpy(shmem, buf, sizeof(buf));

		if (strlen(buf) <= 1) {
			break;
		}
	}

	close(sock);
}

void *create_shared_memory(size_t size) {
	int protection = PROT_READ | PROT_WRITE;
	int visibility = MAP_SHARED | MAP_ANONYMOUS;
	return mmap(NULL, size, protection, visibility, -1, 0);
}

