#include "ccnt.h"
#include "caio.h"

#define COUNTER_NAME "CNT000"
#define EXTERNAL_SIGNAL_SOURCE CNT_SIGTYPE_ISOLATE
#define COUNT_DIRECTION CNT_DIR_UP
#define FILTER_COEFFICIENT 0xA
#define OPERATION_PHASE CNT_MODE_2PHASE
#define OPERATION_MULTIPLIER CNT_MUL_X4
#define OPERATION_CLEAR_SYNC CNT_CLR_ASYNC

#define DAC_NAME "AIO001"
#define DAC_CHANNEL 0
#define DAC_VOLTAGE_OUTPUT 5
#define DAC_OUTPUT_RANGE 50 // 50 is 0-10V


void aocr_initialize_counter(unsigned long count_data);
void aocr_initialize_dac();

void aocr_evaluate_return_code_cnt(long r_code);
void aocr_evaluate_return_code_aio(long r_code);

void aocr_print_count_value(unsigned long count);


