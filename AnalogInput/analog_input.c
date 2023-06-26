#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "caio.h"

#define DEVICE_NAME "AIO000"
#define AI_RANGE 50
#define AI_CHANNEL 0

int main() {
	short Id;
	short AiChannel = AI_CHANNEL;
	short AiRange = AI_RANGE;
	float AiData;

	if (AioInit(DEVICE_NAME, &Id) != 0) {
		printf("Failed to initialize Aio\n");
		exit(1);
	}	

	if (AioSetAiRangeAll(Id, AiRange) != 0) {
		printf("Failed to Set Ai range\n");
		AioExit(Id);
		exit(1);
	}

	if (AioSingleAiEx(Id, AiChannel, &AiData) != 0) {
		printf("Failed to Get Ai Data\n");
		AioExit(Id);
		exit(1);
	}	

	printf("Voltage Data ");
	printf("%hd\t%fV\n", AiChannel, AiData);	

	AioExit(Id);
	exit(0);
}
