#include <stdio.h>
#include <stdlib.h>
#include "ccnt.h"

#define COUNTER_NAME "CNT000"
#define EXTERNAL_SIGNAL_SOURCE CNT_SIGTYPE_ISOLATE
#define COUNT_DIRECTION CNT_DIR_UP
#define FILTER_COEFFICIENT 0xA
#define OPERATION_PHASE CNT_MODE_2PHASE
#define OPERATION_MULTIPLIER CNT_MUL_X4
#define OPERATION_CLEAR_SYNC CNT_CLR_ASYNC

short MaxChannels;
short channel_no_array[10];
short counter_id;

void evaluate_return_code(long r_code);

int main() {
	long return_code;
	unsigned long count_data;
	
	printf("Initializing Counter...\n");
	return_code = CntInit(COUNTER_NAME, &counter_id);	
	evaluate_return_code(return_code);

	printf("Getting Max Channels...\n");
	return_code = CntGetMaxChannels(counter_id, &MaxChannels);
	evaluate_return_code(return_code);
	printf("Max Channels: %d\n", MaxChannels);

	for (short i = 0; i < MaxChannels; i++) {
		channel_no_array[i] = i;
	}


	printf("Stopping Previous Count...\n");
	return_code = CntStopCount(counter_id, channel_no_array, MaxChannels);
	evaluate_return_code(return_code);

	printf("Setting Up Each Channel(s)...\n");
	for (short i = 0; i < MaxChannels; i++) {
		printf("| Configuring the External Signal Source of channel %d\n", i);
		return_code = CntSelectChannelSignal(counter_id, i, EXTERNAL_SIGNAL_SOURCE);
		evaluate_return_code(return_code);

		printf("| Configuring the Count Direction of channel %d\n", i);
		return_code = CntSetCountDirection(counter_id, i, COUNT_DIRECTION);
		evaluate_return_code(return_code); 

		printf("| Configuring the Filter Coefficient of channel %d\n", i);
		return_code = CntSetDigitalFilter(counter_id, i, FILTER_COEFFICIENT);
		evaluate_return_code(return_code);

		printf("| Setting the Operation Mode of channel %d\n", i);
		return_code = CntSetOperationMode(counter_id, i, OPERATION_PHASE, OPERATION_MULTIPLIER, OPERATION_CLEAR_SYNC);
		evaluate_return_code(return_code);
	}

	printf(".\n.\nResettting Counter...\n");
	return_code = CntZeroClearCount(counter_id, channel_no_array, MaxChannels);
	evaluate_return_code(return_code);

	printf("Starting Counter...\n");
	return_code = CntStartCount(counter_id, channel_no_array, MaxChannels);
	evaluate_return_code(return_code);

	printf("Gettting Count Value...\n");
	while (1) {
		return_code = CntReadCount(counter_id, channel_no_array, MaxChannels, &count_data);
		evaluate_return_code(return_code);
		printf("%u\n", count_data);
	}


	return 0;
}

void evaluate_return_code(long r_code) {
	char msg_buf[256];

	if (r_code != 0) {
		CntGetErrorString(r_code, msg_buf);
		printf("%s\n", msg_buf);		
		exit(1);
	}
}
