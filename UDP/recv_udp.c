#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define LISTEN_PORT 8889

int main(void) {
	int sock;
	int i;
	struct sockaddr_in addr;

	float buf[8];

	sock = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(LISTEN_PORT);
	addr.sin_addr.s_addr = INADDR_ANY;

	bind(sock, (struct sockaddr*) &addr, sizeof(addr));

	for (i = 0; i < 5; i++) {
		memset(buf, 0, sizeof(buf));
		recv(sock, buf, sizeof(buf), 0);

		printf("%f\n", buf[i]);
	}

	close(sock);

	return 0;
}
