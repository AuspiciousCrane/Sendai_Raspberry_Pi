//==============================================================================================
//	Head file for AIO
//==============================================================================================

//----------------------------------------------------------------------------------------------
//	Input and output range
//----------------------------------------------------------------------------------------------
#define	PM10						0	//+/-10V
#define	PM5							1	//+/-5V
#define	PM25						2	//+/-2.5V
#define	PM125						3	//+/-1.25V
#define	PM1							4	//+/-1V
#define	PM0625						5	//+/-0.625V
#define	PM05						6	//+/-0.5V
#define	PM03125						7	//+/-0.3125V
#define	PM025						8	//+/-0.25V
#define	PM0125						9	//+/-0.125V
#define	PM01						10	//+/-0.1V
#define	PM005						11	//+/-0.05V
#define	PM0025						12	//+/-0.025V
#define	PM00125						13	//+/-0.0125V
#define	PM001						14	//+/-0.01V
#define	P10							50	//0 ~ 10V
#define	P5							51	//0 ~ 5V
#define	P4095						52	//0 ~ 4.095V
#define	P25							53	//0 ~ 2.5V
#define	P125						54	//0 ~ 1.25V
#define	P1							55	//0 ~ 1V
#define	P05							56	//0 ~ 0.5V
#define	P025						57	//0 ~ 0.25V
#define	P01							58	//0 ~ 0.1V
#define	P005						59	//0 ~ 0.05V
#define	P0025						60	//0 ~ 0.025V
#define	P00125						61	//0 ~ 0.0125V
#define	P001						62	//0 ~ 0.01V
#define	P20MA						100	//0 ~ 20mA
#define	P4TO20MA					101	//4 ~ 20mA
#define	PM20MA						102	//+/-20mA
#define	P1TO5						150	//1 ~ 5V

//----------------------------------------------------------------------------------------------
//	Analog Input Event																
//----------------------------------------------------------------------------------------------
#define	AIE_START			0x00000002	//Event that AD converting start conditions are satisfied
#define	AIE_RPTEND			0x00000010	//Event of repeat end
#define	AIE_END				0x00000020	//Event of device operation end
#define	AIE_DATA_NUM		0x00000080	//Event that data of the specified sampling times are stored
#define	AIE_OFERR			0x00010000	//Event of Overflow
#define	AIE_SCERR			0x00020000	//Event of sampling clock error
#define	AIE_ADERR			0x00040000	//Event of AD converting error

//----------------------------------------------------------------------------------------------
//	Analog Output Event																		
//----------------------------------------------------------------------------------------------
#define	AOE_START			0x00000002	//Event that DA converting start conditions are satisfied
#define	AOE_RPTEND			0x00000010	//Event of repeat end
#define	AOE_END				0x00000020	//Event of device operation end
#define	AOE_DATA_NUM		0x00000080	//Event that data of the specified sampling times are output
#define	AOE_SCERR			0x00020000	//Event of sampling clock error
#define	AOE_DAERR			0x00040000	//Event of DA converting error

//----------------------------------------------------------------------------------------------
//	Counter Event																			
//----------------------------------------------------------------------------------------------
#define	CNTE_DATA_NUM		0x00000010	//Event of count comparison match
#define	CNTE_ORERR			0x00010000	//Event of count overrun
#define	CNTE_ERR			0x00020000	//Counter operating error

//----------------------------------------------------------------------------------------------
//	Analog Input Status																		
//----------------------------------------------------------------------------------------------
#define	AIS_BUSY			0x00000001	//Device is working
#define	AIS_START_TRG		0x00000002	//Wait the start trigger
#define	AIS_DATA_NUM		0x00000010	//Store the data of the specified number of samplings
#define	AIS_OFERR			0x00010000	//Overflow
#define	AIS_SCERR			0x00020000	//Sampling clock error
#define	AIS_AIERR			0x00040000	//AD converting error
#define	AIS_DRVERR			0x00080000	//Driver spec error

//----------------------------------------------------------------------------------------------
//	Analog Output Status																		
//----------------------------------------------------------------------------------------------
#define	AOS_BUSY			0x00000001	//Device is working
#define	AOS_START_TRG		0x00000002	//Wait the start trigger
#define	AOS_DATA_NUM		0x00000010	//Output the data of the specified number of samplings
#define	AOS_SCERR			0x00020000	//Sampling clock error
#define	AOS_AOERR			0x00040000	//DA converting error
#define	AOS_DRVERR			0x00080000	//Driver spec error

//----------------------------------------------------------------------------------------------
//	Counter Status																			
//----------------------------------------------------------------------------------------------
#define	CNTS_BUSY			0x00000001	//Counter is working
#define	CNTS_DATA_NUM		0x00000010	//Count comparison match
#define	CNTS_ORERR			0x00010000	//Overrun
#define	CNTS_ERR			0x00020000	//Count operating error

//----------------------------------------------------------------------------------------------
//	Analog Input Message																		
//----------------------------------------------------------------------------------------------
#define AIOM_AIE_START			0x1000	//Event that AD converting start condition are satisfied
#define AIOM_AIE_RPTEND			0x1001	//Event of repeat end
#define AIOM_AIE_END			0x1002	//Event of device operation end
#define AIOM_AIE_DATA_NUM		0x1003	//Event that data of the specified sampling times are stored
#define AIOM_AIE_DATA_TSF		0x1007	//Event that data of the specified number are transferred
#define AIOM_AIE_OFERR			0x1004	//Event of Overflow
#define AIOM_AIE_SCERR			0x1005	//Event of sampling clock error
#define AIOM_AIE_ADERR			0x1006	//Event of AD converting error

//----------------------------------------------------------------------------------------------
//	Analog Output Message																		
//----------------------------------------------------------------------------------------------
#define AIOM_AOE_START			0x1020	//Event that DA converting start conditions are satisfied
#define AIOM_AOE_RPTEND			0x1021	//Event of repeat end
#define AIOM_AOE_END			0x1022	//Event of device operation end
#define AIOM_AOE_DATA_NUM		0x1023	//Event that data of the specified sampling times are output
#define AIOM_AOE_DATA_TSF		0x1027	//Event that data of the specified number are transferred
#define AIOM_AOE_SCERR			0x1025	//Event of sampling clock error
#define AIOM_AOE_DAERR			0x1026	//Event of DA converting error

//----------------------------------------------------------------------------------------------
//	Counter Message																			
//----------------------------------------------------------------------------------------------
#define AIOM_CNTE_DATA_NUM		0x1042	//Event of count comparison match
#define AIOM_CNTE_ORERR			0x1043	//Event of count overrun
#define AIOM_CNTE_ERR			0x1044	//Event of counter operating error

//----------------------------------------------------------------------------------------------
//	Counter Action Mode																			
//----------------------------------------------------------------------------------------------
#define	CNT_LOADPRESET		0x0000001	//Load the preset count value
#define	CNT_LOADCOMP		0x0000002	//Load the count comparison value

//----------------------------------------------------------------------------------------------
//	Event Controller Destination Signal																
//----------------------------------------------------------------------------------------------
#define	AIOECU_DEST_AI_CLK			4	//Analog input sampling clock
#define	AIOECU_DEST_AI_START		0	//Analog input converting start signal
#define	AIOECU_DEST_AI_STOP			2	//Analog input converting stop signal
#define	AIOECU_DEST_AO_CLK			36	//Analog output sampling clock
#define	AIOECU_DEST_AO_START		32	//Analog output converting start signal
#define	AIOECU_DEST_AO_STOP			34	//Analog output converting stop signal
#define	AIOECU_DEST_CNT0_UPCLK		134	//Up clock signal of counter 0
#define	AIOECU_DEST_CNT1_UPCLK		135	//Up clock signal of counter 1
#define	AIOECU_DEST_CNT0_START		128	//Start signal of counter 0
#define	AIOECU_DEST_CNT1_START		129	//Start signal of counter 1
#define	AIOECU_DEST_CNT0_STOP		130	//Stop signal of counter 0
#define	AIOECU_DEST_CNT1_STOP		131	//Stop signal of counter 1
#define	AIOECU_DEST_MASTER1			104	//Synchronization bus master signal 1
#define	AIOECU_DEST_MASTER2			105	//Synchronization bus master signal 2
#define	AIOECU_DEST_MASTER3			106	//Synchronization bus master signal 3

//----------------------------------------------------------------------------------------------
//	Event Controller Source Signal																
//----------------------------------------------------------------------------------------------
#define	AIOECU_SRC_OPEN				-1	//Not connect
#define	AIOECU_SRC_AI_CLK			4	//Analog input internal clock signal
#define	AIOECU_SRC_AI_EXTCLK		146	//Analog input external clock signal
#define	AIOECU_SRC_AI_TRGSTART		144	//Analog input external trigger start signal
#define	AIOECU_SRC_AI_LVSTART		28	//Analog input level trigger start signal
#define	AIOECU_SRC_AI_STOP			17	//Analog input signal that data of the specified sampling times have been converted (No delay)
#define	AIOECU_SRC_AI_STOP_DELAY	18	//Analog input signal that data of the specified sampling times have been converted (delay)
#define	AIOECU_SRC_AI_LVSTOP		29	//Analog input level trigger stop signal
#define	AIOECU_SRC_AI_TRGSTOP		145	//Analog input external trigger stop signal
#define	AIOECU_SRC_AO_CLK			66	//Analog output internal clock signal
#define	AIOECU_SRC_AO_EXTCLK		149	//Analog output external clock signal
#define	AIOECU_SRC_AO_TRGSTART		147	//Analog output external trigger start signal
#define	AIOECU_SRC_AO_STOP_FIFO		352	//Analog output signal that data of the specified sampling times have been output (FIFO)
#define	AIOECU_SRC_AO_STOP_RING		80	//Analog output signal that data of the specified sampling times have been output (RING)
#define	AIOECU_SRC_AO_TRGSTOP		148	//Analog output external trigger stop signal
#define	AIOECU_SRC_CNT0_UPCLK		150	//Up clock signal of counter 0
#define	AIOECU_SRC_CNT1_UPCLK		152	//Up clock signal of counter 1
#define	AIOECU_SRC_CNT0_CMP			288	//Count comparison match of counter 0
#define	AIOECU_SRC_CNT1_CMP			289	//Count comparison match of counter 1
#define	AIOECU_SRC_SLAVE1			136	//Synchronization bus master signal 1
#define	AIOECU_SRC_SLAVE2			137	//Synchronization bus master signal 2
#define	AIOECU_SRC_SLAVE3			138	//Synchronization bus master signal 3
#define	AIOECU_SRC_START			384	//Ai, Ao, Cnt software start signal
#define	AIOECU_SRC_STOP				385	//Ai, Ao, Cnt software stop signal

//----------------------------------------------------------------------------------------------
//	Function prototype
//----------------------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C"{
#endif
//Common function
long AioInit(char *DeviceName, short *Id);
long AioExit(short Id);
long AioResetDevice(short Id);
long AioGetErrorString(long ErrorCode, char *ErrorString);
long AioQueryDeviceName(short Index, char *DeviceName, char *Device);
long AioGetDeviceType(char *Device, short *DeviceType);
long AioSetControlFilter(short Id, short Signal, float Value);
long AioGetControlFilter(short Id, short Signal, float *Value);
long AioResetProcess(short Id);

//Analog input function
long AioSingleAi(short Id, short AiChannel, long *AiData);
long AioSingleAiEx(short Id, short AiChannel, float *AiData);
long AioMultiAi(short Id, short AiChannels, long *AiData);
long AioMultiAiEx(short Id, short AiChannels, float *AiData);
long AioSingleAiSR(short Id, short AiChannel, long *AiData, unsigned short *Timestamp, unsigned char Mode);
long AioSingleAiExSR(short Id, short AiChannel, float *AiData, unsigned short *Timestamp, unsigned char Mode);
long AioMultiAiSR(short Id, short AiChannels, long *AiData, unsigned short *Timestamp, unsigned char Mode);
long AioMultiAiExSR(short Id, short AiChannels, float *AiData, unsigned short *Timestamp, unsigned char Mode);
long AioGetAiResolution(short Id, short *AiResolution);
long AioSetAiInputMethod(short Id, short AiInputMethod);
long AioGetAiInputMethod(short Id, short *AiInputMethod);
long AioGetAiMaxChannels(short Id, short *AiMaxChannels);
long AioSetAiChannels(short Id, short AiChannels);
long AioGetAiChannels(short Id, short *AiChannels);
long AioSetAiChannelSequence(short Id, short AiSequence, short AiChannel);
long AioGetAiChannelSequence(short Id, short AiSequence, short *AiChannel);
long AioSetAiRange(short Id, short AiChannel, short AiRange);
long AioSetAiRangeAll(short Id, short AiRange);
long AioGetAiRange(short Id, short AiChannel, short *AiRange);
long AioGetAiMemorySize(short Id, long *AiMemorySize);
long AioSetAiMemoryType(short Id, short AiMemoryType);
long AioGetAiMemoryType(short Id, short *AiMemoryType);
long AioSetAiRepeatTimes(short Id, long AiRepeatTimes);
long AioGetAiRepeatTimes(short Id, long *AiRepeatTimes);
long AioSetAiClockType(short Id, short AiClockType);
long AioGetAiClockType(short Id, short *AiClockType);
long AioSetAiSamplingClock(short Id, float AiSamplingClock);
long AioGetAiSamplingClock(short Id, float *AiSamplingClock);
long AioSetAiScanClock(short Id, float AiScanClock);
long AioGetAiScanClock(short Id, float *AiScanClock);
long AioSetAiClockEdge(short Id, short AoClockEdge);
long AioGetAiClockEdge(short Id, short *AoClockEdge);
long AioSetAiStartTrigger(short Id, short AiStartTrigger);
long AioGetAiStartTrigger(short Id, short *AiStartTrigger);
long AioSetAiStartLevel(short Id, short AiChannel, long AiStartLevel, short AiDirection);
long AioSetAiStartLevelEx(short Id, short AiChannel, float AiStartLevel, short AiDirection);
long AioGetAiStartLevel(short Id, short AiChannel, long *AiStartLevel, short *AiDirection);
long AioGetAiStartLevelEx(short Id, short AiChannel, float *AiStartLevel, short *AiDirection);
long AioSetAiStartInRange(short Id, short AiChannel, long Level1, long Level2, long StateTimes);
long AioSetAiStartInRangeEx(short Id, short AiChannel, float Level1, float Level2, long StateTimes);
long AioGetAiStartInRange(short Id, short AiChannel, long *Level1, long *Level2, long *StateTimes);
long AioGetAiStartInRangeEx(short Id, short AiChannel, float *Level1, float *Level2, long *StateTimes);
long AioSetAiStartOutRange(short Id, short AiChannel, long Level1, long Level2, long StateTimes);
long AioSetAiStartOutRangeEx(short Id, short AiChannel, float Level1, float Level2, long StateTimes);
long AioGetAiStartOutRange(short Id, short AiChannel, long *Level1, long *Level2, long *StateTimes);
long AioGetAiStartOutRangeEx(short Id, short AiChannel, float *Level1, float *Level2, long *StateTimes);
long AioSetAiStopTrigger(short Id, short AiStopTrigger);
long AioGetAiStopTrigger(short Id, short *AiStopTrigger);
long AioSetAiStopTimes(short Id, long AiStopTimes);
long AioGetAiStopTimes(short Id, long *AiStopTimes);
long AioSetAiStopLevel(short Id, short AiChannel, long AiStopLevel, short AiDirection);
long AioSetAiStopLevelEx(short Id, short AiChannel, float AiStopLevel, short AiDirection);
long AioGetAiStopLevel(short Id, short AiChannel, long *AiStopLevel, short *AiDirection);
long AioGetAiStopLevelEx(short Id, short AiChannel, float *AiStopLevel, short *AiDirection);
long AioSetAiStopInRange(short Id, short AiChannel, long Level1, long Level2, long StateTimes);
long AioSetAiStopInRangeEx(short Id, short AiChannel, float Level1, float Level2, long StateTimes);
long AioGetAiStopInRange(short Id, short AiChannel, long *Level1, long *Level2, long *StateTimes);
long AioGetAiStopInRangeEx(short Id, short AiChannel, float *Level1, float *Level2, long *StateTimes);
long AioSetAiStopOutRange(short Id, short AiChannel, long Level1, long Level2, long StateTimes);
long AioSetAiStopOutRangeEx(short Id, short AiChannel, float Level1, float Level2, long StateTimes);
long AioGetAiStopOutRange(short Id, short AiChannel, long *Level1, long *Level2, long *StateTimes);
long AioGetAiStopOutRangeEx(short Id, short AiChannel, float *Level1, float *Level2, long *StateTimes);
long AioSetAiStopDelayTimes(short Id, long AiStopDelayTimes);
long AioGetAiStopDelayTimes(short Id, long *AiStopDelayTimes);
long AioSetAiCallBackProc(short Id,
	long (*pProc)(short Id, short AiEvent, short wParam, long lParam, void *Param), long AiEvent, void *Param);
long AioSetAiEventSamplingTimes(short Id, long AiSamplingTimes);
long AioGetAiEventSamplingTimes(short Id, long *AiSamplingTimes);
long AioStartAi(short Id);
long AioStartAiSync(short Id, long TimeOut);
long AioStopAi(short Id);
long AioGetAiStatus(short Id, long *AiStatus);
long AioGetAiSamplingCount(short Id, long *AiSamplingCount);
long AioGetAiStopTriggerCount(short Id, long *AiStopTriggerCount);
long AioGetAiRepeatCount(short Id, long *AiRepeatCount);
long AioGetAiSamplingData(short Id, long *AiSamplingTimes, long *AiData);
long AioGetAiSamplingDataEx(short Id, long *AiSamplingTimes, float *AiData);
long AioResetAiStatus(short Id);
long AioResetAiMemory(short Id);

//Analog output function
long AioSingleAo(short Id, short AoChannel, long AoData);
long AioSingleAoEx(short Id, short AoChannel, float AoData);
long AioMultiAo(short Id, short AoChannels, long *AoData);
long AioMultiAoEx(short Id, short AoChannels, float *AoData);
long AioGetAoResolution(short Id, short *AoResolution);
long AioSetAoChannels(short Id, short AoChannels);
long AioGetAoChannels(short Id, short *AoChannels);
long AioGetAoMaxChannels(short Id, short *AoMaxChannels);
long AioSetAoRange(short Id, short AoChannel, short AoRange);
long AioSetAoRangeAll(short Id, short AoRange);
long AioGetAoRange(short Id, short AoChannel, short *AoRange);
long AioSetAoMemoryType(short Id, short AoMemoryType);
long AioGetAoMemoryType(short Id, short *AoMemoryType);
long AioSetAoRepeatTimes(short Id, long AoRepeatTimes);
long AioGetAoRepeatTimes(short Id, long *AoRepeatTimes);
long AioSetAoClockType(short Id, short AoClockType);
long AioGetAoClockType(short Id, short *AoClockType);
long AioSetAoSamplingClock(short Id, float AoSamplingClock);
long AioGetAoSamplingClock(short Id, float *AoSamplingClock);
long AioSetAoClockEdge(short Id, short AoClockEdge);
long AioGetAoClockEdge(short Id, short *AoClockEdge);
long AioSetAoSamplingData(short Id, long AoSamplingTimes, long *AoData);
long AioSetAoSamplingDataEx(short Id, long AoSamplingTimes, float *AoData);
long AioGetAoSamplingTimes(short Id, long *AoSamplingTimes);
long AioSetAoStartTrigger(short Id, short AoStartTrigger);
long AioGetAoStartTrigger(short Id, short *AoStartTrigger);
long AioSetAoStopTrigger(short Id, short AoStopTrigger);
long AioGetAoStopTrigger(short Id, short *AoStopTrigger);
long AioSetAoCallBackProc(short Id,
	long (*pProc)(short Id, short AoEvent, short wParam, long lParam, void	*Param), long AoEvent, void	*Param);
long AioSetAoEventSamplingTimes(short Id, long AoSamplingTimes);
long AioGetAoEventSamplingTimes(short Id, long *AoSamplingTimes);
long AioStartAo(short Id);
long AioStopAo(short Id);
long AioEnableAo(short Id, short AoChannel);
long AioDisableAo(short Id, short AoChannel);
long AioGetAoStatus(short Id, long *AoStatus);
long AioGetAoSamplingCount(short Id, long *AoSamplingCount);
long AioGetAoRepeatCount(short Id, long *AoRepeatCount);
long AioResetAoStatus(short Id);
long AioResetAoMemory(short Id);

//Digital input and output function
long AioSetDiFilter(short Id, short Bit, float Value);
long AioGetDiFilter(short Id, short Bit, float *Value);
long AioInputDiBit(short Id, short DiBit, short * DiData);
long AioOutputDoBit(short Id, short DoBit, short DoData);
long AioInputDiByte(short Id, short DiPort, short * DiData);
long AioOutputDoByte(short Id, short DoPort, short DoData);
long AioSetDioDirection(short Id, long Dir);
long AioGetDioDirection(short Id, long *Dir);

//Counter function
long AioGetCntMaxChannels(short Id, short *CntMaxChannels);
long AioSetCntComparisonMode(short Id, short CntChannel, short CntMode);
long AioGetCntComparisonMode(short Id, short CntChannel, short *CntMode);
long AioSetCntPresetReg(short Id, short CntChannel, long PresetNumber, long *PresetData, short Flag);
long AioSetCntComparisonReg(short Id, short CntChannel, long ComparisonNumber, long *ComparisonData, short Flag);
long AioSetCntInputSignal(short Id, short CntChannel, short CntInputSignal);
long AioGetCntInputSignal(short Id, short CntChannel, short *CntInputSignal);
long AioSetCntCallBackProc(short Id, short CntChannel,
	long (*pProc)(short Id, short CntEvent, short wParam, long lParam, void	*Param), long CntEvent, void *Param);
long AioSetCntFilter(short Id, short CntChannel, short Signal, float Value);
long AioGetCntFilter(short Id, short CntChannel, short Signal, float *Value);
long AioStartCnt(short Id, short CntChannel);
long AioStopCnt(short Id, short CntChannel);
long AioPresetCnt(short Id, short CntChannel, long PresetData);
long AioGetCntStatus(short Id, short CntChannel, long *CntStatus);
long AioGetCntCount(short Id, short CntChannel, long *Count);
long AioResetCntStatus(short Id, short CntChannel, long CntStatus);

//Event Controller
long AioSetEcuSignal(short Id, short Destination, short Source);
long AioGetEcuSignal(short Id, short Destination, short *Source);

//Demo device function
long AioDemoReset(short Id);
long AioGetDemoAo(short Id, short AoChannelNum, short *AoChannel, float *AoData);
long AioSetDemoAi(short Id, short AiChannelNum, short *AiChannel, float *AiData);
long AioSetDemoAiType(short Id, short AiChannelNum, short *AiChannel, short *AiType, short *AiPeriod);
long AioGetDemoDoBit(short Id, short DoBitNum, short *DoBit, short *DoData);
long AioGetDemoDoByte(short Id, short DoPortNum, short *DoPort, short *DoData);
long AioSetDemoDiBit(short Id, short DiBitNum, short *DiBit, short *DiData);
long AioSetDemoDiByte(short Id, short DiPortNum, short *DiPort, short *DiData);
long AioSetDemoAiStartExtTrigger(short Id, short Data);
long AioGetDemoAiStartExtTrigger(short Id, short *Data);
long AioSetDemoAiStopExtTrigger(short Id, short Data);
long AioGetDemoAiStopExtTrigger(short Id, short *Data);
long AioSetDemoAiClockExtTrigger(short Id, short Data);
long AioGetDemoAiClockExtTrigger(short Id, short *Data);
long AioSetDemoAoStartExtTrigger(short Id, short Data);
long AioGetDemoAoStartExtTrigger(short Id, short *Data);
long AioSetDemoAoStopExtTrigger(short Id, short Data);
long AioGetDemoAoStopExtTrigger(short Id, short *Data);
long AioSetDemoAoClockExtTrigger(short Id, short Data);
long AioGetDemoAoClockExtTrigger(short Id, short *Data);

#ifdef __cplusplus
};
#endif
