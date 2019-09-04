/*---------------------------------------------------------------------------------------
	Model		: adc.c
	Description	: ADC Head file
	Author		: harry
	Create Time	: 2019.1.3
	Version ID  : V1
	Mcu			: EM88F715N 20PIN
---------------------------------------------------------------------------------------*/
#include "app.h"

	u8 pid_dataup;	//PID���ݸ������� pid_dataup*8ms
  signed   short en=0;		// ��ǰ���
  signed   short en1=0;		// �ϴ����
  signed   short en2=0;		// ���ϴ����
  signed   short now_out=0;	//��ǰPID���
  signed   short pre_out;	//��һ��PID���	
  float kp;	//����ϵ��	
  float ki;	//����ϵ��
  float kd;	//΢��ϵ��
		
	u16  speed_cntbuffer;   
	u16  read_speed_rpm;
	u16  set_rpm;
	u16  set_rpm_buffer;	
	
	u8  speed_cnt_l;
	u8  speed_cnt_h;	
	u8  speed_buffer_cnt_l;
	u8  speed_buffer_cnt_h;

//-----------------Zero cross ���㴥��----------------------------------------------------
 	u16 power_set=0;						//1-200 (0��200)���⴦��
 	u8 power_l=0;						//1-200 (0��200)���⴦��
 	u8 power_h=0;						//1-200 (0��200)���⴦��
 	u8 trigger_delay_h;					//��ʱ������λ����
 	u8 trigger_delay_l;					//��ʱ������λ����
 	u8  zc_counter;						//������� the counter of zero cross
 	bit en_zc_count_f;								//����������λ the flag of counter of zero cross
 	bit fre_check_ok_f;								//��Ƶ���OKλ��1���ɹ���0λ���ʧ��
 	bit is_50hz_f;									//Ƶ�ʱ�־λ1Ϊ50Hz 0Ϊ60Hz
 	bit frist_zc_f;									//��һ�ι����־��0��һ�Σ�1λ������
 	bit en_fire_f;									//���������ر�־λ

//-----------------�����Ĵ���-----------------------------------------------------------------
 	_WorkType work_mode;	      	//����ģʽ1
 	_WorkType old_work_mode;	    //����ģʽ
 	bit switch_on_f;							//���ر�־
 	bit working_f;								//���ر�־
 	bit en_relay_f;								//���ر�־
 	bit  soft_run_f;	
	bit process_10ms_f;	//8ms������  the sign of process task
	
	
//-----------------action------------------------------------------------------------
 	u8 work_step_cout;					//������CNT
	u8 protect_cnt; 
 	u8 work_cout;								//����CNT
 	u8 job_timer_cnt;						//���ڹ�����ʱ
 	u8 job_cnt;									//���������ָ���ֱ�ӿ��������õ��ڼ�����
 	u8 timer_set;								//��ʱֵ����	
 	u8 second_cout;							//��ʱ����� the count of second
 	u8 count_10ms;								//��ʱ8ms���� the count of 8ms
 	 	
 	u8 ice_step;   							//������е��ڼ��� crushed ice step
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
 	 	
 	u8 interlock_cnt=0;					//��������	the count of interlock
 	bit interlock_f;								//������־  the sign of interlock	
 	bit time_over_f=0;								//��ʱʱ�䵽
 	u8 	 temp_8;						//����ֵ	
 	u16  temp1_16;  						//��ʱֵ			
	
	u8 	 off_cnt;						//	
	
	extern void delay_20us(void);
	extern void delay_1ms(u8 n);	


/*-------------------------------------------------------
---�� �� ����-Pid_Init
---��    �ܣ�-pid
---��    ����-
---�� �� ֵ��-
---��    �ã�-
---ǰ��������-
---˵    ����-
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
---�� �� ����-Pid_Process
---��    �ܣ�-pid������
---��    ����-void 
---�� �� ֵ��-0-1000 ����ֵ
---��    �ã�-
---ǰ��������-
---˵    ����-set_rpm---�趨Ŀ���ٶ�
			 -read_speed_rpm---��ȡ�ٶ�
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
			Task_8ms();			//����ֵ����Ƶת��TCCB��ʱ��ֵ						
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
// �������ƣ�time_prosess(void)
// �������ܣ�
// ��ں�������ȫ�ֱ���
// ���ں�����ȫ�ֱ���
//----------------------------------------------------------------------------------------	

void Task_8ms(void)  	  
{		
//----------�����ٶ�----------------------------------------------
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
//-----------------����ֵת��Ϊ������ʱ��ֵ-----------------------------------------------
	temp1_16=power_set;
	
	
	if(power_set>700)
	temp1_16=temp1_16;
	
	
	if (power_set>1000) 
		{
			temp1_16=0;
		}
	power_l=temp1_16;		//Ĭ�ϵ�8λ��ֵ��trigger_delay_l
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
			trigger_delay_l=temp1_16;		//Ĭ�ϵ�8λ��ֵ��trigger_delay_l
			trigger_delay_h=temp1_16>>8;				
	}	

	
//-----------------1-3��������������------------------------------------------------------	
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
//-------------------------PID����--------------------------------------------------------	    
	if(set_rpm!=0)
		{
			pid_dataup++;
			if (pid_dataup>=PID_DATAUPTIME) //����PID����Ҫʱ��������
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
					if (pid_dataup>=PID_DATAUPTIME) //����PID����Ҫʱ��������
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
// �������ƣ�time_prosess(void)
// �������ܣ�
// ��ں�������ȫ�ֱ���
// ���ں�����ȫ�ֱ���
//----------------------------------------------------------------------------------------	

void Time_prosess(void)
{				
	if (second_cout>=125) //���ʱ��8ms*125=1s
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
// �������ƣ�Scan_Key(void)
// �������ܣ�
// ��ں�����
// ���ں�����
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
// �������ƣ�
// �������ܣ�
// ��ں�����
// ���ں�����
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
					
	if (key_value==KEY_ICE) 			//���ģʽ
			{
				if ((!time_over_f)&&(work_mode!=WORK_LOSTLOCK)&&(work_mode!=WORK_PROTECT))
					{
						work_mode=WORK_IEC;	
						switch_on_f=1;									
					}											
			}
	else if (key_value==KEY_NULL)	//����ģʽ
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
	else if (key_value==KEY_SPEED1) //�����ٶ�1ģʽ
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
	else if (key_value==KEY_SPEED2)//�����ٶ�2ģʽ
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
// �������ƣ�work_mode_control(void)
// �������ܣ�
// ��ں�����
// ���ں�����
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
// �������ƣ�work_mode_control(void)
// �������ܣ�
// ��ں�����
// ���ں�����
//----------------------------------------------------------------------------------------
	
void Control_task(void)
{
	
//----------------------��ʱ����----------------------------------------------------------
	if (working_f) 
		{
			if (job_timer_cnt>=timer_set) 	//���ʱ�䵽��ͣ��
				{
					job_timer_cnt=0;
					time_over_f=1;
					switch_on_f=0;					
				}	
		}	
		
//-------------ʧȥ��������---------------------------------------------------------------
	if ((interlock_f==0)&&working_f&&(job_cnt>=1)) //40ms ʧȥ���������ͣ��
		{
			//	switch_on_f=0;			//�ػ�
			//	time_over_f=1;			//�踴λ��0ffλ�òſ����¿������������ָ���ֱ�ӿ�������
		}	
	if (working_f) //40ms ʧȥ���������ͣ��
		{
			if(hall_b_p||hall_a_p)
			{				
				switch_on_f=0;			//�ػ�
				time_over_f=1;			//�踴λ��0ffλ�òſ����¿������������ָ���ֱ�ӿ�������
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
			
			job_timer_cnt=0;				//��ʱ��0
			ice_step=0;						//��0��ʼ����
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
	else if (work_mode==WORK_IEC) //���
		{		
			if (working_f==0) 
				{
					working_f=1;				//�ù�����־λ
					timer_set=TIME_SPEED_CONTROL_MODE;//������ʱ�������ʱ�����Ĵ���
					job_timer_cnt=0;				//��ʱ��0
					ice_step=0;						//��0��ʼ����
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
										switch_on_f=0;			//�ػ�
										time_over_f=1;			//�踴λ��0ffλ�òſ����¿������������ָ���ֱ�ӿ�������
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
	else if (work_mode==WORK_SPEED1) //����1
		{	
			if(switch_on_f)
			{
				if (working_f==0) 
				{
					working_f=1;				//�ù�����־λ
					timer_set=TIME_SPEED_CONTROL_MODE;//������ʱ�������ʱ�����Ĵ���
					job_timer_cnt=0;				//��ʱ��0
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
	else if (work_mode==WORK_SPEED2) //����2
		{	
			if(switch_on_f)
			{
				if (working_f==0) 
				{
					working_f=1;				//�ù�����־λ
					timer_set=TIME_SPEED_CONTROL_MODE;//������ʱ�������ʱ�����Ĵ���
					job_timer_cnt=0;				//��ʱ��0
					ice_step=0;						//��0��ʼ����
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

