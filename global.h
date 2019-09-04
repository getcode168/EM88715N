//----------------------------------------------------------------------------------------
//	;Model: PF-101  搅拌机:100-240V 50/60Hz                    
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
	
//-----------------变量定义---------------------------------------------------------------
	#define DISENABLE_PROTECT  0u  //1u软件不保护 0u开软件保护
		
	#define	PID_DATAUPTIME 3
		
	#define INTERNALLOCK_CNT_VALUE  3  			 //5*8ms=40ms  40ms无过零信号即无安全锁定。
	#define TIME_CRUSHED_ICE_MODE   20  		 //碎冰时间60
	#define TIME_SPEED_CONTROL_MODE 20 		 		//调速时间60	
	#define SPEED1_RPM_SET  500			//500*20=10000rpm
	#define SPEED2_RPM_SET  900			//900*20=18000rpm	
	
	#define ICE_SPEED_MIN  60			//
	#define ICE_SPEED_MAX  600	
	#define ICE_SPEED_FIRST  450		
	#define OUT_ICE_TIME  23	
	#define DELAY_ICE_TIME 3
		
//----------------慢加速参数-------------------------------------------------------------

	#define SPEED_SLOW_ADD 2		//2其他PRE_SET+WORK LEVEL1加速参数 5*16=80rpm/8ms
	#define SPEED_SLOW_DEC 2    	//2减速参数 2*16=32rpm/8ms
	
	
/****************************7643 220V 50Hz  碎肉测试数据*************************************
马达直径电源测试，齿轮比8:1   2420RPM @230V 50Hz 2240RPM @220V 50Hz
philips Min 1800rpm  Max 2400RPM at 220v 50Hz
  碎肉全功率开230W @230V 50Hz
  philips全功率开230W @230V 50Hz
		
	CHOP_POWER_SET=73 胡萝卜OK  340W	
	CHOP_POWER_SET=82 香菜OK   170W
	CHOP_POWER_SET=72 洋葱OK  90W		
	设定105-----不放碎肉杯空载?RPM 142W
	设定100-----碎肉杯空载1600RPM*8  不放碎肉杯空载16000RPM 142W 
	设定90-----不放杯空载14700RPM 138W 
	设定85-----不放杯空载13800RPM 110W 
	设定80-----不放杯空载12600RPM 95W 
	设定75-----不放杯空载11200RPM 82W 
	设定70-----不放杯空载10400RPM 72W 
	设定65-----不放杯空载9000RPM 57W 
	设定60-----不放杯空载7400RPM 46W 
********************************************************************************************/

#define POWER_ADD 1			//软启动用

//-----------------硬件定义端口hardware output I/O defintion------------------------------
static bit trigger_out_p	  	@0x05@5: rpage 0;	//触发P55输出
static bit iec_p    					@0x06@3: rpage 0;	//P63 
static bit speed1_p    				@0x06@6: rpage 0;	//P66输入 
static bit speed2_p    				@0x06@7: rpage 0;	//P67输入 
static bit pwr_p    					@0x05@7: rpage 0;	//P57 							
static bit cs_relay_p     	  @0x05@6: rpage 0;	//继电器    P57输出  
static bit hall_a_p     	  	@0x06@0: rpage 0;	// 
static bit hall_b_p     	  	@0x06@1: rpage 0;	//
//----------------------------------------------------------------------------------------

			 									 
#endif 


