//================================================================
//================================================================
// CONTEC Linux CNT Header File
//                 								CONTEC Co.,Ltd.
//											   Ver1.00
//================================================================
//================================================================
#ifndef __CCNT_H_DEFINED__
#define __CCNT_H_DEFINED__

//================================================================
// Macro definition
//================================================================
// Call Back Function Method
typedef void (*PCNT_MATCH_CALLBACK)(short, short, long, long, void *);
typedef void (*PCNT_TIMEUP_CALLBACK)(short, short, long, long, void *);
typedef void (*PCNT_COUNTER_ERR_CALLBACK)(short, short, long, long, void *);
typedef void (*PCNT_CARRY_BORROW_CALLBACK)(short, short, long, long, void *);
typedef void (*PCNT_SAMPLING_STOP_CALLBACK)(short, short, long, long, void *);
typedef void (*PCNT_SAMPLING_COUNT_CALLBACK)(short, short, long, long, void *);
// Message
#define	CNTM_COUNTUP_CH0						0x1100
#define	CNTM_COUNTUP_CH1						0x1101
#define	CNTM_COUNTUP_CH2						0x1102
#define	CNTM_COUNTUP_CH3						0x1103
#define	CNTM_COUNTUP_CH4						0x1104
#define	CNTM_COUNTUP_CH5						0x1105
#define	CNTM_COUNTUP_CH6						0x1106
#define	CNTM_COUNTUP_CH7						0x1107
#define	CNTM_TIME_UP							0x1140

#define	CNTM_COUNTER_ERROR						0x1141
#define	CNTM_CARRY_BORROW						0x1142

#define	CNTM_SAMPLING_STOP						0x1150
#define	CNTM_SAMPLING_COUNT						0x1151
//================================================================
// Error Code
//================================================================
// Initialize Error
// Common
#define	CNT_ERR_SUCCESS							0				// Normal Complete
#define	CNT_ERR_INI_RESOURCE					1				// Failed in the acquisition of resource.
#define	CNT_ERR_INI_INTERRUPT					2				// Failed in the registration of interrupt routine.
#define	CNT_ERR_INI_MEMORY						3				// Failed in the memory allocation.
#define	CNT_ERR_INI_REGISTRY					4				// Failed in access to the setting file.
#define	CNT_ERR_INI_BOARD_ID					5				// Board ID is duplicated.
// CNT
// Lib Error
// Common
#define	CNT_ERR_DLL_DEVICE_NAME					10000			// Device name which isn't registered in setting file is specified.
#define	CNT_ERR_DLL_INVALID_ID					10001			// Invalid ID is specified.
#define	CNT_ERR_DLL_CALL_DRIVER					10002			// Driver cannot be called (failed in ioctl).
#define	CNT_ERR_DLL_CREATE_FILE					10003			// Failed in creating file (open failed).
#define	CNT_ERR_DLL_CLOSE_FILE					10004			// Failed in closing file (close failed).
#define	CNT_ERR_DLL_CREATE_THREAD				10005			// Failed in creating thread.
#define	CNT_ERR_INFO_INVALID_DEVICE				10050			// Specified device name isn't found.
#define	CNT_ERR_INFO_NOT_FIND_DEVICE			10051			// The usable device isn't found.
#define	CNT_ERR_INFO_INVALID_INFOTYPE			10052			// The specified device information type is outside the range.
// CNT
#define	CNT_ERR_DLL_MODE						10100			// Invalid mode setting.
#define	CNT_ERR_DLL_BUFF_ADDRESS				10101			// Invalid data buffer address.
#define	CNT_ERR_DLL_CALLBACK					10400			// Invalid address of callback function.
#define	CNT_ERR_DLL_GENINP						10401			// Invalid general-purpose input type.
// USB error 
#ifndef STATUS_SYS_USB_CRC
#define STATUS_SYS_USB_CRC						20020			// CRC mismatch
#define STATUS_SYS_USB_BTSTUFF					20021			// BITSTUFF error
#define STATUS_SYS_USB_NO_ENTRY					20022			// URB stop (stop request to endpoint)
#define STATUS_SYS_USB_CONNECT_RESET			20023			// URB is an unlink
#define STATUS_SYS_USB_INPROGRESS				20024			// During URB processing
#define STATUS_SYS_USB_COMMUNICATION			20025			// Receive URB, receive data faster than write data to memory
#define STATUS_SYS_USB_STREAM_RESOURCE			20026			// At the time of transmission URB, the data rate is faster than the transmission data rate, data can not be taken out from the memory
#define STATUS_SYS_USB_DATA_OVERRUN				20027			// Receive more data than the maximum packet size
#define STATUS_SYS_USB_REMOTE_IO				20028			// The total amount of URB request data was not received
#define STATUS_SYS_USB_NO_DEVICE				20029			// No USB device in system
#define STATUS_SYS_USB_XDEV						20030			// Partial completion of isochronous transfer
#define STATUS_SYS_USB_ENDPOINT_HALTED			20031			// End point stall
#define STATUS_SYS_USB_INVALID					20032			// Argument error etc. Fatal error
#define STATUS_SYS_USB_SHUTDOWN					20033			// Device disconnects from system
#define STATUS_SYS_USB_TIMEOUT					20034			// Transfer timeout
#endif
// Module Error
// Common
#define	CNT_ERR_SYS_MEMORY						20000			// Failed in memory allocation.
#define	CNT_ERR_SYS_NOT_SUPPORTED				20001			// This function cannot be used in this device.
#define	CNT_ERR_SYS_BOARD_EXECUTING				20002			// It cannot perform because the device is executing.
#define	CNT_ERR_SYS_USING_OTHER_PROCESS			20003			// It cannot perform because the other process is using the device.
// CNT
#define	CNT_ERR_SYS_MODE						20100			// Invalid mode setting.
#define	CNT_ERR_CH_NO							20201			// Channel number is outside the range.
#define	CNT_ERR_CH_NUM							20202			// Number of channels is outside the range.
#define	CNT_ERR_SYS_CH_VALUE					20203			// Counter value is outside the range.
#define	CNT_ERR_SYS_REGNO						20204			// Compare register number is outside the range.
#define	CNT_ERR_SYS_TIMER_VALUE					20300			// Timer value is outside the range.
//================================================================
// Mode
//================================================================
// Z Phase Mode
#define	CNT_ZPHASE_NOT_USE						1
#define	CNT_ZPHASE_NEXT_ONE						2
#define	CNT_ZPHASE_EVERY_TIME					3
// Z Phase Logic
#define	CNT_ZLOGIC_POSITIVE						0
#define	CNT_ZLOGIC_NEGATIVE						1
// Signal Source
#define	CNT_SIGTYPE_ISOLATE						0
#define	CNT_SIGTYPE_TTL							1
#define	CNT_SIGTYPE_LINERECEIVER				2
// Count Direction
#define	CNT_DIR_DOWN							0
#define	CNT_DIR_UP								1
// 1Phase/2Phase
#define	CNT_MODE_1PHASE							0
#define	CNT_MODE_2PHASE							1
#define	CNT_MODE_GATECONTROL					2
// Mul
#define	CNT_MUL_X1								0
#define	CNT_MUL_X2								1
#define	CNT_MUL_X4								2
// Sync Clear
#define	CNT_CLR_ASYNC							0
#define	CNT_CLR_SYNC							1
// Generic I/O Signal
#define	CNT_GENIO_LINERECEIVER					0
#define	CNT_GENIO_TTL							1
// Output Logic
#define	CNT_OEVENT_NEGATIVE						0
#define	CNT_OEVENT_POSITIVE						1
// Output Hardware Event
#define	CNT_OEVENT_GENOUT						0x00
#define	CNT_OEVENT_MATCH0						0x01
#define	CNT_OEVENT_MATCH1						0x02
#define	CNT_OEVENT_FLTERR						0x04
#define	CNT_OEVENT_AIERR						0x08
#define	CNT_OEVENT_ALMERR						0x10
// Input Signal Event
#define	CNT_IEVENT_GENINP						0
#define	CNT_IEVENT_STARTSTOP					1
#define	CNT_IEVENT_PRESET						2
#define	CNT_IEVENT_CLEAR						3
// RISE/FALL
#define	CNT_INP_NONE							0
#define	CNT_INP_RIZE							1
#define	CNT_INP_FALL							2
// Count Match Event
#define	CNT_MATCH_NONE							0
#define	CNT_MATCH_PRESET						1
#define	CNT_MATCH_CLEAR							2
// Error Type
#define	CNT_AI_ERROR							1
#define	CNT_FLT_ERROR							2
#define	CNT_ALM_ERROR							3
// Carry/Borrow
#define	CNT_CB_CARRY							1
#define	CNT_CB_BORROW							2
//================================================================
// Others
//================================================================
// Start/stop comparison match
#define	CNT_MATCH_STOP							0
#define	CNT_MATCH_START							1
// Start/stop timer
#define	CNT_TIMER_STOP							0
#define	CNT_TIMER_START							1
// Start/stop counter error notification
#define	CNT_CNT_ERR_STOP			            0
#define	CNT_CNT_ERR_START			            1
// Start/stop carry borrow notification
#define	CNT_CB_STOP					            0
#define	CNT_CB_START				            1
//================================================================
// Information Type
//================================================================
#define	ICNT_DEVICE_TYPE						0				// Device Type.Param1:short
#define	ICNT_NUMBER_OF_CH						1				// Number of Channels Param1:short
#define	ICNT_BIT								2				// Number of Bits Param1:short
#define	ICNT_IS_DIGITAL_FILTER					3				// Is it the digital filter?    Param1:short(True/False)
#define	ICNT_IS_DEFF							4				// Is it the defferential conversion of general-purpose inupt?	Param1:short(True/False)
#define	ICNT_CNTSOURCE							5				// The selected available range of signal source:Param1:short
#define	ICNT_BOARD_TYPE							20				// Board type
// Cnt Source
#define	ICNT_CNTSOURCE_TTL						0x01
#define	ICNT_CNTSOURCE_PHOTO					0x02
#define	ICNT_CNTSOURCE_LINERECEIVER				0x04
//================================================================
// Device Type
//================================================================
#define	DEVICE_TYPE_ISA							0				//ISA or C Bus
#define	DEVICE_TYPE_PCI							1				//PCI Bus
#define	DEVICE_TYPE_PCMCIA						2				//PCMCIA
#define	DEVICE_TYPE_USB							3				//USB
#define	DEVICE_TYPE_FIT							4				//FIT

// SyncSignal
#define	CNTS_CLOCK_OUT_OFF						0
#define	CNTS_CLOCK_OUT_ON						1
#define	CNTS_START_OUT_OFF						0
#define	CNTS_START_OUT_ON						1
#define	CNTS_STOP_OUT_OFF						0
#define	CNTS_STOP_OUT_ON						1
// Sampling Start
#define	CNTS_START_SOFT							1				// Software Start
#define	CNTS_START_EXT_RISE						2				// External Start Rise
#define	CNTS_START_EXT_FALL						3				// External Start Fall
#define	CNTS_START_CNTMATCH_CH0_REG0			4				// Count Match CH0:REG0
#define	CNTS_START_CNTMATCH_CH1_REG0			5				// Count Match CH1:REG0
#define	CNTS_START_CNTMATCH_CH2_REG0			6				// Count Match CH2:REG0
#define	CNTS_START_CNTMATCH_CH3_REG0			7				// Count Match CH3:REG0
#define	CNTS_START_CNTMATCH_CH4_REG0			8				// Count Match CH4:REG0
#define	CNTS_START_CNTMATCH_CH5_REG0			9				// Count Match CH5:REG0
#define	CNTS_START_CNTMATCH_CH6_REG0			10				// Count Match CH6:REG0
#define	CNTS_START_CNTMATCH_CH7_REG0			11				// Count Match CH7:REG0
#define	CNTS_START_CNTMATCH_CH0_REG1			12				// Count Match CH0:REG1
#define	CNTS_START_CNTMATCH_CH1_REG1			13				// Count Match CH1:REG1
#define	CNTS_START_CNTMATCH_CH2_REG1			14				// Count Match CH2:REG1
#define	CNTS_START_CNTMATCH_CH3_REG1			15				// Count Match CH3:REG1
#define	CNTS_START_CNTMATCH_CH4_REG1			16				// Count Match CH4:REG1
#define	CNTS_START_CNTMATCH_CH5_REG1			17				// Count Match CH5:REG1
#define	CNTS_START_CNTMATCH_CH6_REG1			18				// Count Match CH6:REG1
#define	CNTS_START_CNTMATCH_CH7_REG1			19				// Count Match CH7:REG1
#define	CNTS_START_EXTSIG_1						20				// EXTSIG1
#define	CNTS_START_EXTSIG_2						21				// EXTSIG2
#define	CNTS_START_EXTSIG_3						22				// EXTSIG3
// Sampling Clock
#define	CNTS_CLOCK_CLOCK						1				// Internal Clock
#define	CNTS_CLOCK_EXT_TRG						2				// External Clock
#define	CNTS_CLOCK_EXTSIG_1						3				// EXTSIG1
#define	CNTS_CLOCK_EXTSIG_2						4				// EXTSIG2
#define	CNTS_CLOCK_EXTSIG_3						5				// EXTSIG3
// Internal Clock
#define	CNTS_TIM_UNIT_S							1
#define	CNTS_TIM_UNIT_MS						2
#define	CNTS_TIM_UNIT_US						3
#define	CNTS_TIM_UNIT_NS						4
// Sampling Stop
#define	CNTS_STOP_SOFT							1				// Software Stop
#define	CNTS_STOP_EXT_RISE						2				// External Stop Rize
#define	CNTS_STOP_EXT_FALL						3				// External Stop Fall
#define	CNTS_STOP_NUM							4				// Stop with Number of Data
#define	CNTS_STOP_CNTMATCH_CH0_REG0				5				// Count Match CH0:REG0
#define	CNTS_STOP_CNTMATCH_CH1_REG0				6				// Count Match CH1:REG0
#define	CNTS_STOP_CNTMATCH_CH2_REG0				7				// Count Match CH2:REG0
#define	CNTS_STOP_CNTMATCH_CH3_REG0				8				// Count Match CH3:REG0
#define	CNTS_STOP_CNTMATCH_CH4_REG0				9				// Count Match CH4:REG0
#define	CNTS_STOP_CNTMATCH_CH5_REG0				10				// Count Match CH5:REG0
#define	CNTS_STOP_CNTMATCH_CH6_REG0				11				// Count Match CH6:REG0
#define	CNTS_STOP_CNTMATCH_CH7_REG0				12				// Count Match CH7:REG0
#define	CNTS_STOP_CNTMATCH_CH0_REG1				13				// Count Match CH0:REG1
#define	CNTS_STOP_CNTMATCH_CH1_REG1				14				// Count Match CH1:REG1
#define	CNTS_STOP_CNTMATCH_CH2_REG1				15				// Count Match CH2:REG1
#define	CNTS_STOP_CNTMATCH_CH3_REG1				16				// Count Match CH3:REG1
#define	CNTS_STOP_CNTMATCH_CH4_REG1				17				// Count Match CH4:REG1
#define	CNTS_STOP_CNTMATCH_CH5_REG1				18				// Count Match CH5:REG1
#define	CNTS_STOP_CNTMATCH_CH6_REG1				19				// Count Match CH6:REG1
#define	CNTS_STOP_CNTMATCH_CH7_REG1				20				// Count Match CH7:REG1
#define	CNTS_STOP_EXTSIG_1						21				// EXTSIG1
#define	CNTS_STOP_EXTSIG_2						22				// EXTSIG2
#define	CNTS_STOP_EXTSIG_3						23				// EXTSIG3
// ExtSig
#define	CNTS_EXT_NOTUSE							0				// Not Used
#define CNTS_EXT_START_SOFT						1				// Software Start
#define CNTS_EXT_STOP_SOFT						2				// Software Stop
#define CNTS_EXT_CLOCK							3				// Internal Clock
#define CNTS_EXT_EXT_TRG						4				// External Clock
#define CNTS_EXT_START_EXT_RISE					5				// External Start Rize
#define CNTS_EXT_START_EXT_FALL					6				// External Start Fall
#define CNTS_EXT_STOP_EXT_RISE					7				// External Stop Rize
#define CNTS_EXT_STOP_EXT_FALL					8				// External Stop Fall
#define CNTS_EXT_CLOCK_ERROR					9				// Sampling Clock Error
#define	CNTS_EXT_TRNSNUM						10				// Stop Number of Transfer Data
#define	CNTS_EXT_CNTMATCH_CH0_REG0				11				// Count Match Ch0:REG0
#define	CNTS_EXT_CNTMATCH_CH1_REG0				12				// Count Match CH1:REG0
#define	CNTS_EXT_CNTMATCH_CH2_REG0				13				// Count Match CH2:REG0
#define	CNTS_EXT_CNTMATCH_CH3_REG0				14				// Count Match CH3:REG0
#define	CNTS_EXT_CNTMATCH_CH4_REG0				15				// Count Match CH4:REG0
#define	CNTS_EXT_CNTMATCH_CH5_REG0				16				// Count Match CH5:REG0
#define	CNTS_EXT_CNTMATCH_CH6_REG0				17				// Count Match CH6:REG0
#define	CNTS_EXT_CNTMATCH_CH7_REG0				18				// Count Match CH7:REG0
#define	CNTS_EXT_CNTMATCH_CH0_REG1				19				// Count Match CH0:REG1
#define	CNTS_EXT_CNTMATCH_CH1_REG1				20				// Count Match CH1:REG1
#define	CNTS_EXT_CNTMATCH_CH2_REG1				21				// Count Match CH2:REG1
#define	CNTS_EXT_CNTMATCH_CH3_REG1				22				// Count Match CH3:REG1
#define	CNTS_EXT_CNTMATCH_CH4_REG1				23				// Count Match CH4:REG1
#define	CNTS_EXT_CNTMATCH_CH5_REG1				24				// Count Match CH5:REG1
#define	CNTS_EXT_CNTMATCH_CH6_REG1				25				// Count Match CH6:REG1
#define	CNTS_EXT_CNTMATCH_CH7_REG1				26				// Count Match CH7:REG1
// Status
#define	CNTS_STATUS_BMSTOP						0x1
#define	CNTS_STATUS_CNTSTART					0x2
#define	CNTS_STATUS_CNTSTOP						0x4
#define	CNTS_STATUS_TRGIN						0x8
#define	CNTS_STATUS_OVERRUN						0x10
// Error
#define CNTS_STATUS_FIFOEMPTY					0x1
#define CNTS_STATUS_FIFOFULL					0x2
#define CNTS_STATUS_SGOVERIN					0x4
#define CNTS_STATUS_TRGERR						0x8
#define CNTS_STATUS_CLKERR						0x10
#define CNTS_STATUS_SLAVEHALT					0x20
#define CNTS_STATUS_MASTERHALT					0x40	
// Count Mode
#define	CNTS_MODE_NORMAL						0				// Normal Counter
#define	CNTS_MODE_DIFF							1				// Differencial Counter
// Counter Start
#define	CNTS_START_CNT_NOT_WITH_SAMP			3				// Counter Start not with Sampling Start
#define	CNTS_START_CNT_WITH_SAMP				4				// Counter Start with Sampling Start
// Counter Stop
#define	CNTS_STOP_CNT_NOT_WITH_SAMP				3				// Counter Stop not with Sampling Stop
#define	CNTS_STOP_CNT_WITH_SAMP					4				// Counter Stop with Sampling Stop
// Reset
#define	CNTS_RESET_ALL							0x01
#define	CNTS_RESET_FIFO_IN						0x02
// Buffer
#define	CNTS_WRITE_ONCE							0
#define	CNTS_WRITE_RING							1
// Count Match Direction(UP=1, DOWN=2)
#define	CNTM_DIR_UP								1				// match of up count
#define	CNTM_DIR_DOWN							2				// match of down count

//================================================================
// Function Prototype
//================================================================
#ifdef __cplusplus
extern "C"{
#endif
// Common function
long CntInit(char *device_name, short *id);
long CntExit(short id);
long CntResetDevice(short id);
long CntGetErrorString(long err_code, char *err_string);
// Setting function (set)
long CntSetZMode (short id, short ch_no, short zmode);
long CntSetZLogic(short id, short ch_no, short zlogic);
long CntSelectChannelSignal (short id, short ch_no, short sig_type);
long CntSetCountDirection (short id, short ch_no, short dir);
long CntSetOperationMode (short id, short ch_no, short phase, short mul, short sync_clr);
long CntSetDigitalFilter (short id, short ch_no, short filter_value);
long CntSetPulseWidth (short id, short ch_no, short pls_width);
long CntSetInputType(short id, short ch_no, short type);
long CntSetOutputHardwareEvent(short Id, short ChNo, short OutputLogic, int EventType, short PulseWidth);
long CntSetInputHardwareEvent(short Id, short ChNo, int EventType, short RF0, short RF1, short Reserved);
long CntSetCountMatchHardwareEvent(short Id, short ChNo, short RegisterNo, int EventType, short Reserved);
long CntSetPresetRegister(short Id, short ChNo, unsigned int PresetData, short Reserved);
// Setting function (get)
long CntGetZMode (short id, short ch_no, short *zmode);
long CntGetZLogic(short id, short ch_no, short *zlogic);
long CntGetChannelSignal (short id, short ch_no, short *sig_type);
long CntGetCountDirection (short id, short ch_no, short *dir);
long CntGetOperationMode (short id, short ch_no, short *phase, short *mul, short *sync_clr);
long CntGetDigitalFilter (short id, short ch_no, short *filter_value);
long CntGetPulseWidth (short id, short ch_no, short *pls_width);
// Counter function
long CntStartCount(short id, short *ch_no, short ch_num);
long CntStopCount(short id, short *ch_no, short ch_num);
long CntPreset(short id, short *ch_no, short ch_num, unsigned long *preset_data);
long CntZeroClearCount(short Id, short *ChNo, short chNum);
long CntReadCount(short id, short *ch_no, short ch_num, unsigned long *count_data);
long CntReadStatus (short id, short ch_no, short *sts);
long CntReadStatusEx(short Id, short ChNo, int *Sts);
// Notify function
long CntSetCountMatchEvent (short id, short ch_no, short reg_no, unsigned long count, short start);
long CntSetCountMatchCallBackProc(short id, PCNT_MATCH_CALLBACK call_back , void *param);
long CntSetCounterErrorEvent(short Id, short start);
long CntSetCounterErrorCallbackProc(short Id, PCNT_COUNTER_ERR_CALLBACK CallBackProc, void *Param);
long CntSetCarryBorrowEvent(short Id, short start);
long CntSetCarryBorrowCallbackProc(short Id, PCNT_CARRY_BORROW_CALLBACK CallBackProc, void *Param);
long CntSetTimeUpEvent(short id , unsigned long time_value, short start);
long CntSetTimeUpCallBackProc(short id, PCNT_TIMEUP_CALLBACK call_back , void *param);
// General purpose input function
long CntOutputDOBit(short Id, short ChNo, short Reserved, unsigned char OutData);
long CntInputDIByte(short id , short reserved, unsigned char *bdata);
// Test function
long CntSetTestPulse(short Id, short Internal, short Out, int Reserved);
// Sampling mode function
long CntSetStandAlone(short Id);
long CntSetCounterMode(short Id, short ChNo, short CountMode);
// Information function
long CntQueryDeviceName(short Index, char *device_name, char *device);
long CntGetMaxChannels(short id,  short *ch_num);
// Sampling condition function
long CntSetSamplingStartTrigger(short Id, short StartTrg, short CountStartMode, short CountChNum);
long CntSetSamplingClockTrigger(short Id, short ClockTrg);
long CntSetSamplingStopTrigger(short Id, short StopTrg, short CountStopMode, short CountChNum);
long CntSetSamplingInternalClock(short Id, unsigned int Clock, short Unit);
long CntSetSamplingStopNumber(short Id, unsigned int StopNum);
// Sampling operation function
long CntSamplingFifoReset(short Id);
long CntSamplingSetBuffer(short Id, unsigned int *Buffer, short ChNum, unsigned int ScanNum, short IsRing);
long CntSamplingStart(short Id);
long CntSamplingStop(short Id);
// Sampling status function
long CntGetSamplingStatus(short Id, unsigned int *Status, unsigned int *Err);
long CntGetSamplingCount(short Id, int *ScanCount, int *ScanCarry);
long CntGetSamplingWritePointer(short Id, int *WritePointer, int *ScanCount, int *ScanCarry);
// Sampling event function
long CntSetSamplingStopEvent(short Id, PCNT_SAMPLING_STOP_CALLBACK CallBackProc, void *Param);
long CntSetSamplingCountEvent(short Id, unsigned int Count, PCNT_SAMPLING_COUNT_CALLBACK CallBackProc, void *Param);

long CntGetDeviceInfo(char *device, short info_type, void *param1, void *param2, void *param3);
#ifdef __cplusplus
};
#endif
#endif