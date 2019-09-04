#ifndef __INTERRUPT_VECTOR_H__
	#define __INTERRUPT_VECTOR_H__

	#include "EM88F715N.H"
	#include "type.h"
	#include "global.h"
	#include "app.h"
	
	
	u8 trigger_cnt;
	u8 switch_cnt;
	
	
	u8 turn_cnt=0;
	
	
	
	
void delay_20us(void);
void delay_1ms(u8 n);	
//------------------------------------------------------------------------------------
//�������ƣ�delay_us  20us
//�������ܣ�A��ʱ
//��ں�����k
//���ں�����void
//------------------------------------------------------------------------------------
void delay_20us(void)
{
 u8 i;
 for(i=0;i<16;i++)
   {
       NOP();
       NOP();
   }
}

//------------------------------------------------------------------------------------
//�������ƣ�delay_us  20uss
//�������ܣ�A��ʱ
//��ں�����k
//���ں�����void
//------------------------------------------------------------------------------------

void delay_10us(void)
{
 u8 i;
 for(i=0;i<10;i++)
   {
       NOP();
       NOP();
   }
}
//------------------------------------------------------------------------------------
//�������ƣ�delay_1ms 
//�������ܣ�A��ʱ
//��ں�����k
//���ں�����void
//------------------------------------------------------------------------------------	
void delay_1ms(u8 n)
{
	u8 i=50;
	while(n--)
		{
			while (i--) 
				{
					 delay_20us();
				}			
		}
	
}
//-- You can remove marks, if you want using any interrupt funcitons.-----------------	


extern int IntVecIdx; //occupied 0x10:rpage 0

void _intcall Allint(void) @ int 
{
  switch(IntVecIdx)
  {
	case 0x3:
		
	if (EXSF0) //INT0  Zero Cross
		{
			EXSF0=0;
				
			
//---------------------�����������״̬-------------------------------------------------
  	interlock_f=1;			//������־λ
  	interlock_cnt=0;		//����������0
  	
//----------------------------------------------------------------------------------------  	
  	if(switch_on_f)
  		{
  			en_relay_f=1;
  			if (switch_cnt<15) 
	  			{
	  				switch_cnt++;
	  			}
  			else 
	  			{
	  				en_fire_f=1;
	  			}
  		}
  	else 
  		{
  			en_fire_f=0;
  			if (switch_cnt>5) 
	  			{
	  				switch_cnt--;
	  			}
  			else 
	  			{
	  				en_relay_f=0;
	  			}
  		}
  	
//---------------------ʶ��50/60Hz--------------------------------------------------------  	
  	if (fre_check_ok_f) 	//���Ƶ�ʼ�ⲻok������Ƶ��
	    {
//---------------------power_set��0/200ֵ���⴦��---------------------------------------	
			if (en_fire_f) 	//��������
				{
					if((power_h==0)&&(power_l==0)) 
						{
							trigger_out_p=0;
						}										
					else if((power_l >50)||(power_h > 0)) 	//��>88��ʱ����
						{						
							TC1DA=trigger_delay_l;		//���ֽ�
							TC2DA=trigger_delay_h;			//���ֽ�
							TC1S=1; 			//Timer1 ��ʱ��ʼ					
							TC1IE=1;									
						}	
					else 
						{
							trigger_out_p=0;
						}	
    		}
    	else 
    		{
    			trigger_out_p=0;  			
    		}
    	}
  	else 							//(Ƶ��ʶ��OK )
    	{
    		if (frist_zc_f==0)		//��һ�ο�ʼ���� 
	    		{
	    			frist_zc_f=1;	//�õ�һ�ι����־λ
						en_zc_count_f=1;//��ʼ����
						zc_counter=0;	//���㼱������
	    		}
	    	else 					//�ڶ���ZCʶ��50/60Hz
	    		{
	    			en_zc_count_f=0; //ֹͣ����   		
			    	 if ((zc_counter > 146)&&(zc_counter < 206))//ERROR  50Hz=100US*100 60Hz 83*100us
			    		{
				    		 if (zc_counter > 182) //91=(100+83)/2
					    		{
					    			is_50hz_f=1;//50Hz
					    		}
				    		 else 
					    		{
					    			is_50hz_f=0;//60Hz
					    		}
					    	frist_zc_f=0;		//��������������־				    		
					    	fre_check_ok_f=1;	//��Ƶ���OK		    	
			    		}
		    		else 						//ʶ��������²��Թ�Ƶ reset register and repeat test
			    		{
			    			fre_check_ok_f=0;	//��Ƶ������
			    			frist_zc_f=0;		//��һ�ι��㸴λ���Ա���һ�μ������
			    			en_zc_count_f=0;	//ֹͣ�������	
			    		}				    	
	    		}	    		
			}	
			
		}			

	break;
	
	case 0x5:// SPEED 
	
	if(P8ICSF)
		{
			P8ICSF=0;
			P80=P80;
			protect_cnt=0;
			
			turn_cnt++;
			//1�������һ���ٶ� һȦ1������	
			if(turn_cnt>=2)
			{
				turn_cnt=0;
				speed_buffer_cnt_l=speed_cnt_l;
			  speed_buffer_cnt_h=speed_cnt_h;	
				speed_cnt_l=0;
				speed_cnt_h=0;			
				PORT6^=0X04;
			}

			
		}

	break;
	
	case 0x7://TCC 500us
  TCCD=6;			//��TCC����ֵ
  TCSF=0;

//---------------------10ms��ʱ����*-------------------------------------------------------
  count_10ms++;
  ice_step_cnt++;
//---------------------lcd task process---------------------------------------------------    	

  if (count_10ms >= 20) //500us*20=10ms
    {	
    	    	  
    	count_10ms=0;
    	process_10ms_f=1;	//��10ms����
    	work_step_cout++;	
    	second_cout++;
//---------------------internallock-------------------------------------------------------
		if((working_f)&&(job_timer_cnt>=1))			//��������			    
	    	{
	    		interlock_cnt++;
	    	}			    			    	
    	if (interlock_cnt>=20) //ʧȥ��������ﵽһ��ֵ����Ϊ����װ�öϿ�
	    	{
	    		interlock_f=0;
	    		interlock_cnt=0;
	    	}		    		
	  } 
	    
//----------------------------------------------------------------------------------------	  
	if (en_relay_f) 
	{
		PORT5^=0X40;	//P56
	}
	else 
	{
		cs_relay_p=0;
	}
	 	 	 	 
	break;

	//case 0x9:
	//break;

	//case 0xB:
	//break;

	//case 0xD:
	//break;
	
	//case 0x11:
	//break;

	case 0x13://frie 
	
	TC1DASF=0;  //���жϱ�־λ TC1SF=0;	
	
	TC1S=0; 			//��Timer1					
	TC1IE=0;	
	
	if (((power_h==2)&&(power_l>208))||(power_h>2)) //720
		{	
			trigger_cnt=1;
		}
	else 
		{
			trigger_cnt=1;
		}
	//trigger_out_p=1;
	//delay_20us();
	
	//trigger_out_p=0;
	//trigger_cnt=1;
	
	break;

	//case 0x15:
	//break;
	
	//case 0x17:
	//break;	

	//case 0x1B:
	//break;
		
	//case 0x1D:
	//break;
	
	//case 0x1F:
	//break;
				
//	case 0x23:

	//break;

	//case 0x25:
	//break;

	//case 0x27:
	//break;
	
	case 0x29://TCC3 50us
		
	TC3DASF=0;//���жϱ�־λ TC3SF=0;
	    	
//--------------------���㹤Ƶ����������--------------------------------------		
 	if(en_zc_count_f)			//50Hz 20ms/2=10ms/50us=200
	 {										//60Hz 16.7ms/2=8.3ms/50us=166	 		  
	 		zc_counter++;
 	 }
 	 
	//--------------------------speed_cnt�ٶȼ���-----------------------------------
	if (speed_cnt_h<20) //20*256+255=5375
	{
		if (speed_cnt_l==255) 
			{
					speed_cnt_h++;			
			}
		speed_cnt_l++;			
	}

	if ((speed_cnt_h>=7))//>3072
		{
			speed_buffer_cnt_l=2;
			speed_buffer_cnt_h=0;
		}
//--------------------------��������--------------------------------------------	        
	if (trigger_cnt==1) 
		{
			trigger_out_p=1;    //����
			//delay_10us();
			//trigger_out_p=0;    //
		}
	else if(trigger_cnt==3)
		{
			trigger_out_p=1;    //����
			//delay_10us();
		//	trigger_out_p=0;    //
		}	
	else 
		{
      trigger_out_p=0;    //
		}
	
	if (trigger_cnt>0) 
		{
			trigger_cnt--;
		}			
			
	break;

	//case 0x2B:
	//break;
	
	//case 0x2D:
	//break;
	
	//case 0x2F:
	//break;
	
	//case 0x31:
	//break;   
	
	//case 0x33:
	//break;

	//case 0x3B:
	//break;  
	
  }
}


void _intcall INT_interrupt_l(void) @ 0x02:low_int 0
{
 _asm{MOV A,0x2};
}

void _intcall pinchange_l(void) @ 0x04:low_int 1
{
 _asm{MOV A,0x2};	
}

void _intcall tcc_interrupt_l(void) @ 0x06:low_int 2
{
 _asm{MOV A,0x2};	
}

/*void _intcall LVD_interrupt_l(void) @ 0x08:low_int 3
{
 _asm{MOV A,0x2};	
}*/
/*
void _intcall Comparator1_interrupt_l(void) @ 0x0A:low_int 4
{
 _asm{MOV A,0x2};	
}
*/
/*void _intcall SPI_interrupt_l(void) @ 0x0C:low_int 5
{
 _asm{MOV A,0x2};	
}*/

/*void _intcall AD_interrupt_l(void) @ 0x10:low_int 6
{
 _asm{MOV A,0x2};
}*/

void _intcall TC1_interrupt_l(void) @ 0x12:low_int 7
{
 _asm{MOV A,0x2};
}

/*void _intcall PWMPA_interrupt_l(void) @ 0x14:low_int 8
{
 _asm{MOV A,0x2};
}*/

/*void _intcall PWMDA_interrupt_l(void) @ 0x16:low_int 9
{
 _asm{MOV A,0x2};	
}*/

/*void _intcall I2CTX_interrupt_l(void) @ 0x1A:low_int 10
{
 _asm{MOV A,0x2};	
}*/

/*void _intcall I2CRX_interrupt_l(void) @ 0x1C:low_int 11
{
 _asm{MOV A,0x2};	
}*/

/*void _intcall I2CSTOP_interrupt_l(void) @ 0x1E:low_int 12
{
 _asm{MOV A,0x2};	
}*/
/*
void _intcall TC2_interrupt_l(void) @ 0x22:low_int 13
{
 _asm{MOV A,0x2};
}
*/
/*void _intcall PWMPB_interrupt_l(void) @ 0x24:low_int 14
{
 _asm{MOV A,0x2};	
}*/

/*void _intcall PWMDB_interrupt_l(void) @ 0x26:low_int 15
{
 _asm{MOV A,0x2};
}*/

void _intcall TC3_interrupt_l(void) @ 0x28:low_int 16
{
 _asm{MOV A,0x2};
}

/*void _intcall PWMPC_interrupt_l(void) @ 0x2A:low_int 17
{
 _asm{MOV A,0x2};	
}*/

/*void _intcall PWMDC_interrupt_l(void) @ 0x2C:low_int 18
{
 _asm{MOV A,0x2};
}*/

/*void _intcall UART_RX_ERR_interrupt_l(void) @ 0x2E:low_int 19
{
 _asm{MOV A,0x2};
}*/

/*void _intcall UART_RX_interrupt_l(void) @ 0x30:low_int 20
{
 _asm{MOV A,0x2};	
}*/

/*void _intcall UART_TX_interrupt_l(void) @ 0x32:low_int 21
{
 _asm{MOV A,0x2};	
}*/

/*void _intcall SYSHOLD_interrupt_l(void) @ 0x3A:low_int 22
{
 _asm{MOV A,0x2};	
}*/

#endif