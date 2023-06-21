#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>

#define SERVER_ADDR "192.168.11.108"
#define SERVER_PORT 8889

int main(void) {
	int sock, i;
	struct sockaddr_in addr;
	char buf[100];

	sock = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(SERVER_PORT);
	addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

	while (1) {
		fgets(&buf, sizeof(buf), stdin);
		sendto(sock, buf, sizeof(buf), 0, (struct sockaddr*) &addr, sizeof(addr));

		if (strlen(buf) <= 1) {
			break;
		}
	}

	printf("Exiting Program...\n");
	close(sock);

	return 0;
}
