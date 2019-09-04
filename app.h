
/***************************************************************************************
	Model		: adc.h
	Description	: Head file of adc
	Author		: harry
	Create Time	: 2019.01.03
	Version ID  : V1
	Mcu			: EM88F715N 20pin
****************************************************************************************/
#ifndef app_h__
	#define app_h__

	#include "EM88F715N.H"
	#include "type.h"	
	#include "global.h"

	extern	u16  read_speed_rpm;
	extern u16  set_rpm;
	extern u16  set_rpm_buffer;	
	extern 	bit  soft_run_f;
	extern u8  speed_cnt_l;
	extern u8  speed_cnt_h;	
	extern u8  speed_buffer_cnt_l;
	extern u8  speed_buffer_cnt_h;
	
	extern u8 	 off_cnt;	
//-----------------位变量定义-------------------------------------------------------------

typedef enum{
		WORK_OFF			=	(u8)0,
		WORK_READY		=	(u8)1,
		WORK_IEC			=	(u8)2,
		WORK_SPEED1		=	(u8)3,
		WORK_SPEED2		=	(u8)4,
		WORK_PROTECT	=	(u8)5,
		WORK_LOSTLOCK	=	(u8)6,
	}_WorkType;


typedef enum{
		KEY_NULL			=	(u8)0,
		KEY_ICE				=	(u8)1,
		KEY_SPEED1		=	(u8)2,
		KEY_SPEED2		=	(u8)3,

	}_KEY_Type;
	
	
	extern	bit process_10ms_f;								//8ms任务标记  the sign of process task
												//待机0     碎冰		搅拌1	搅拌2		搅拌3
	//enum work_mode_value{ WORK_OFF=0,WORK_READY,WORK_IEC=1,WORK_SPEED1=2,WORK_SPEED2=3,WORK_PROTECT=4,WORK_LOSTLOCK=5};//工作模式
	
	//enum key_type {KEY_NULL=0,KEY_ICE=1,KEY_SPEED1=2,KEY_SPEED2=3};//工作模式
//-----------------宏定义||编译开关-------------------------------------------------------
//	#define GET_BIT(x,y)   (((x)&(1<<(y)))==0?0:1)  //取x变量y位的数据

//-----------------Zero cross 过零触发----------------------------------------------------
	extern 	u16 power_set;						//1-200 (0，200)特殊处理
	extern 	u8 power_l;						//1-200 (0，200)特殊处理
	extern	u8 power_h;						//1-200 (0，200)特殊处理
	extern 	u8 trigger_delay_h;					//定时触发高位计数
	extern	u8 trigger_delay_l;					//定时触发低位计数
	
	extern	u8 zc_counter;						//过零计数 the counter of zero cross
	extern 	bit en_zc_count_f;								//允许过零计数位 the flag of counter of zero cross
	extern	bit fre_check_ok_f;								//工频检测OK位，1检测成功，0位检测失败
	extern	bit is_50hz_f;									//频率标志位1为50Hz 0为60Hz
	extern	bit frist_zc_f;									//第一次过零标志，0第一次，1位过零了
	
	extern	bit en_fire_f;									//允许触发开关标志位
	
	
//-----------------工作寄存器-----------------------------------------------------------------
	extern	_WorkType work_mode;	      				//工作模式
	extern	_WorkType old_work_mode;	      				//工作模式
	extern	bit switch_on_f;								//开关标志
	extern	bit working_f;								//开关标志
	extern	bit en_relay_f;								//开关标志
	extern  u8  return_off;

//-----------------action------------------------------------------------------------
	extern 	u8 work_step_cout;					//工作步CNT
	
	extern 	u8 work_cout;						//工作CNT
	extern 	u8 job_timer_cnt;					//用于工作计时
	extern 	u8 job_cnt;							//避免连锁恢复后直接开机动作用到在计数器
	extern 	u8 timer_set;						//定时值设置	
	extern 	u8 second_cout;						//定时秒计数 the count of second
	extern	u8 count_10ms;						//定时8ms计数 the count of 8ms
	
	extern	u8 ice_step;   						//碎冰运行到第几步 
	extern	u8 ice_step_cnt;   				
	extern	u8 protect_cnt;   	
	extern bit en_protect_cnt_f;
	
	extern	u8 interlock_cnt;					//连锁计数	the count of interlock
	extern	bit interlock_f;								//连锁标志  the sign of interlock	
	extern	bit time_over_f;								//计时时间到
	extern	u8 	 temp_8;						//缓冲值	
	extern	u16  temp1_16;  						//临时值	

//-------------------------------------------------------------------- 		
	extern void Time_prosess(void);
	extern void Scan_task(void);	
	extern void Task_8ms(void);	
	extern void Scan_task(void);
	extern _KEY_Type Scan_Key(void);
	extern void Control_task(void);
	void Pid_Init(void);


	void Time_prosess(void);
	void Scan_task(void);	
	void Task_8ms(void);	
	_KEY_Type Scan_KEY(void);
	void Over_LoadDetection(void);
	void Control_task(void);
	extern void Prosess_10ms(void);
		
#endif


