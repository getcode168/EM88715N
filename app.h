
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
//-----------------λ��������-------------------------------------------------------------

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
	
	
	extern	bit process_10ms_f;								//8ms������  the sign of process task
												//����0     ���		����1	����2		����3
	//enum work_mode_value{ WORK_OFF=0,WORK_READY,WORK_IEC=1,WORK_SPEED1=2,WORK_SPEED2=3,WORK_PROTECT=4,WORK_LOSTLOCK=5};//����ģʽ
	
	//enum key_type {KEY_NULL=0,KEY_ICE=1,KEY_SPEED1=2,KEY_SPEED2=3};//����ģʽ
//-----------------�궨��||���뿪��-------------------------------------------------------
//	#define GET_BIT(x,y)   (((x)&(1<<(y)))==0?0:1)  //ȡx����yλ������

//-----------------Zero cross ���㴥��----------------------------------------------------
	extern 	u16 power_set;						//1-200 (0��200)���⴦��
	extern 	u8 power_l;						//1-200 (0��200)���⴦��
	extern	u8 power_h;						//1-200 (0��200)���⴦��
	extern 	u8 trigger_delay_h;					//��ʱ������λ����
	extern	u8 trigger_delay_l;					//��ʱ������λ����
	
	extern	u8 zc_counter;						//������� the counter of zero cross
	extern 	bit en_zc_count_f;								//����������λ the flag of counter of zero cross
	extern	bit fre_check_ok_f;								//��Ƶ���OKλ��1���ɹ���0λ���ʧ��
	extern	bit is_50hz_f;									//Ƶ�ʱ�־λ1Ϊ50Hz 0Ϊ60Hz
	extern	bit frist_zc_f;									//��һ�ι����־��0��һ�Σ�1λ������
	
	extern	bit en_fire_f;									//���������ر�־λ
	
	
//-----------------�����Ĵ���-----------------------------------------------------------------
	extern	_WorkType work_mode;	      				//����ģʽ
	extern	_WorkType old_work_mode;	      				//����ģʽ
	extern	bit switch_on_f;								//���ر�־
	extern	bit working_f;								//���ر�־
	extern	bit en_relay_f;								//���ر�־
	extern  u8  return_off;

//-----------------action------------------------------------------------------------
	extern 	u8 work_step_cout;					//������CNT
	
	extern 	u8 work_cout;						//����CNT
	extern 	u8 job_timer_cnt;					//���ڹ�����ʱ
	extern 	u8 job_cnt;							//���������ָ���ֱ�ӿ��������õ��ڼ�����
	extern 	u8 timer_set;						//��ʱֵ����	
	extern 	u8 second_cout;						//��ʱ����� the count of second
	extern	u8 count_10ms;						//��ʱ8ms���� the count of 8ms
	
	extern	u8 ice_step;   						//������е��ڼ��� 
	extern	u8 ice_step_cnt;   				
	extern	u8 protect_cnt;   	
	extern bit en_protect_cnt_f;
	
	extern	u8 interlock_cnt;					//��������	the count of interlock
	extern	bit interlock_f;								//������־  the sign of interlock	
	extern	bit time_over_f;								//��ʱʱ�䵽
	extern	u8 	 temp_8;						//����ֵ	
	extern	u16  temp1_16;  						//��ʱֵ	

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


