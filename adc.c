/*---------------------------------------------------------------------------------------
	Model		: adc.c
	Description	: ADC Head file
	Author		: harry
	Create Time	: 2019.1.3
	Version ID  : V1
	Mcu			: EM88F715N 20PIN
---------------------------------------------------------------------------------------*/
#include "adc.h"

/**********************
delay 10us 
***********************/
void DELAY_10US()
{
   u8 i;
   for(i=0;i<6;i++)
   {
       NOP();
       NOP();
   }
}

/*-----------------------------------------------------------------
---函 数 名：-Get_AdcAverage
---功    能：-
---参    数：-ch ADC channel
---返 回 值：- adc value
---调    用：- ADC_Read()
---前提条件：-
---说    明：- Get_AdcAverage

-----------------------------------------------------------------*/

u8 Get_AdcAverage(u8 ch,u8 times)
{
	u16 temp_val=0;
	u8 t;
	for(t=0;t<times;t++)
		{
			temp_val+=ADC_Read(ch);
		}
	t=temp_val/times;
	return t;
} 

/*-----------------------------------------------------------------
---函 数 名：-ADC_Read
---功    能：-Read adc convert value
---参    数：-channel 通道
---返 回 值：-返回AD转换至 8bit 0-256 丢掉低4位
---调    用：-无
---前提条件：-
---说    明：- 

-----------------------------------------------------------------*/

u8 ADC_Read(u8 channel)
{
	u8 value,i=10;
	switch (channel)//选通道---模拟开关
		{
			case 0:	break;
			case 1:	break;
			case 2:	break;	
			case 3:	break;	
			case 4:	break;	
			case 5:				
#ifdef _ANT5	
			ADISR=5;		//选择AD输入通道Ch5
#endif
			break;	
			case 6:	
#ifdef _ANT6		
			ADISR=6;		//选择AD输入通道Ch6
#endif	
			break;			
			case 7:	
#ifdef _ANT7		
			ADISR=7;		//选择AD输入通道Ch6
#endif	
			break;				
			case 8:	break;											
		}
	ADP=1;          //打开AD电源	
	DELAY_10US();		//采用延时
	
	ADRUN=1;
	while(ADRUN&&(i--))
		{
			DELAY_10US();
		}
	
	value=ADDL>>4;
	value+=ADDH<<4;
	ADP=0;          //关掉AD电源
	if (i == 0) 
		{
			return 0;				
		}
	else 
		{
			return value;	
		}		
}
/*-----------------------------------------------------------------
---函 数 名：-ADC_Init
---功    能：-
---参    数：- 
---返 回 值：-
---调    用：-
---前提条件：-
---说    明：-低功耗改写ADC电源开关

-----------------------------------------------------------------*/

void ADC_Init(void)
{
	
	ADCR1=0x09;     //ckr2~0=000=Fm/16	
	ADCR2=0;        //选择内部参考电压VDD
	
//---------------选定模拟I/O口------------------------------------------------------------	
#ifdef _ANT5	
	P6CR=0X01;		//P62设为输入		
	ADISR=5;		//选择AD输入通道Ch5
	ADE5=1;		//使能P54设为AD输入口
#endif

#ifdef _ANT6	
	P6CR=0X10;		//P64设为输入		
	ADISR=6;		//选择AD输入通道Ch5
	ADE6=1;		//使能P54设为AD输入口
#endif


}