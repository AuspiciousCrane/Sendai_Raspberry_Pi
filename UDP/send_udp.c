#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_ADDR "192.168.11.108"
#define SERVER_PORT 8889

int main(void) {
	int sock, i;
	struct sockaddr_in addr;
	float buf[8];

	sock = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(SERVER_PORT);
	addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

	for (i = 0; i < 5; i++) {
		buf[i] = i * 1.0;
		sendto(sock, buf, sizeof(buf), 0, (struct sockaddr*) &addr, sizeof(addr));
	}

	close(sock);

	return 0;
}
