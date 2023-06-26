#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//AIO header file
#include "caio.h"

int main(void){

	//--------------------------------------------------------------------------------------------------
	//	Declare variables																			
	//--------------------------------------------------------------------------------------------------
	//Return values of functions 
	long	Ret;
	//Device name
	char	DeviceName[256];
	//ID
	short	Id;
	//Error code string
	char	ErrorString[256];
	//The used channel
	short	AiChannel;
	//Range
	short	AiRange;
	//Converted data
	float	AiData;
	//The max number of channels
	short	MaxAiChannels;
	
	//--------------------------------------------------------------------------------------------------
	//	Confirm to input the device name															
	//--------------------------------------------------------------------------------------------------
	printf("\nPlease input device name : ");
	scanf("%s", DeviceName);

	//--------------------------------------------------------------------------------------------------
	//	Initialize the device																		
	//--------------------------------------------------------------------------------------------------
	Ret = AioInit(DeviceName, &Id);
	if(Ret != 0){
		AioGetErrorString(Ret, ErrorString);
		printf("AioInit = %ld : %s\n\n", Ret, ErrorString);
		exit(0);
	}

	//--------------------------------------------------------------------------------------------------
	//	Set analog input range																		
	//--------------------------------------------------------------------------------------------------
	printf("\nPlease select analog input range from the following list\n");
	printf("+/-10V\t\t : 0\t0~10V\t\t : 50\n");
	printf("+/-5V\t\t : 1\t0~5V\t\t : 51\n");
	printf("+/-2.5V\t\t : 2\t0~4.095V\t : 52\n");
	printf("+/-1.25V\t : 3\t0~2.5V\t\t : 53\n");
	printf("+/-1V\t\t : 4\t0~1.25V\t\t : 54\n");
	printf("+/-0.625V\t : 5\t0~1V\t\t : 55\n");
	printf("+/-0.5V\t\t : 6\t0~0.5V\t\t : 56\t\n");
	printf("+/-0.3125V\t : 7\t0~0.25V\t\t : 57\n");
	printf("+/-0.25V\t : 8\t0~0.1V\t\t : 58\n");
	printf("+/-0.125V\t : 9\t0~0.05V\t\t : 59\n");
	printf("+/-0.1V\t\t : 10\t0~0.025V\t : 60\n");
	printf("+/-0.05V\t : 11\t0~0.0125V\t : 61\n");
	printf("+/-0.025V\t : 12\t0~0.01V\t\t : 62\n");
	printf("+/-0.0125V\t : 13\t0~20mA\t\t : 100\n");
	printf("+/-0.01V\t : 14\t4~20mA\t\t : 101\n");
	printf("+/-20mA\t\t : 102\t1~5V\t\t : 150\n");
	scanf("%hd", &AiRange);
	printf("\n");

	//Set the input range
	Ret = AioSetAiRangeAll(Id, AiRange);
	if(Ret != 0){
		AioGetErrorString(Ret, ErrorString);
		printf("AioSetAiRangeAll = %ld : %s\n\n", Ret, ErrorString);
		Ret = AioExit(Id);
		exit(0);
	}

	//--------------------------------------------------------------------------------------------------
	//	Set the analog input channel  																
	//--------------------------------------------------------------------------------------------------
	//Get the max number of channels
	Ret = AioGetAiMaxChannels(Id, &MaxAiChannels);
	if(Ret != 0){
		AioGetErrorString(Ret, ErrorString);
		printf("AioGetAiMaxChannels = %ld : %s\n\n", Ret, ErrorString);
		Ret = AioExit(Id);
		exit(0);
	}

	printf("\nPlease input the channel through which analog input is performed 0~%hd : ", MaxAiChannels - 1);
	scanf("%hd", &AiChannel);
	if((AiChannel < 0) || (AiChannel >= MaxAiChannels)){
		printf("\nThe set channel is out of the available range\n\n");
		Ret = AioExit(Id);
		exit(0);
	}

	//--------------------------------------------------------------------------------------------------
	//	Analog input once from the specified channel												
	//--------------------------------------------------------------------------------------------------
	Ret = AioSingleAiEx(Id, AiChannel, &AiData);
	if(Ret != 0){
		AioGetErrorString(Ret, ErrorString);
		printf("AioSingleAiEx = %ld : %s\n\n", Ret, ErrorString);
		Ret = AioExit(Id);
		exit(0);
	}
	if((AiRange == P20MA) || (AiRange == P4TO20MA) || (AiRange == PM20MA)){
		printf("Channel\tCurrent\n");
		printf("%hd\t%fmA\n", AiChannel, AiData);
	}else{
		printf("Channel\tVoltage\n");
		printf("%hd\t%fV\n", AiChannel, AiData);
	}
	
	//--------------------------------------------------------------------------------------------------
	//	Device Exit																					
	//--------------------------------------------------------------------------------------------------
	Ret = AioExit(Id);
	if(Ret != 0){
		AioGetErrorString(Ret, ErrorString);
		printf("AioExit = %ld : %s\n\n", Ret, ErrorString);
		exit(0);
	}
	exit(0);
}
