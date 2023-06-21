#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

int main() {
	if (gpioInitialise() < 0) {
		return 1;
	}

	gpioSetMode(16, PI_OUTPUT);

	gpioWrite(16, 1);
	time_sleep(0.5);

	gpioWrite(16, 0);
	time_sleep(0.5);

	return 0;
}
