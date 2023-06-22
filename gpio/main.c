#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define OUTPUT_PIN 4
#define DURATION 1

int main() {
	printf("Starting Program...\n");

	if (gpioInitialise() < 0) {
		return 1;
	}

	gpioSetMode(OUTPUT_PIN, PI_OUTPUT);

	while(1) {
		gpioWrite(OUTPUT_PIN, 1);
		time_sleep(DURATION);

		gpioWrite(OUTPUT_PIN, 0);
		time_sleep(DURATION);
	}

	printf("Exiting Program...\n");
	return 0;
}
