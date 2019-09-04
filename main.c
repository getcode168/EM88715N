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
	System_Init();		//开机初始化
	
    while(1)
		{
			WDTC();	
//----------------------speed cal				  	  
			Time_prosess();
			Prosess_10ms();
			Scan_task();		// 扫描出处于何种模式	
			Prosess_10ms();
			Time_prosess();
			Control_task();	// 在所在模式下进行的操作	
			Prosess_10ms();	
			Time_prosess();	
			Prosess_10ms();
											
		}				
goto boot;//PC超出，返回复位

}

void System_Init(void)
{
	WDTC();
	DISI();
//-----------------设定I/O----------------------------------------------------------------		

	P6CR|=0xcb;			//P61/60/63/65/67为输入   			高入低出
	P6PHCR&=0x34;		//P61/63/60/65/67上拉     			低使能上拉
	P6PLCR|=0xcb;		//禁止P61/60/63/67/65		  			低使能下拉
	P6ODCR&=0x34;		//禁止p60/6163//65/67集电极开路	高使能开漏
	
  P6CR&=0xfb;			//P6262
  P6PHCR&=0xfb;		//P55/56/57上拉
  P6ODCR|=0x04;		//禁止电极开路
  P6PLCR|=0x04;		//禁止下拉    
  
	P5CR&=0x1f;			//P55/56/57为输出
	P5PHCR&=0x1f;		//P55/56/57上拉
	P5PLCR|=0xe0;		//禁止P55/56/57下拉
	P5ODCR&=0x1f;		//禁止P55/56/57集电极开路
		
	en_relay_f=0;
		
//-----------------TCC 50us---------------------------------------------------------------	
	TCCCR=0X4c;			//Fm(主时钟 ) 内部振荡周期时钟 使能TCC预分频比1:8		
	TCCD=6;					//TCC溢出中断后需要重新赋初值						//TCC=1/8MHz*8*(256-206)*1=50us
	TCIE=1;	 				//使能TCC中断	
		
//-----------------TCC3 500us-------------------------------------------------------------	
	TC3CR1=0x00;		//Timer3选择主频 
	TC3CR2=0x15;		//使能TC3定时器功能,选择内部时钟源Fc/2^4
	TC3DA=25;				//TC3计数值为250下,定时时间(250*2^4/8M)=500uS
	TC3IE=1;
	TC3S=1; 				//Timer3 定时开始	
	 
//-----------------TCC1 Triac timer-------------------------------------------------------	
	TC1CR1=0x56;		//Timer1 16bits 单次模式
	TC1CR2=0x33;		//使能TC1计数功能,选择内部时钟源Fc/2^6  20000=10ms 向下计数
	
//-----------------INT0  zc用于过零中断-------------------------------------------
	P5CR|=0x10;			//P54 Input
	P5PHCR&=0xef;		//P54上拉
	P5PLCR|=0x10;		//禁止P54下拉
	P5ODCR&=0xef;		//禁止集电极开路
	EI0ES1=1;
	EI0ES0=0;				//双边沿中断
	EXIE0=1;
					
//-----------------PORT8 Speed用于过零中断---------------------------------------------
	P8CR|=0x01;				//P80为输入
	P78PHCR|=0x08;		//禁止P80上拉
	P78PLCR|=0x08;		//禁止P80下拉
	P78ODCR&=0xFE;		//禁止集电极开路	
	P8ICIE=1;					//使能中断
	ICWKP8=0;					//禁止中断唤醒
	P80=P80;					//为下次中断准备
				
	WDTCR|=0x1D;			// 1/64		
//-----------------初始变量---------------------------------------------------------------		
	pwr_p=1;		
	time_over_f=1;	
	interlock_f=0;			//连锁
	en_fire_f=0;				//触发开关
	switch_on_f=0;			//开关标志
	frist_zc_f=0;				//第一次过零标志
	working_f=0;//调速已经在运行了		
	fre_check_ok_f=0;		//工频已经检测OK
	is_50hz_f=0;				//50Hz工频标志，=0是为60Hz
	process_10ms_f=0;		//8ms处理标志
	
	
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

	en_zc_count_f=0;		//允许过零计数（计时）用于识别50/60Hz
	
//-----------------Clean all flag---------------------------------------------------------
	SFR1=0;	
	SFR2=0;	
	SFR3=0;	
	SFR4=0;	
	SFR5=0;	
	SFR6=0;			
	Pid_Init();					
	ENI();					//开总中断	
	
}

