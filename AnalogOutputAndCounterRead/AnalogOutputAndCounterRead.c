#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "AnalogOutputAndCounterRead.h"

short MaxChannels;
short channel_no_array[10];
short counter_id;

short dac_id;


int main() {
	long return_code;
	unsigned long count_data;

	initialize_counter(count_data);
	initialize_dac();
	
	printf("Gettting Count Value...\n");
	while (1) {
		return_code = AioSingleAoEx(dac_id, DAC_CHANNEL, DAC_VOLTAGE_OUTPUT);
		evaluate_return_code_aio(return_code);

		return_code = CntReadCount(counter_id, channel_no_array, MaxChannels, &count_data);
		evaluate_return_code_cnt(return_code);
		print_count_value(count_data);

		sleep(2);

		return_code = AioSingleAoEx(dac_id, DAC_CHANNEL, 0);
		evaluate_return_code_aio(return_code);

		return_code = CntReadCount(counter_id, channel_no_array, MaxChannels, &count_data);
		evaluate_return_code_cnt(return_code);
		print_count_value(count_data);

		sleep(2);

	}


	return 0;
}


void initialize_counter(unsigned long count_data) {
	long return_code;

	printf("Initializing Counter...\n");
	return_code = CntInit(COUNTER_NAME, &counter_id);	
	evaluate_return_code_cnt(return_code);

	printf("Getting Max Channels...\n");
	return_code = CntGetMaxChannels(counter_id, &MaxChannels);
	evaluate_return_code_cnt(return_code);
	printf("Max Channels: %d\n", MaxChannels);

	for (short i = 0; i < MaxChannels; i++) {
		channel_no_array[i] = i;
	}


	printf("Stopping Previous Count...\n");
	return_code = CntStopCount(counter_id, channel_no_array, MaxChannels);
	evaluate_return_code_cnt(return_code);

	printf("Setting Up Each Channel(s)...\n");
	for (short i = 0; i < MaxChannels; i++) {
		printf("| Configuring the External Signal Source of channel %d\n", i);
		return_code = CntSelectChannelSignal(counter_id, i, EXTERNAL_SIGNAL_SOURCE);
		evaluate_return_code_cnt(return_code);

		printf("| Configuring the Count Direction of channel %d\n", i);
		return_code = CntSetCountDirection(counter_id, i, COUNT_DIRECTION);
		evaluate_return_code_cnt(return_code); 

		printf("| Configuring the Filter Coefficient of channel %d\n", i);
		return_code = CntSetDigitalFilter(counter_id, i, FILTER_COEFFICIENT);
		evaluate_return_code_cnt(return_code);

		printf("| Setting the Operation Mode of channel %d\n", i);
		return_code = CntSetOperationMode(counter_id, i, OPERATION_PHASE, OPERATION_MULTIPLIER, OPERATION_CLEAR_SYNC);
		evaluate_return_code_cnt(return_code);
	}

	printf(".\n.\nResettting Counter...\n");
	return_code = CntZeroClearCount(counter_id, channel_no_array, MaxChannels);
	evaluate_return_code_cnt(return_code);

	printf("Starting Counter...\n");
	return_code = CntStartCount(counter_id, channel_no_array, MaxChannels);
	evaluate_return_code_cnt(return_code);

}

void initialize_dac() {
	long return_code;

	printf("Initializing DAC...\n");
	return_code = AioInit(DAC_NAME, &dac_id);
	evaluate_return_code_aio(return_code);

	printf("Setting the output Range...\n");
	return_code = AioSetAoRangeAll(dac_id, DAC_OUTPUT_RANGE);
	evaluate_return_code_aio(return_code);
}

void evaluate_return_code_cnt(long r_code) {
	char msg_buf[256];

	if (r_code != 0) {
		CntGetErrorString(r_code, msg_buf);
		printf("%s\n", msg_buf);		
		CntExit(counter_id);
		exit(1);
	}
}

void evaluate_return_code_aio(long r_code) {
	char msg_buf[256];

	if (r_code != 0) {
		AioGetErrorString(r_code, msg_buf);
		printf("%s\n", msg_buf);		
		CntExit(counter_id);
		AioExit(dac_id);
		exit(1);
	}
}

void print_count_value(unsigned long count) {
	if (count <= 2) {
		printf("Counter Value: 0\n");
	} else {
		printf("Counter Value: %d\n", ULONG_MAX - count);
	}
}
