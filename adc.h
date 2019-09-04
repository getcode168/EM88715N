
/***************************************************************************************
	Model		: adc.h
	Description	: Head file of adc
	Author		: harry
	Create Time	: 2019.01.03
	Version ID  : V1
	Mcu			: EM88F715N 20pin
****************************************************************************************/
#ifndef adc_h__
	#define adc_h__

	#include "EM88F715N.H"
	#include "type.h"	
	
//---------------¶¨ÒåÓ²¼þ---------------------------------------------------
//#define _ANT0
//#define _ANT1
//#define _ANT2
//#define _ANT3
//#define _ANT4
#define _ANT5
//#define _ANT6
//#define _ANT7
//#define _ANT8
//#define _ANT9

extern	void ADC_Init(void);//ADC initaties
extern  u8 ADC_Read(u8 channel);//get adc value
extern  u8 Get_AdcAverage(u8 ch,u8 times);	//get adc average value
	
#endif