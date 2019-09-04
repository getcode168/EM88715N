//----------------------------------------------------------------------------------------
//	;Model: PF-101  �����:100-240V 50/60Hz                    
//	;MCU EM88F715N 
//	;Supply Voltage = 5V  
//----------------------------------------------------------------------------------------
/*
Option detail:

  NRE                           Enable
  NRHL                          32/fc
  ENWDT                         Disable
  RESETEN                       /RST
  VDD RESET/RELEASE LEVEL       3.8V/4.0V
  HLP                           High
  HLFS                          Normal
  IODG                          50ns
  OSC                           IRC(P51 functions as I/O pin)
  RCM                           16MHz
  FSS                           16KHz
  IRCPSS                        Int. ref.
  
  SHCLK                         8 clock
  SHEN                          Enable
  ID0                           
  ID1                           
  ID2                           
  ID3                           
  ID4                           
  ID5                           
  IRCOMS                        Speedup
  ADFM                          
  EFTIM                         Light

*/
#ifndef _GLOGAL_H__ 
	#define _GLOGAL_H__ 
	
	#include "type.h"	
	
//-----------------��������---------------------------------------------------------------
	#define DISENABLE_PROTECT  0u  //1u��������� 0u���������
		
	#define	PID_DATAUPTIME 3
		
	#define INTERNALLOCK_CNT_VALUE  3  			 //5*8ms=40ms  40ms�޹����źż��ް�ȫ������
	#define TIME_CRUSHED_ICE_MODE   20  		 //���ʱ��60
	#define TIME_SPEED_CONTROL_MODE 20 		 		//����ʱ��60	
	#define SPEED1_RPM_SET  500			//500*20=10000rpm
	#define SPEED2_RPM_SET  900			//900*20=18000rpm	
	
	#define ICE_SPEED_MIN  60			//
	#define ICE_SPEED_MAX  600	
	#define ICE_SPEED_FIRST  450		
	#define OUT_ICE_TIME  23	
	#define DELAY_ICE_TIME 3
		
//----------------�����ٲ���-------------------------------------------------------------

	#define SPEED_SLOW_ADD 2		//2����PRE_SET+WORK LEVEL1���ٲ��� 5*16=80rpm/8ms
	#define SPEED_SLOW_DEC 2    	//2���ٲ��� 2*16=32rpm/8ms
	
	
/****************************7643 220V 50Hz  �����������*************************************
���ֱ����Դ���ԣ����ֱ�8:1   2420RPM @230V 50Hz 2240RPM @220V 50Hz
philips Min 1800rpm  Max 2400RPM at 220v 50Hz
  ����ȫ���ʿ�230W @230V 50Hz
  philipsȫ���ʿ�230W @230V 50Hz
		
	CHOP_POWER_SET=73 ���ܲ�OK  340W	
	CHOP_POWER_SET=82 ���OK   170W
	CHOP_POWER_SET=72 ���OK  90W		
	�趨105-----�������Ɑ����?RPM 142W
	�趨100-----���Ɑ����1600RPM*8  �������Ɑ����16000RPM 142W 
	�趨90-----���ű�����14700RPM 138W 
	�趨85-----���ű�����13800RPM 110W 
	�趨80-----���ű�����12600RPM 95W 
	�趨75-----���ű�����11200RPM 82W 
	�趨70-----���ű�����10400RPM 72W 
	�趨65-----���ű�����9000RPM 57W 
	�趨60-----���ű�����7400RPM 46W 
********************************************************************************************/

#define POWER_ADD 1			//��������

//-----------------Ӳ������˿�hardware output I/O defintion------------------------------
static bit trigger_out_p	  	@0x05@5: rpage 0;	//����P55���
static bit iec_p    					@0x06@3: rpage 0;	//P63 
static bit speed1_p    				@0x06@6: rpage 0;	//P66���� 
static bit speed2_p    				@0x06@7: rpage 0;	//P67���� 
static bit pwr_p    					@0x05@7: rpage 0;	//P57 							
static bit cs_relay_p     	  @0x05@6: rpage 0;	//�̵���    P57���  
static bit hall_a_p     	  	@0x06@0: rpage 0;	// 
static bit hall_b_p     	  	@0x06@1: rpage 0;	//
//----------------------------------------------------------------------------------------

			 									 
#endif 


