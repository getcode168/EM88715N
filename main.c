#include "interrupt_vector.h"
#include "EM88F715N.H"
#include "type.h"
#include "global.h"
#include "app.h"


	extern void delay_20us(void);
	extern void delay_1ms(u8 n);	
	void System_Init(void);


void main(void)
{
	
boot:	
	System_Init();		//������ʼ��
	
    while(1)
		{
			WDTC();	
//----------------------speed cal				  	  
			Time_prosess();
			Prosess_10ms();
			Scan_task();		// ɨ������ں���ģʽ	
			Prosess_10ms();
			Time_prosess();
			Control_task();	// ������ģʽ�½��еĲ���	
			Prosess_10ms();	
			Time_prosess();	
			Prosess_10ms();
											
		}				
goto boot;//PC���������ظ�λ

}

void System_Init(void)
{
	WDTC();
	DISI();
//-----------------�趨I/O----------------------------------------------------------------		

	P6CR|=0xcb;			//P61/60/63/65/67Ϊ����   			����ͳ�
	P6PHCR&=0x34;		//P61/63/60/65/67����     			��ʹ������
	P6PLCR|=0xcb;		//��ֹP61/60/63/67/65		  			��ʹ������
	P6ODCR&=0x34;		//��ֹp60/6163//65/67���缫��·	��ʹ�ܿ�©
	
  P6CR&=0xfb;			//P6262
  P6PHCR&=0xfb;		//P55/56/57����
  P6ODCR|=0x04;		//��ֹ�缫��·
  P6PLCR|=0x04;		//��ֹ����    
  
	P5CR&=0x1f;			//P55/56/57Ϊ���
	P5PHCR&=0x1f;		//P55/56/57����
	P5PLCR|=0xe0;		//��ֹP55/56/57����
	P5ODCR&=0x1f;		//��ֹP55/56/57���缫��·
		
	en_relay_f=0;
		
//-----------------TCC 50us---------------------------------------------------------------	
	TCCCR=0X4c;			//Fm(��ʱ�� ) �ڲ�������ʱ�� ʹ��TCCԤ��Ƶ��1:8		
	TCCD=6;					//TCC����жϺ���Ҫ���¸���ֵ						//TCC=1/8MHz*8*(256-206)*1=50us
	TCIE=1;	 				//ʹ��TCC�ж�	
		
//-----------------TCC3 500us-------------------------------------------------------------	
	TC3CR1=0x00;		//Timer3ѡ����Ƶ 
	TC3CR2=0x15;		//ʹ��TC3��ʱ������,ѡ���ڲ�ʱ��ԴFc/2^4
	TC3DA=25;				//TC3����ֵΪ250��,��ʱʱ��(250*2^4/8M)=500uS
	TC3IE=1;
	TC3S=1; 				//Timer3 ��ʱ��ʼ	
	 
//-----------------TCC1 Triac timer-------------------------------------------------------	
	TC1CR1=0x56;		//Timer1 16bits ����ģʽ
	TC1CR2=0x33;		//ʹ��TC1��������,ѡ���ڲ�ʱ��ԴFc/2^6  20000=10ms ���¼���
	
//-----------------INT0  zc���ڹ����ж�-------------------------------------------
	P5CR|=0x10;			//P54 Input
	P5PHCR&=0xef;		//P54����
	P5PLCR|=0x10;		//��ֹP54����
	P5ODCR&=0xef;		//��ֹ���缫��·
	EI0ES1=1;
	EI0ES0=0;				//˫�����ж�
	EXIE0=1;
					
//-----------------PORT8 Speed���ڹ����ж�---------------------------------------------
	P8CR|=0x01;				//P80Ϊ����
	P78PHCR|=0x08;		//��ֹP80����
	P78PLCR|=0x08;		//��ֹP80����
	P78ODCR&=0xFE;		//��ֹ���缫��·	
	P8ICIE=1;					//ʹ���ж�
	ICWKP8=0;					//��ֹ�жϻ���
	P80=P80;					//Ϊ�´��ж�׼��
				
	WDTCR|=0x1D;			// 1/64		
//-----------------��ʼ����---------------------------------------------------------------		
	pwr_p=1;		
	time_over_f=1;	
	interlock_f=0;			//����
	en_fire_f=0;				//��������
	switch_on_f=0;			//���ر�־
	frist_zc_f=0;				//��һ�ι����־
	working_f=0;//�����Ѿ���������		
	fre_check_ok_f=0;		//��Ƶ�Ѿ����OK
	is_50hz_f=0;				//50Hz��Ƶ��־��=0��Ϊ60Hz
	process_10ms_f=0;		//8ms�����־
	
	
	if(!(speed1_p&&speed2_p&&iec_p))
	{
			delay_20us();
			delay_20us();
			delay_20us();//
			if(!(speed1_p&&speed2_p&&iec_p))
				{
					work_mode=WORK_READY;			
					if(!speed1_p)
						{
							old_work_mode=WORK_SPEED1;
						}
					else
						{
							old_work_mode=WORK_SPEED2;
						}
				}
			else
			{		
				work_mode=WORK_OFF;						
			}
	}
	else
	{
			delay_20us();
			delay_20us();
			delay_20us();//
			if(speed1_p&&speed2_p&&iec_p)
				work_mode=WORK_OFF;
	}

	en_zc_count_f=0;		//��������������ʱ������ʶ��50/60Hz
	
//-----------------Clean all flag---------------------------------------------------------
	SFR1=0;	
	SFR2=0;	
	SFR3=0;	
	SFR4=0;	
	SFR5=0;	
	SFR6=0;			
	Pid_Init();					
	ENI();					//�����ж�	
	
}

