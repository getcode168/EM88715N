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
---�� �� ����-Get_AdcAverage
---��    �ܣ�-
---��    ����-ch ADC channel
---�� �� ֵ��- adc value
---��    �ã�- ADC_Read()
---ǰ��������-
---˵    ����- Get_AdcAverage

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
---�� �� ����-ADC_Read
---��    �ܣ�-Read adc convert value
---��    ����-channel ͨ��
---�� �� ֵ��-����ADת���� 8bit 0-256 ������4λ
---��    �ã�-��
---ǰ��������-
---˵    ����- 

-----------------------------------------------------------------*/

u8 ADC_Read(u8 channel)
{
	u8 value,i=10;
	switch (channel)//ѡͨ��---ģ�⿪��
		{
			case 0:	break;
			case 1:	break;
			case 2:	break;	
			case 3:	break;	
			case 4:	break;	
			case 5:				
#ifdef _ANT5	
			ADISR=5;		//ѡ��AD����ͨ��Ch5
#endif
			break;	
			case 6:	
#ifdef _ANT6		
			ADISR=6;		//ѡ��AD����ͨ��Ch6
#endif	
			break;			
			case 7:	
#ifdef _ANT7		
			ADISR=7;		//ѡ��AD����ͨ��Ch6
#endif	
			break;				
			case 8:	break;											
		}
	ADP=1;          //��AD��Դ	
	DELAY_10US();		//������ʱ
	
	ADRUN=1;
	while(ADRUN&&(i--))
		{
			DELAY_10US();
		}
	
	value=ADDL>>4;
	value+=ADDH<<4;
	ADP=0;          //�ص�AD��Դ
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
---�� �� ����-ADC_Init
---��    �ܣ�-
---��    ����- 
---�� �� ֵ��-
---��    �ã�-
---ǰ��������-
---˵    ����-�͹��ĸ�дADC��Դ����

-----------------------------------------------------------------*/

void ADC_Init(void)
{
	
	ADCR1=0x09;     //ckr2~0=000=Fm/16	
	ADCR2=0;        //ѡ���ڲ��ο���ѹVDD
	
//---------------ѡ��ģ��I/O��------------------------------------------------------------	
#ifdef _ANT5	
	P6CR=0X01;		//P62��Ϊ����		
	ADISR=5;		//ѡ��AD����ͨ��Ch5
	ADE5=1;		//ʹ��P54��ΪAD�����
#endif

#ifdef _ANT6	
	P6CR=0X10;		//P64��Ϊ����		
	ADISR=6;		//ѡ��AD����ͨ��Ch5
	ADE6=1;		//ʹ��P54��ΪAD�����
#endif


}