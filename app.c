/*---------------------------------------------------------------------------------------
	Model		: adc.c
	Description	: ADC Head file
	Author		: harry
	Create Time	: 2019.9.4
	Version ID  : V1  
	Mcu			: EM88F715N 20PIN
---------------------------------------------------------------------------------------*/
#include "app.h"

	u8 pid_dataup;	//PID数据更新周期 pid_dataup*8ms
  signed   short en=0;		// 当前误差
  signed   short en1=0;		// 上次误差
  signed   short en2=0;		// 上上次误差
  signed   short now_out=0;	//当前PID输出
  signed   short pre_out;	//上一次PID输出	
  float kp;	//比例系数	
  float ki;	//积分系数
  float kd;	//微分系数
		
	u16  speed_cntbuffer;   
	u16  read_speed_rpm;
	u16  set_rpm;
	u16  set_rpm_buffer;	
	
	u8  speed_cnt_l;
	u8  speed_cnt_h;	
	u8  speed_buffer_cnt_l;
	u8  speed_buffer_cnt_h;

//-----------------Zero cross 过零触发----------------------------------------------------
 	u16 power_set=0;						//1-200 (0，200)特殊处理
 	u8 power_l=0;						//1-200 (0，200)特殊处理
 	u8 power_h=0;						//1-200 (0，200)特殊处理
 	u8 trigger_delay_h;					//定时触发高位计数
 	u8 trigger_delay_l;					//定时触发低位计数
 	u8  zc_counter;						//过零计数 the counter of zero cross
 	bit en_zc_count_f;								//允许过零计数位 the flag of counter of zero cross
 	bit fre_check_ok_f;								//工频检测OK位，1检测成功，0位检测失败
 	bit is_50hz_f;									//频率标志位1为50Hz 0为60Hz
 	bit frist_zc_f;									//第一次过零标志，0第一次，1位过零了
 	bit en_fire_f;									//允许触发开关标志位

//-----------------工作寄存器-----------------------------------------------------------------
 	_WorkType work_mode;	      	//工作模式1
 	_WorkType old_work_mode;	    //工作模式
 	bit switch_on_f;							//开关标志
 	bit working_f;								//开关标志
 	bit en_relay_f;								//开关标志
 	bit  soft_run_f;	
	bit process_10ms_f;	//8ms任务标记  the sign of process task
	
	
//-----------------action------------------------------------------------------------
 	u8 work_step_cout;					//工作步CNT
	u8 protect_cnt; 
 	u8 work_cout;								//工作CNT
 	u8 job_timer_cnt;						//用于工作计时
 	u8 job_cnt;									//避免连锁恢复后直接开机动作用到在计数器
 	u8 timer_set;								//定时值设置	
 	u8 second_cout;							//定时秒计数 the count of second
 	u8 count_10ms;								//定时8ms计数 the count of 8ms
 	 	
 	u8 ice_step;   							//碎冰运行到第几步 crushed ice step
 	u8 ice_step_cnt; 
 	
 	bit frist_ice_f;
 	u8 ice_step_time; 
 	u8 ice_recorde_time1; 
 	u8 ice_recorde_time2;  
 	u8 ice_recog_cnt;
 	u8 ice_recog_cnt1; 	
 	u8 ice_step_recorde_time;
 	u8 ice_step_recorde_time1; 
 	u8 ice_step_recorde_time2;   	
 	bit en_protect_cnt_f;
 	 	
 	u8 interlock_cnt=0;					//连锁计数	the count of interlock
 	bit interlock_f;								//连锁标志  the sign of interlock	
 	bit time_over_f=0;								//计时时间到
 	u8 	 temp_8;						//缓冲值	
 	u16  temp1_16;  						//临时值			
	
	u8 	 off_cnt;						//	
	
	extern void delay_20us(void);
	extern void delay_1ms(u8 n);	


/*-------------------------------------------------------
---函 数 名：-Pid_Init
---功    能：-pid
---参    数：-
---返 回 值：-
---调    用：-
---前提条件：-
---说    明：-
	kp=1.15;
	ki=0.25;
	kd=0.36;  
-------------------------------------------------------*/
void Pid_Init(void)
{
  now_out=0;
  en=0;
  en1=0;
  en2=0;
  pre_out=0;
  
	kp=1.15;
	ki=0.25;
	kd=0.36;  
}

/*-------------------------------------------------------
---函 数 名：-Pid_Process
---功    能：-pid处理函数
---参    数：-void 
---返 回 值：-0-1000 功率值
---调    用：-
---前提条件：-
---说    明：-set_rpm---设定目标速度
			 -read_speed_rpm---读取速度
-------------------------------------------------------*/

u16 Pid_Process(void)
{

	en=set_rpm-read_speed_rpm;
	
	now_out=kd*(en-2*en1+en2);
	
	now_out=(en-en1+(ki*en)+now_out)*kp;
	
	now_out=now_out+pre_out;
	
	en2=en1;
	
	en1=en;    


	if(now_out>840)
	  {
	  	now_out=840;            
	  }
	if(now_out<50)
	  {
	  	now_out=50;            
	  }
	pre_out=now_out;
	
	return now_out;
}


void Prosess_10ms(void)
{
	if (process_10ms_f) 
		{	
			Time_prosess();			
			process_10ms_f=0;
			Task_8ms();			//触发值按工频转换TCCB延时初值						
			if (work_mode==WORK_OFF)
				{
					if(off_cnt<200)
					{
						off_cnt++;
					}
				}
			else
				{
					off_cnt=0;
				}									
		}
}

//----------------------------------------------------------------------------------------
// 函数名称：time_prosess(void)
// 函数功能：
// 入口函数：用全局变量
// 出口函数：全局变量
//----------------------------------------------------------------------------------------	

void Task_8ms(void)  	  
{		
//----------计算速度----------------------------------------------
	speed_cntbuffer=speed_buffer_cnt_h;
	speed_cntbuffer=speed_cntbuffer<<8;
	speed_cntbuffer+=speed_buffer_cnt_l;	
	if((speed_cntbuffer<55)&&(speed_cntbuffer>3))	
	speed_cntbuffer=speed_cntbuffer;
	
	if (speed_cntbuffer>10) //4us
  {
  	read_speed_rpm=60000/speed_cntbuffer; //read_speed_rpm*20=rpm
  }
  else 
  {
  	read_speed_rpm=0;
  }
//-----------------功率值转换为触发定时初值-----------------------------------------------
	temp1_16=power_set;
	
	
	if(power_set>700)
	temp1_16=temp1_16;
	
	
	if (power_set>1000) 
		{
			temp1_16=0;
		}
	power_l=temp1_16;		//默认低8位赋值给trigger_delay_l
	power_h=temp1_16>>8;	
	if((temp1_16>=1)&&(temp1_16<=1000)) 
		{
			if (is_50hz_f) 
				{
					temp1_16=20000-(temp1_16*20);	//20000=10ms
				}
			else 
				{
					temp1_16=16667-(temp1_16*16);	
				}
			trigger_delay_l=temp1_16;		//默认低8位赋值给trigger_delay_l
			trigger_delay_h=temp1_16>>8;				
	}	

	
//-----------------1-3档的软启动处理------------------------------------------------------	
	if (soft_run_f&&en_fire_f&&switch_on_f) 
	{
		if (soft_run_f) 
			{
					
				if(set_rpm_buffer>set_rpm)
					{
						if((set_rpm_buffer<1001)&&(set_rpm<1001))
							{
								set_rpm=set_rpm+SPEED_SLOW_ADD;
							}
					}
				else if (set_rpm_buffer<set_rpm)
					{
						set_rpm=set_rpm_buffer;
					}	
				else 
					{
						set_rpm=set_rpm_buffer;
					}
			}
		else 
			{
				set_rpm_buffer=set_rpm_buffer;
			}
	}
	else if (en_fire_f&&switch_on_f) 
	{
		if (work_mode == WORK_IEC) 
		{
			set_rpm=set_rpm_buffer;
		}
	}	

//----------------------------------------------------------------------------------------
	if (!en_fire_f) 
		{
			set_rpm=0;
			trigger_out_p=0;
		}
//-------------------------PID处理--------------------------------------------------------	    
	if(set_rpm!=0)
		{
			pid_dataup++;
			if (pid_dataup>=PID_DATAUPTIME) //进入PID更新要时间计数溢出
		   	{
		   		pid_dataup=0;
		   		power_set=Pid_Process();		   						   									   						   					   		 
		   	}                           	                                                      
		}
	else
		{
			if(read_speed_rpm > 20)//1000RPM
				{
					pid_dataup++;
					if (pid_dataup>=PID_DATAUPTIME) //进入PID更新要时间计数溢出
				   	{
				   		pid_dataup=0;
				   		temp1_16=Pid_Process();		   						   									   						   					   		 
				   	} 
				}
			else
				{
					Pid_Init();
				}
			power_set=0;
			pid_dataup=0;
		} 			
			
}

//----------------------------------------------------------------------------------------
// 函数名称：time_prosess(void)
// 函数功能：
// 入口函数：用全局变量
// 出口函数：全局变量
//----------------------------------------------------------------------------------------	

void Time_prosess(void)
{				
	if (second_cout>=125) //秒计时，8ms*125=1s
		{
			second_cout=0;		    					  
			if(working_f)
				{
					job_timer_cnt++;
				}
			else
				{
					job_timer_cnt=0;
				}
				
			if(en_protect_cnt_f)
			{
				protect_cnt++;
			}
			else
			{
				protect_cnt=0;
			}	
		}
	if(ice_step_cnt>=200)
		{
			ice_step_cnt=0;
			if(working_f&&(work_mode==WORK_IEC)&&en_fire_f)
				{
					ice_step_time++;
				}
		} 
}

//----------------------------------------------------------------------------------------
// 函数名称：Scan_Key(void)
// 函数功能：
// 入口函数：
// 出口函数：
//----------------------------------------------------------------------------------------

_KEY_Type Scan_Key(void)
{
	_KEY_Type key_temp=KEY_NULL;
	
		if (!iec_p) 
		{
			delay_20us();
			if (!iec_p) 
				key_temp=KEY_ICE;
		}	
	 if (!speed1_p)
		{
			delay_20us();
			if (!speed1_p)
				key_temp=KEY_SPEED1;
		}		
	 if (!speed2_p) 
		{
			delay_20us();
			if (!speed2_p) 
				key_temp=KEY_SPEED2;
		}
		Prosess_10ms();
	return key_temp;

}
//----------------------------------------------------------------------------------------
// 函数名称：
// 函数功能：
// 入口函数：
// 出口函数：
//----------------------------------------------------------------------------------------
	
void Scan_task(void)
{	
	_KEY_Type key_value=KEY_NULL;		
	
	key_value=Scan_Key();
//----------------------------	
	if((key_value!=KEY_NULL)&&(work_mode!=WORK_LOSTLOCK)&&(work_mode!=WORK_PROTECT))	
		{
			pwr_p=0;		
			delay_1ms(1);
			if(!hall_a_p)
				{
					if(!hall_b_p)
					pwr_p=0;
					else
					{
						work_mode=WORK_LOSTLOCK;
						pwr_p=1;					
					}						
				}
			else
				{	
					work_mode=WORK_LOSTLOCK;				
					pwr_p=1;		
				}			
		}	
					
	if (key_value==KEY_ICE) 			//碎冰模式
			{
				if ((!time_over_f)&&(work_mode!=WORK_LOSTLOCK)&&(work_mode!=WORK_PROTECT))
					{
						work_mode=WORK_IEC;	
						switch_on_f=1;									
					}											
			}
	else if (key_value==KEY_NULL)	//待机模式
			{		
			if((work_mode!=WORK_PROTECT)&&(work_mode != WORK_READY))	
				{
					work_mode=WORK_OFF;
					switch_on_f=0;
				}
			else if(work_mode == WORK_READY)
				{
					if(old_work_mode ==WORK_SPEED1)
					{
						work_mode=WORK_OFF;
					}
				}
			}
	else if (key_value==KEY_SPEED1) //搅拌速度1模式
			{
				if ((!time_over_f)&&(work_mode!=WORK_LOSTLOCK)&&(work_mode!=WORK_PROTECT))
					{
						work_mode=WORK_SPEED1;
						switch_on_f=1;
					}
				else if((work_mode == WORK_READY)||(old_work_mode == WORK_SPEED2))
					{
						old_work_mode=WORK_SPEED1;
					}								
			}
	else if (key_value==KEY_SPEED2)//搅拌速度2模式
			{

				if ((!time_over_f)&&(work_mode!=WORK_LOSTLOCK)&&(work_mode!=WORK_PROTECT))
					{
						work_mode=WORK_SPEED2;
						switch_on_f=1;
					}
				else if(work_mode == WORK_READY)
					{
						old_work_mode=WORK_SPEED2;
					}
			}									
	Over_LoadDetection();
}



//----------------------------------------------------------------------------------------
// 函数名称：work_mode_control(void)
// 函数功能：
// 入口函数：
// 出口函数：
//----------------------------------------------------------------------------------------
	
void Over_LoadDetection(void)
{
	
#if(DISENABLE_PROTECT==0u)
	
	if(work_mode == WORK_IEC)
   {
   	if(working_f&&en_fire_f)
   	{
   		if((power_set>200)&&(read_speed_rpm<100))
   		{
   			en_protect_cnt_f=1;
   			if(protect_cnt>=4)
   			{
   			//	work_mode= WORK_PROTECT;
   			}
   		}
   	}
   }
   else if((work_mode == WORK_SPEED1)||(work_mode == WORK_SPEED2))
   {
     if(working_f&&en_fire_f)
	   	{
	   		if((power_set>200)&&(read_speed_rpm<100))
	   		{
	   			en_protect_cnt_f=1;
	   			if(protect_cnt>=4)
	   			{
	   				work_mode= WORK_PROTECT;
	   			}
	   		}
	   	}
   }
#endif   
}



//----------------------------------------------------------------------------------------
// 函数名称：work_mode_control(void)
// 函数功能：
// 入口函数：
// 出口函数：
//----------------------------------------------------------------------------------------
	
void Control_task(void)
{
	
//----------------------计时操作----------------------------------------------------------
	if (working_f) 
		{
			if (job_timer_cnt>=timer_set) 	//如果时间到了停机
				{
					job_timer_cnt=0;
					time_over_f=1;
					switch_on_f=0;					
				}	
		}	
		
//-------------失去连锁操作---------------------------------------------------------------
	if ((interlock_f==0)&&working_f&&(job_cnt>=1)) //40ms 失去连锁，软件停机
		{
			//	switch_on_f=0;			//关机
			//	time_over_f=1;			//需复位到0ff位置才可重新开机避免连锁恢复后直接开机动作
		}	
	if (working_f) //40ms 失去连锁，软件停机
		{
			if(hall_b_p||hall_a_p)
			{				
				switch_on_f=0;			//关机
				time_over_f=1;			//需复位到0ff位置才可重新开机避免连锁恢复后直接开机动作
				work_mode=WORK_OFF;
			}		
		}			
//----------------------------------------------------------------------------------------

	if (work_mode==WORK_OFF) //
		{
			job_timer_cnt=0;
			power_set=0;
			working_f=0;
			power_set=0;
			interlock_f=0;			
			switch_on_f=0;
			fre_check_ok_f=0;
			set_rpm_buffer=0;
			set_rpm=0;
			
			job_timer_cnt=0;				//计时清0
			ice_step=0;						//从0开始工作
			soft_run_f=0;
			ice_step_cnt=0;
			
					
			if(off_cnt>150)
				{
					time_over_f=0;
				}					
			Pid_Init();
		}	
	if((work_mode==WORK_LOSTLOCK)||(work_mode==WORK_PROTECT)||(work_mode == WORK_READY))
		{
				switch_on_f=0;
				fre_check_ok_f=0;
				set_rpm_buffer=0;
				set_rpm=0;
		}
	else if (work_mode==WORK_IEC) //碎冰
		{		
			if (working_f==0) 
				{
					working_f=1;				//置工作标志位
					timer_set=TIME_SPEED_CONTROL_MODE;//赋工作时长置与计时工作寄存器
					job_timer_cnt=0;				//计时清0
					ice_step=0;						//从0开始工作
					soft_run_f=0;
					ice_step_cnt=0;
				}
			else 								
				{		
					switch(ice_step)
					{
						case 0://on and off when reach max speed
							if(!frist_ice_f)					
							{
								frist_ice_f=1;
								set_rpm_buffer=ICE_SPEED_FIRST;
							}
							else
							{
								set_rpm_buffer=ICE_SPEED_MAX;
							}
							switch_on_f=1;
							if(ice_recog_cnt==0)
							{
								if((read_speed_rpm>(ICE_SPEED_FIRST))&&(ice_step_time>4))
								{
									ice_step_time=0;
									ice_step_cnt=0;
									power_set=0;
									ice_step=1;
									frist_ice_f=0;
								}
							}
							else
							{
								if((read_speed_rpm>(ICE_SPEED_MAX))&&(ice_step_time>4))
								{
									ice_step_time=0;
									ice_step_cnt=0;
									set_rpm_buffer=0;
									set_rpm=0;
									power_set=0;
									ice_step=1;
									frist_ice_f=0;
								}							
							}
							
						break;
						
						case 1://waiting min speed
							frist_ice_f=0;
							if(read_speed_rpm < ICE_SPEED_MIN)
							{
								ice_recog_cnt++;
								if(((ice_step_recorde_time+ice_step_recorde_time1+ice_step_recorde_time2)/3) > OUT_ICE_TIME)
								{
									if((ice_recog_cnt > 7)&&(ice_recog_cnt1 > 5))
									{
										ice_recog_cnt=0;
										switch_on_f=0;			//关机
										time_over_f=1;			//需复位到0ff位置才可重新开机避免连锁恢复后直接开机动作
										ice_step_time=0;
										ice_step_recorde_time1=0;
										ice_step_recorde_time2=0;
									}
									else
									{
										ice_recog_cnt1=1;
									}
								}
								ice_step_recorde_time2=ice_step_recorde_time1;
								ice_step_recorde_time1=ice_step_recorde_time;
								ice_step_time=0;
								power_set=0;
								ice_step=2;
								
							}
						break;
						
						case 2:
							power_set=0;
							if(ice_step_time > DELAY_ICE_TIME)
							{
								ice_step=0;
								ice_step_time=0;
								ice_step_cnt=0;
							}					
						break;				
					}
					
				}
		}
	else if (work_mode==WORK_SPEED1) //调速1
		{	
			if(switch_on_f)
			{
				if (working_f==0) 
				{
					working_f=1;				//置工作标志位
					timer_set=TIME_SPEED_CONTROL_MODE;//赋工作时长置与计时工作寄存器
					job_timer_cnt=0;				//计时清0
					soft_run_f=1;
					en_relay_f=1;
				}	
				else 
				{
					soft_run_f=1;
					set_rpm_buffer=SPEED1_RPM_SET;					
				}			
			}

		}
	else if (work_mode==WORK_SPEED2) //调速2
		{	
			if(switch_on_f)
			{
				if (working_f==0) 
				{
					working_f=1;				//置工作标志位
					timer_set=TIME_SPEED_CONTROL_MODE;//赋工作时长置与计时工作寄存器
					job_timer_cnt=0;				//计时清0
					ice_step=0;						//从0开始工作
					soft_run_f=1;
					en_relay_f=1;
				}	
				else 
				{
					soft_run_f=1;
					set_rpm_buffer=SPEED2_RPM_SET;
					//en_relay_f=1;
				}
			}
		}

}

