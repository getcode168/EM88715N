#ifndef _EM88715N_H__
	#define _EM88715N_H__

/****************************************************************
 *      Header file for the Elan                                *
 *      Elan chip:   EM88F715N                                  *	
 *      Tilte:       EM88F715N include file                     * 
 *      Description: The Definition of EM88F715N Registers      *
 *      Company:     ELAN MICROELECTRONICS (SZ) LTD.            * 
 *      Date:        06/29/2017                                 *
 *      Version:     v1.0                                       *
 ****************************************************************/
/************** REGISTER BANK 0 *************/
static unsigned int R0         @0x00:rpage 0;//Indirect Address Register
static unsigned int IAR        @0x00:rpage 0;//Indirect Address Register
static unsigned int BSR        @0x01:rpage 0;//Bank Select Control Registal
static unsigned int R2         @0x02:rpage 0;//Program Counter
static unsigned int PC         @0x02:rpage 0;//Program Counter
static unsigned int PCL        @0x02:rpage 0;//Program Counter	
static unsigned int R3         @0x03:rpage 0;//Status Register
static unsigned int SR		     @0x03:rpage 0;//Status Register
static unsigned int STATUS     @0x03:rpage 0;//Status Register
static unsigned int R4         @0x04:rpage 0;//Ram Select Register
static unsigned int RSR        @0x04:rpage 0;//Ram Select Register
static unsigned int R5         @0x05:rpage 0;//Port 5 data Register
static unsigned int PORT5      @0x05:rpage 0;//Port 5 data Register
static unsigned int R6         @0x06:rpage 0;//Port 6 data Register
static unsigned int PORT6      @0x06:rpage 0;//Port 6 data Register
static unsigned int R7         @0x07:rpage 0;//Port 7 data Register
static unsigned int PORT7      @0x07:rpage 0;//Port 7 data Register
static unsigned int R8         @0x08:rpage 0;//Port 7 data Register
static unsigned int PORT8      @0x08:rpage 0;//Port 7 data Register  
static unsigned int IOCR5       @0x0B:rpage 0;//Port 5 control Register
static unsigned int P5CR       @0x0B:rpage 0;//Port 5 control Register
static unsigned int IOCR6       @0x0C:rpage 0;//Port 6 control Register
static unsigned int P6CR       @0x0C:rpage 0;//Port 6 control Register	
static unsigned int IOCR7       @0x0D:rpage 0;//Port 7 control Register
static unsigned int P7CR       @0x0D:rpage 0;//Port 7 control Register		
static unsigned int OMCR       @0x0E:rpage 0;//Operating Mode Control Register
static unsigned int EIESCR     @0x0F:rpage 0;//Extermal Interrupt Edge Select Control Register
//-----------------------------------------
static unsigned int WUCR1      @0x10:rpage 0;//Wake-up Control Register 1
static unsigned int WUCR2      @0x11:rpage 0;//Wake-up Control Register 2
static unsigned int WUCR3      @0x12:rpage 0;//Wake-up Control Register 3
static unsigned int SFR1       @0x14:rpage 0;//Status Flag Register1
static unsigned int SFR2       @0x15:rpage 0;//Status Flag Register2
static unsigned int SFR3       @0x16:rpage 0;//Status Flag Register3
static unsigned int SFR4       @0x17:rpage 0;//Status Flag Register4
static unsigned int SFR5       @0x18:rpage 0;//Status Flag Register5
static unsigned int SFR6       @0x19:rpage 0;//Status Flag Register6
static unsigned int IMR1       @0x1B:rpage 0;//Interrupt Mask Register1
static unsigned int IMR2       @0x1C:rpage 0;//Interrupt Mask Register2
static unsigned int IMR3       @0x1D:rpage 0;//Interrupt Mask Register3
static unsigned int IMR4       @0x1E:rpage 0;//Interrupt Mask Register4
static unsigned int IMR5       @0x1F:rpage 0;//Interrupt Mask Register5
static unsigned int IMR6       @0x20:rpage 0;//Interrupt Mask Register6
//-----------------------------------------
static unsigned int WDTCR      @0x21:rpage 0;//Watchdog Timer Control Register)
static unsigned int TCCCR      @0x22:rpage 0;//TCC Control Register
static unsigned int TCCD       @0x23:rpage 0;//TCC Data Register
static unsigned int TC1CR1     @0x24:rpage 0;//Timer/Counter 1 Control Register 1
static unsigned int TC1CR2     @0x25:rpage 0;//Timer/Counter 1 Control Register 2
static unsigned int TC1DA      @0x26:rpage 0;//Timer/Counter 1 Data Buffer A
static unsigned int TC1DB      @0x27:rpage 0;//Timer/Counter 1 Data Buffer B
static unsigned int TC2CR1     @0x28:rpage 0;//Timer/Counter 2 Control Register 1
static unsigned int TC2CR2     @0x29:rpage 0;//Timer/Counter 2 Control Register 2
static unsigned int TC2DA      @0x2A:rpage 0;//Timer/Counter 2 Data Buffer A
static unsigned int TC2DB      @0x2B:rpage 0;//Timer/Counter 2 Data Buffer B
static unsigned int TC3CR1     @0x2C:rpage 0;//Timer/Counter 3 Control Register 1
static unsigned int TC3CR2     @0x2D:rpage 0;//Timer/Counter 3 Control Register 2
static unsigned int TC3DA      @0x2E:rpage 0;//Timer/Counter 3 Data Buffer A
static unsigned int TC3DB      @0x2F:rpage 0;//Timer/Counter 3 Data Buffer B
//-----------------------------------------
static unsigned int I2CCR1     @0x30:rpage 0;//I2C Status and Control Register 1
static unsigned int I2CCR2     @0x31:rpage 0;//I2C Status and Control Register 2
static unsigned int I2CSA      @0x32:rpage 0;//I2C Slave Address Register)
static unsigned int I2CDB      @0x33:rpage 0;//I2C Data Buffer Register
static unsigned int I2CDAL     @0x34:rpage 0;//I2C Device Address Register
static unsigned int I2CDAH     @0x35:rpage 0;//I2C Device Address Register
static unsigned int SPICR      @0x36:rpage 0;//SPI Control Register
static unsigned int SPIS       @0x37:rpage 0;//SPI Status Register
static unsigned int SPIR       @0x38:rpage 0;//SPI Read Buffer Register
static unsigned int SPIW       @0x39:rpage 0;//SPI Write Buffer Register
static unsigned int CMPCR1     @0x3A:rpage 0;//Compartor control Register1
static unsigned int CMPCR2     @0x3B:rpage 0;//Compartor control Register2
static unsigned int CMPCR3     @0x3C:rpage 0;//Compartor control Register3			
static unsigned int ADCR1      @0x3E:rpage 0;//ADC Control Register 1
static unsigned int ADCR2      @0x3F:rpage 0;//ADC Control Register 2
//-----------------------------------------
static unsigned int ADISR      @0x40:rpage 0;//nalog to Digital Converter Input Channel Select Register
static unsigned int ADER1      @0x41:rpage 0;//Analog to Digital Converter Input Control Register 1
static unsigned int ADER2      @0x42:rpage 0;//Analog to Digital Converter Input Control Register 2
static unsigned int ADDL       @0x43:rpage 0;//Low Byte of Analog to Digital Converter Data
static unsigned int ADDH       @0x44:rpage 0;//High Byte of Analog to Digital Converter Data
static unsigned int ADCVL      @0x45:rpage 0;//Low Byte of Analog to Digital Converter Comparison
static unsigned int ADCVH      @0x46:rpage 0;//High Byte of Analog to Digital Converter Comparison

/********** REGISTER BANK 1 **************/
static unsigned int P8CR       @0x05:rpage 1;//PORT8 I/O Control Register
static unsigned int IOCR8      @0x05:rpage 1;//PORT8 I/O Control Register

static unsigned int P5PHCR     @0x08:rpage 1;//Port 5 Pull-high Control Register
static unsigned int P6PHCR     @0x09:rpage 1;//Port 6 Pull-high Control Register
static unsigned int P78PHCR    @0x0A:rpage 1;//Port 7~A Pull-high Control Register
static unsigned int P5PLCR     @0x0B:rpage 1;//Port 5 Pull-low Control Register
static unsigned int P6PLCR     @0x0C:rpage 1;//Port 6 Pull-low Control Register
static unsigned int P78PLCR    @0x0D:rpage 1;//Port 7~8 Pull-low Control Register
static unsigned int P5HDSCR    @0x0E:rpage 1;//Port 5 High Drive/Sink Control Register
static unsigned int P6HDSCR    @0x0F:rpage 1;//Port 6 High Drive/Sink Control Register)
//-----------------------------------------
static unsigned int P78HDSCR   @0x10:rpage 1;//Port 7~8 High Drive/Sink Control Register
static unsigned int P5ODCR     @0x11:rpage 1;//Port 5 Open-drain Control Register
static unsigned int P6ODCR     @0x12:rpage 1;//Port 6 Open-drain Control Register
static unsigned int P78ODCR    @0x13:rpage 1;//Port 7~A Open-drain Control Register)
static unsigned int DEADTCR    @0x14:rpage 1;//Dead time Control Register)	
static unsigned int DEADTR     @0x15:rpage 1;//Dead time  Register
static unsigned int PWMSCR     @0x16:rpage 1;//PWM Source Clock control register
static unsigned int PWMACR     @0x17:rpage 1;//PWM Control Register
static unsigned int PRDAL      @0x18:rpage 1;//LOW byte of pwma period
static unsigned int PRDAH      @0x19:rpage 1;//high byte of pwma period		
static unsigned int DTAL       @0x1A:rpage 1;//LOW byte of pwma duty
static unsigned int DTAH       @0x1B:rpage 1;//HIGH byte of pwma duty		
static unsigned int TMRAL      @0x1C:rpage 1;//LOW byte of TimerA
static unsigned int TMRAH      @0x1D:rpage 1;//High byte of TimerA	
static unsigned int PWMBCR     @0x1E:rpage 1;//PWMB Control¡¡Register
static unsigned int PRDBL      @0x1F:rpage 1;//LOW byte of pwmB period
static unsigned int PRDBH      @0x20:rpage 1;//high byte of pwmB period		
static unsigned int DTBL       @0x21:rpage 1;//LOW byte of pwmB duty
static unsigned int DTBH       @0x22:rpage 1;//HIGH byte of pwmB duty		
static unsigned int TMRBL      @0x23:rpage 1;//LOW byte of TimerB
static unsigned int TMRBH      @0x24:rpage 1;//High byte of TimerB	
static unsigned int PWMCCR     @0x25:rpage 1;//PWMB Control¡¡Register				
static unsigned int PRDCL      @0x26:rpage 1;//LOW byte of pwmC period
static unsigned int PRDCH      @0x27:rpage 1;//high byte of pwmC period	
static unsigned int DTCL       @0x28:rpage 1;//LOW byte of pwmC duty
static unsigned int DTCH       @0x29:rpage 1;//high byte of pwmC duty		
static unsigned int TMRCL      @0x2A:rpage 1;//LOW byte of Timerc
static unsigned int TMRCH      @0x2B:rpage 1;//HIGH byte of pwmC Timerc
//-----------------------------------------
static unsigned int URCR       @0x33:rpage 1;//UART Control Register
static unsigned int URS        @0x34:rpage 1;//UART Status Register
static unsigned int URTD       @0x35:rpage 1;//UART Transmit Data Buffer Register
static unsigned int URRDL      @0x36:rpage 1;//UART Receive Data Low Buffer Register
static unsigned int URRDH      @0x37:rpage 1;//UART Receive Data High Buffer Register
//-----------------------------------------

static unsigned int TBPTL      @0x45:rpage 1;//Table Pointer Low Register
static unsigned int TBPTH      @0x46:rpage 1;//Table Pointer High Register
static unsigned int STKMON     @0x47:rpage 1;//Stack Monitor
static unsigned int PCH        @0x48:rpage 1;//Program Counter High
static unsigned int HLVDCR     @0x49:rpage 1;//Low Voltage Detector Control Register


/*    R1 bits    */
static bit SBS0    @0x01@4:rpage 0;//Special Register Bank Select bit
static bit GBS0    @0x01@0:rpage 0;//General Register Bank Select bit0

/*	STATUS bits	*/
static	bit INT    @0X03@7:rpage 0;//Interrupt ensble¡¡enable
static	bit N      @0X03@6:rpage 0;//Negative flag
static	bit OV     @0X03@5:rpage 0;//Overflow¡¡flag
static	bit T      @0X03@4:rpage 0;//Time-out bit
static	bit P      @0X03@3:rpage 0;//Power down bit
static	bit Z      @0X03@2:rpage 0;//Zero flag
static	bit DC     @0X03@1:rpage 0;//Auxiliary carry flag 
static	bit C      @0X03@0:rpage 0;//Carry flag 

/*    PORT5 bits    */
static bit P57     @0x05@7:rpage 0;
static bit P56     @0x05@6:rpage 0;
static bit P55     @0x05@5:rpage 0;
static bit P54     @0x05@4:rpage 0;
static bit P53     @0x05@3:rpage 0;
static bit P52     @0x05@2:rpage 0;
static bit P51     @0x05@1:rpage 0;
static bit P50     @0x05@0:rpage 0;

/*    PORT6 bits    */
static bit P67     @0x06@7:rpage 0;
static bit P66     @0x06@6:rpage 0;
static bit P65     @0x06@5:rpage 0;
static bit P64     @0x06@4:rpage 0;
static bit P63     @0x06@3:rpage 0;
static bit P62     @0x06@2:rpage 0;
static bit P61     @0x06@1:rpage 0;
static bit P60     @0x06@0:rpage 0;

/*    PORT7 bits    */
static bit P77     @0x07@7:rpage 0;
static bit P76     @0x07@6:rpage 0;
static bit P75     @0x07@5:rpage 0;
static bit P74     @0x07@4:rpage 0;
static bit P73     @0x07@3:rpage 0;
static bit P72     @0x07@2:rpage 0;
static bit P71     @0x07@1:rpage 0;
static bit P70     @0x07@0:rpage 0;

/*    PORT8 bits    */
static bit P87     @0x08@7:rpage 0;
static bit P86     @0x08@6:rpage 0;
static bit P85     @0x08@5:rpage 0;
static bit P84     @0x08@4:rpage 0;
static bit P83     @0x08@3:rpage 0;
static bit P82     @0x08@2:rpage 0;
static bit P81     @0x08@1:rpage 0;
static bit P80     @0x08@0:rpage 0;


/*    OMCR bits    */
static bit CPUS    @0x0E@7:rpage 0;//CPU Oscillator Source Select
static bit IDLE    @0x0E@6:rpage 0;//Idle Mode Enable Bit
static bit PERCS   @0x0E@5:rpage 0;//pERIPHERY Clock source for green and idle mode
static bit IIPS    @0x0E@4:rpage 0;//IRC INTERRNAL power switch bit, used in mode change 
static bit FMSF    @0x0E@3:rpage 0;//FM stable flag bit
static bit RCM2    @0x0E@2:rpage 0;//Internal RC mode select bits
static bit RCM1    @0x0E@1:rpage 0;//Internal RC mode select bits
static bit RCM0    @0x0E@0:rpage 0;//Internal RC mode select bits

/*    EIESCR bits    */
static bit EI76ES  @0x0F@7:rpage 0;//external interrupt edge select bit 
static bit EI54ES  @0x0F@6:rpage 0;//external interrupt edge select bit 
static bit EI32ES1 @0x0F@5:rpage 0;//external interrupt edge select bit 
static bit EI32ES0 @0x0F@4:rpage 0;//external interrupt edge select bit 
static bit EI1ES1  @0x0F@3:rpage 0;//external interrupt edge select bit 
static bit EI1ES0  @0x0F@2:rpage 0;//external interrupt edge select bit 
static bit EI0ES1  @0x0F@1:rpage 0;//external interrupt edge select bit 
static bit EI0ES0  @0x0F@0:rpage 0;//external interrupt edge select bit
/*    WUCR1 bits    */
static bit CMPWK   @0x10@6:rpage 0;//comparator Wake-up Enable Bit
static bit HLVDWK  @0x10@5:rpage 0;//Low Voltage Detect Wake-up Enable Bit 
static bit ADWK    @0x10@4:rpage 0;//A/D Converter Wake-up Function Enable Bit 
static bit INTWK1  @0x10@3:rpage 0;//External Interrupt (INT pin) Wake-up Function Enable Bit
static bit INTWK0  @0x10@2:rpage 0;//External Interrupt (INT pin) Wake-up Function Enable Bit

/*    WUCR2 bits    */
static bit SPIWK   @0x11@3:rpage 0;//SPI wake-up enable bi
static bit I2CWK   @0x11@2:rpage 0;//I2C wake-up enable bit

/*    WUCR3 bits    */
static bit ICWKP8  @0x12@7:rpage 0;//Pin-change Wake-up Function Enable Bit 
static bit ICWKP7  @0x12@6:rpage 0;//Pin-change Wake-up Function Enable Bit 
static bit ICWKP6  @0x12@5:rpage 0;//Pin-change Wake-up Function Enable Bit 
static bit ICWKP5  @0x12@4:rpage 0;//Pin-change Wake-up Function Enable Bit 
static bit INTWK76 @0x12@2:rpage 0;//External Interrupt (INT pin) Wake-up Function Enable Bit 
static bit INTWK54 @0x12@1:rpage 0;//External Interrupt (INT pin) Wake-up Function Enable Bit 
static bit INTWK32 @0x12@0:rpage 0;//External Interrupt (INT pin) Wake-up Function Enable Bit 

/*    SFR1 bits    */
static bit CMPSF   @0x14@6:rpage 0;//comparator status flag
static bit HLVDSF  @0x14@5:rpage 0;//Low Voltage Detector status flag
static bit ADSF    @0x14@4:rpage 0;//Status flag for Analog-to-Digital conversion
static bit EXSF1   @0x14@3:rpage 0;//External interrupt status flag
static bit EXSF0   @0x14@2:rpage 0;//External interrupt status flag
//static bit WTSF    @0x14@1:rpage 0;//Watch timer status flag
static bit TCSF    @0x14@0:rpage 0;//TCC overflow status flag

/*    SFR2 bits    */
static bit UERRSF  @0x15@5:rpage 0;//UART receiving error Status flag
static bit URSF    @0x15@4:rpage 0;//UART receive mode data buffer full Status flag
static bit UTSF    @0x15@3:rpage 0;//UART transmit mode data buffer empty flag
static bit TC3DASF @0x15@2:rpage 0;//8-bit timer/Counter 3 Status flag
static bit TC2DASF @0x15@1:rpage 0;//8-bit timer/Counter 2 Status flag
static bit TC1DASF @0x15@0:rpage 0;//8-bit timer/Counter 1 Status flag
/*    SFR3 bits    */
static bit PWMCPSF @0x16@5:rpage 0;//Status flag of period-matching for PWMC
static bit PWMCDSF @0x16@4:rpage 0;//Status flag of duty-matching for PWMC
static bit PWMBPSF @0x16@3:rpage 0;//Status flag of period-matching for PWMB
static bit PWMBDSF @0x16@2:rpage 0;//Status flag of duty-matching for PWMB 
static bit PWMAPSF @0x16@1:rpage 0;//Status flag of period-matching for PWMA  
static bit PWMADSF @0x16@0:rpage 0;//Status flag of duty-matching for PWMA    
/*    SFR4 bits    */
static bit P8ICSF  @0x17@7:rpage 0;//Port 8 Status flag
static bit P7ICSF  @0x17@6:rpage 0;//Port 7 Status flag
static bit P6ICSF  @0x17@5:rpage 0;//Port 6 Status flag
static bit P5ICSF  @0x17@4:rpage 0;//Port 5 Status flag
static bit SPISF   @0x17@3:rpage 0;//SPI mode Status flag
static bit I2CSTPSF@0x17@2:rpage 0;//I2C Stop Status flag
static bit I2CRSF  @0x17@1:rpage 0;//I2C Receive Status flag
static bit I2CTSF  @0x17@0:rpage 0;//I2C Transmit Status flag

/*    SFR5 bits    */
static bit EXSF7   @0x18@5:rpage 0;//External Interrupt Status flag
static bit EXSF6   @0x18@4:rpage 0;//External Interrupt Status flag
static bit EXSF5   @0x18@3:rpage 0;//External Interrupt Status flag
static bit EXSF4   @0x18@2:rpage 0;//External Interrupt Status flag
static bit EXSF3   @0x18@1:rpage 0;//External Interrupt Status flag
static bit EXSF2   @0x18@0:rpage 0;//External Interrupt Status flag
/*    SFR6 bits    */                                               
static bit SHSF    @0x19@7:rpage 0;//System hold Status flag 
static bit TC3DBSF @0x19@2:rpage 0;//TC3DB matches Status flag 
static bit TC2DBSF @0x19@1:rpage 0;//TC2DB matches Status flag 
static bit TC1DBSF @0x19@0:rpage 0;//TC1DB matches Status flag 

/*    IMR1 bits    */
static bit CMPIE   @0x1B@6:rpage 0;//CMPSF interrupt enable bit
static bit HLVDIE  @0x1B@5:rpage 0;//LVDSF interrupt enable bit
static bit ADIE    @0x1B@4:rpage 0;//ADSF interrupt enable bit
static bit EXIE1   @0x1B@3:rpage 0;//EXSF1 interrupt enable bit
static bit EXIE0   @0x1B@2:rpage 0;//EXSF0 interrupt enable bit

static bit TCIE    @0x1B@0:rpage 0;//TCSF interrupt enable bit
	
/*    IMR2 bits    */
static bit UERRIE  @0x1C@5:rpage 0;//UART receive error interrupt enable bit
static bit URIE    @0x1C@4:rpage 0;//UART receive mode Interrupt enable bit
static bit UTIE    @0x1C@3:rpage 0;//UART transmit mode interrupt enable bit
static bit TC3IE   @0x1C@2:rpage 0;//Interrupt enable bit
static bit TC2IE   @0x1C@1:rpage 0;//Interrupt enable bit
static bit TC1IE   @0x1C@0:rpage 0;//Interrupt enable bit   
/*    IMR3 bits    */                                    
static bit PWMCPIE @0x1D@5:rpage 0;//PWMCPSF interrupt enable bit
static bit PWMCDIE @0x1D@4:rpage 0;//PWMCDSF interrupt enable bit
static bit PWMBPIE @0x1D@3:rpage 0;//PWMBPSF interrupt enable bit
static bit PWMBDIE @0x1D@2:rpage 0;//PWMBDSF interrupt enable bit
static bit PWMAPIE @0x1D@1:rpage 0;//PWMAPSF interrupt enable bit
static bit PWMADIE @0x1D@0:rpage 0;//PWMADSF interrupt enable bit

	
/*    IMR4 bits    */
static bit P8ICIE  @0x1E@7:rpage 0;//Ports8 pin-change Interrupt enable bit
static bit P7ICIE  @0x1E@6:rpage 0;//Ports7 pin-change Interrupt enable bit
static bit P6ICIE  @0x1E@5:rpage 0;//Ports6 pin-change Interrupt enable bit
static bit P5ICIE  @0x1E@4:rpage 0;//Ports5 pin-change Interrupt enable bit
static bit SPIIE   @0x1E@3:rpage 0;//SPI  Interrupt enable bit
static bit I2CSTPIE@0x1E@2:rpage 0;//I2C stop interrupt enable bit
static bit I2CRIE  @0x1E@1:rpage 0;//I2C Interface Rx interrupt enable bit 
static bit I2CTIE  @0x1E@0:rpage 0;//I2C Interface Tx interrupt enable bit 

/*    IMR5 bits    */
static bit EXIE7   @0x1F@5:rpage 0;//EXSF7 interrupt enable bit
static bit EXIE6   @0x1F@4:rpage 0;//EXSF6 interrupt enable bit
static bit EXIE5   @0x1F@3:rpage 0;//EXSF5 interrupt enable bit
static bit EXIE4   @0x1F@2:rpage 0;//EXSF4 interrupt enable bit
static bit EXIE3   @0x1F@1:rpage 0;//EXSF3 interrupt enable bit
static bit EXIE2   @0x1F@0:rpage 0;//EXSF2 interrupt enable bit
/*    IMR6 bits    */                                          
static bit SHIE    @0x20@7:rpage 0;//SHSF interrupt enable bit

/*    WDTCR bits    */
static bit WDTE    @0x21@7:rpage 0;//Watchdog Timer Enable Bit
static bit FSSF    @0x21@6:rpage 0;//Fs stabke flag Bit	
static bit PSWE    @0x21@3:rpage 0;//Prescaler enable bit for WDT 
static bit WPSR2   @0x21@2:rpage 0;//WDT Prescaler Bits
static bit WPSR1   @0x21@1:rpage 0;
static bit WPSR0   @0x21@0:rpage 0;
                 /*
                     ; |-----|-----|-----|-----------|
                     ; |WPSR2|WPSR1|WPSR0| WDT Rate  |
                     ; |-----|-----|-----|-----------|
                     ; |  0  |  0  |  0  |    1:1    |
                     ; |-----|-----|-----|-----------|
                     ; |  0  |  0  |  1  |    1:2    |
                     ; |-----|-----|-----|-----------|
                     ; |  0  |  1  |  0  |    1:4    |
                     ; |-----|-----|-----|-----------|
                     ; |  0  |  1  |  1  |    1:8    |
                     ; |-----|-----|-----|-----------|
                     ; |  1  |  0  |  0  |   1:16    |
                     ; |-----|-----|-----|-----------|
                     ; |  1  |  0  |  1  |   1:32    |
                     ; |-----|-----|-----|-----------|
                     ; |  1  |  1  |  0  |   1:64    |
                     ; |-----|-----|-----|-----------|
                     ; |  1  |  1  |  1  |   1:128   |
                     ; |-----|-----|-----|-----------|
                 */

/*    TCCCR bits    */
static bit TCCS    @0x22@6:rpage 0;//TCC Clock Source Select Bit
static bit TS      @0x22@5:rpage 0;//TCC Signal Source
static bit TE      @0x22@4:rpage 0;//TCC Signal Edge
static bit PSTE    @0x22@3:rpage 0;//Prescaler enable bit for TCC
static bit TPSR2   @0x22@2:rpage 0;//TCC Prescaler Bits
static bit TPSR1   @0x22@1:rpage 0;//TCC Prescaler Bits
static bit TPSR0   @0x22@0:rpage 0;//TCC Prescaler Bits
             /*
                    ; |-----|-----|-----|-----------|
                    ; |TPSR2|TPSR1|TPSR0| TCC Rate  |
                    ; |-----|-----|-----|-----------|
                    ; |  0  |  0  |  0  |    1:2    |
                    ; |-----|-----|-----|-----------|
                    ; |  0  |  0  |  1  |    1:4    |
                    ; |-----|-----|-----|-----------|
                    ; |  0  |  1  |  0  |    1:8    |
                    ; |-----|-----|-----|-----------|
                    ; |  0  |  1  |  1  |   1:16    |
                    ; |-----|-----|-----|-----------|
                    ; |  1  |  0  |  0  |   1:32    |
                    ; |-----|-----|-----|-----------|
                    ; |  1  |  0  |  1  |   1:64    |
                    ; |-----|-----|-----|-----------|
                    ; |  1  |  1  |  0  |   1:128   |
                    ; |-----|-----|-----|-----------|
                    ; |  1  |  1  |  1  |   1:256   |
                    ; |-----|-----|-----|-----------|
             */

/*    TC1CR1 bits    */
static bit TC1S    @0x24@7:rpage 0;//Timer/Counter 1 start control
static bit TC1RC   @0x24@6:rpage 0;//Timer 1 Read Control Bit
static bit TC1SS1  @0x24@5:rpage 0;//Timer/Counter 1 clock source select Bit 1
static bit TC1MOD  @0x24@4:rpage 0;// Timer Operation Mode Select Bit
static bit TC1FF   @0x24@3:rpage 0;//Inversion for Timer/Counter 1 as PWM or PDO mode 
static bit TC1OMS  @0x24@2:rpage 0;//Timer Output Mode Select Bit
static bit TC1IS1  @0x24@1:rpage 0;//Timer 1 Interrupt Type Select Bits
static bit TC1IS0  @0x24@0:rpage 0;//Timer 1 Interrupt Type Select Bits
	           /*
	               ; |------|------|---------------------------------|
	               ; |TC1IS1|TC1IS0|   Timer 1 Interrupt Type Select |
	               ; |------|------|---------------------------------|
	               ; |   0  |   0  |   TC1DA (period) matching       |
	               ; |------|------|---------------------------------|
	               ; |   0  |   1  |   TC1DB (duty) matching         |
	               ; |------|------|---------------------------------|
	               ; |   1  |   X  |   TC1DB (duty) matching         |
	               ; |------|------|---------------------------------|
	           */ 

/*    TC1CR2 bits    */
static bit TC1M2   @0x25@7:rpage 0;//Timer/Counter 1 operation mode select
static bit TC1M1   @0x25@6:rpage 0;
static bit TC1M0   @0x25@5:rpage 0;
              /*
                  ; |-------|-------|--------|------------------------------------------------|
                  ; | TC1M2 | TC1M1 |  TC1M0 |   			Operating Mode Select 			  |
                  ; |-------|-------|--------|------------------------------------------------|
                  ; |   0   |   0   |    0   |			Timer/Counter Rising Edge 		      |
                  ; |-------|-------|--------|------------------------------------------------|
                  ; |   0   |   0   |    1   |			Timer/Counter Falling Edge			  |
                  ; |-------|-------|--------|------------------------------------------------|
                  ; |   0   |   1   |    0   |			Capture Mode Rising Edge  		      |
                  ; |-------|-------|--------|------------------------------------------------|
                  ; |   0   |    1  |    1   |			Capture Mode Falling Edge 			  |
   				  ; |-------|-------|--------|------------------------------------------------|
                  ; |   0   |   0   |    0   | 					Window mode   				  |
                  ; |-------|-------|--------|------------------------------------------------|
                  ; |   0   |   0   |    1   | 			Programmable Divider output  		  |
                  ; |-------|-------|--------|------------------------------------------------|
                  ; |   0   |   1   |    0   |			Pulse Width Modulation output		  |
                  ; |-------|-------|--------|------------------------------------------------|
                  ; |   0   |    1  |    1   |Buzzer (output timer/counter clock source.  The |
				  ; |   0   |    1  |    1   |duty cycle of the clock source must be 50/50)   |
				  ; |-------|-------|--------|------------------------------------------------|
              */
static bit TC1SS0  @0x25@4:rpage 0;//Timer Operation Mode Select Bit
static bit TC1CK3  @0x25@3:rpage 0;//Inversion for Timer/Counter 1 as PWM or PDO mode 
static bit TC1CK2  @0x25@2:rpage 0;//Timer Output Mode Select Bit
static bit TC1CK1  @0x25@1:rpage 0;//Timer 1 Interrupt Type Select Bits
static bit TC1CK0  @0x25@0:rpage 0;//Timer 1 Interrupt Type Select 

/*    TC2CR1 bits    */
static bit TC2S    @0x28@7:rpage 0;//Timer/Counter 2 start control
static bit TC2RC   @0x28@6:rpage 0;//Timer 2 Read Control Bit
static bit TC2SS1  @0x28@5:rpage 0;//Timer/Counter 2 clock source select Bit 1 
static bit TC2FF   @0x28@3:rpage 0;//Inversion for Timer/Counter 2 as PWM or PDO mode 
static bit TC2OMS  @0x28@2:rpage 0;//Timer Output Mode Select Bit 
static bit TC2IS1  @0x28@1:rpage 0;//Timer 2 Interrupt Type Select Bits
static bit TC2IS0  @0x28@0:rpage 0;//Timer 2 Interrupt Type Select Bits
              /*
                  ; |------|------|-----------------------------------|
                  ; |TC2IS1|TC2IS0|   Timer 2 Interrupt Type Select   |
                  ; |------|------|-----------------------------------|
                  ; |   0  |   0  |      TC2DA (period) matching      |
                  ; |------|------|-----------------------------------|
                  ; |   0  |   1  |       TC2DB (duty) matching       |
                  ; |------|------|-----------------------------------|
                  ; |   1  |   0  |                                   |
                  ; |------|------|      TC2DA and TC2DB matching     |
                  ; |   1  |   1  |                                   |
                  ; |------|------|-----------------------------------|
              */

/*    TC2CR2 bits    */
static bit TC2M2   @0x29@7:rpage 0;//Timer/Counter 2 operation mode select 
static bit TC2M1   @0x29@6:rpage 0;
static bit TC2M0   @0x29@5:rpage 0;
              /*
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |TC2M2|TC2M1|TC2M0|             Operating Mode Select                  |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  0  |  0  |  0  |           Timer/Counter Rising Edge                |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  0  |  0  |  1  |          Timer/Counter Falling Edge                |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  0  |  1  |  0  |           Capture Mode Rising Edge                 |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  0  |  1  |  1  |          Capture Mode Falling Edge                 |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  1  |  0  |  0  |		             Window mode	                   |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  1  |  0  |  1  |          Programmable Divider output               |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  1  |  1  |  0  |         Pulse Width Modulation output              |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |     |     |     |													   |
                  ; |  1  |  1  |  1  | Buzzer(output timer/counter clock source. The 	   |
				  ;	|     |     |     |		duty cycle of the clock source must be 50/50)  |
                  ; |-----|-----|-----|----------------------------------------------------|
              */
static bit TC2SS0  @0x29@4:rpage 0;//Timer/Counter 2 Clock Source Select Bit 0 
static bit TC2CK3  @0x29@3:rpage 0;//Timer/Counter 2 Clock Source Prescaler Select
static bit TC2CK2  @0x29@2:rpage 0;//Timer/Counter 2 Clock Source Prescaler Select
static bit TC2CK1  @0x29@1:rpage 0;//Timer/Counter 2 Clock Source Prescaler Select
static bit TC2CK0  @0x29@0:rpage 0;//Timer/Counter 2 Clock Source Prescaler Select

/*    TC3CR1 bits    */
static bit TC3S    @0x2C@7:rpage 0;//Timer/Counter 3 start control
static bit TC3RC   @0x2C@6:rpage 0;//Timer 3 Read Control Bit 
static bit TC3SS1  @0x2C@5:rpage 0;//Timer/Counter 3 Clock Source Select Bit 1 
static bit TC3FF   @0x2C@3:rpage 0;//Inversion for Timer/Counter 3 as PWM or PDO mode
static bit TC3OMS  @0x2C@2:rpage 0;//Timer Output Mode Select Bit 
static bit TC3IS1  @0x2C@1:rpage 0;// Timer 3 Interrupt Type Select Bits
static bit TC3IS0  @0x2C@0:rpage 0;// Timer 3 Interrupt Type Select Bits
              /*
                  ; |------|------|-----------------------------------|
                  ; |TC3IS1|TC3IS0|   Timer 3 Interrupt Type Select   |
                  ; |------|------|-----------------------------------|
                  ; |   0  |   0  |      TC3DA (period) matching      |
                  ; |------|------|-----------------------------------|
                  ; |   0  |   1  |       TC3DB (duty) matching       |
                  ; |------|------|-----------------------------------|
                  ; |   1  |   0  |                                   |
                  ; |------|------|      TC3DA and TC3DB matching     |
                  ; |   1  |   1  |                                   |
                  ; |------|------|-----------------------------------|
              */

/*    TC3CR2 bits    */
static bit TC3M2   @0x2D@7:rpage 0;//Timer/Counter 3 operation mode select
static bit TC3M1   @0x2D@6:rpage 0;
static bit TC3M0   @0x2D@5:rpage 0;
              /*
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |TC3M2|TC3M1|TC3M0|             Operating Mode Select                  |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  0  |  0  |  0  |           Timer/Counter Rising Edge                |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  0  |  0  |  1  |          Timer/Counter Falling Edge                |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  0  |  1  |  0  |           Capture Mode Rising Edge                 |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  0  |  1  |  1  |          Capture Mode Falling Edge                 |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  1  |  0  |  0  |		             Window mode	                   |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  1  |  0  |  1  |          Programmable Divider output               |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |  1  |  1  |  0  |         Pulse Width Modulation output              |
                  ; |-----|-----|-----|----------------------------------------------------|
                  ; |     |     |     |													   |
                  ; |  1  |  1  |  1  | Buzzer(output timer/counter clock source. The 	   |
				  ;	|     |     |     |		duty cycle of the clock source must be 50/50)  |
                  ; |-----|-----|-----|----------------------------------------------------|
              */
static bit TC3SS0  @0x2D@4:rpage 0;//Timer/Counter 3 Clock Source Select Bit 0 
static bit TC3CK3  @0x2D@3:rpage 0;//Timer/Counter 3 clock source prescaler select
static bit TC3CK2  @0x2D@2:rpage 0;
static bit TC3CK1  @0x2D@1:rpage 0;
static bit TC3CK0  @0x2D@0:rpage 0;

/*    I2CCR1 bits    */
static bit I2CSP   @0x30@7:rpage 0;//Master mode/Slave mode
static bit S_PEND  @0x30@7:rpage 0;//Master mode/Slave mode	
static bit Strobe  @0x30@7:rpage 0;//Master mode/Slave mode	
static bit Pend    @0x30@7:rpage 0;//Master mode/Slave mode	
static bit IMS     @0x30@6:rpage 0;//I2C Master/Slave mode select bit
static bit ISS     @0x30@5:rpage 0;//I2C Fast/Standard mode select bit
static bit STOP    @0x30@4:rpage 0;//In master mode if stop=1 and r.nw =1 then the mcu must return a nack signal to the slave device before sending a stop signal.
static bit SAR_EMPTY @0x30@3:rpage 0;//set when the mcu transmits a 1 byte data form the i2c slave address register and receives an ack or nack signal.
static bit ACK     @0x30@2:rpage 0;//the ack condition bit is set to 1 by hardware when the device responds with an acknowledge signal
static bit FULL    @0x30@1:rpage 0;//Set by hardware when the I2C Receive Buffer Register is ful
static bit EMPTY   @0x30@0:rpage 0;//set by hardware when i2c transmit buffer register is empty and receives ack signal.

/*    I2CCR2 bits    */
static bit I2CBF   @0x31@7:rpage 0;//I2C Busy Flag Bit 
static bit GCEN    @0x31@6:rpage 0;//I2C General Call Function Enable Bit
static bit BBF     @0x31@4:rpage 0;//Busy Flag Bit
static bit I2CTS2  @0x31@3:rpage 0;//I2C Transmit Clock Select Bits
static bit I2CTS1  @0x31@2:rpage 0;//I2C Transmit Clock Select Bits
static bit I2CTS0  @0x31@1:rpage 0;//I2C Transmit Clock Select Bits
static bit I2CEN   @0x31@0:rpage 0;//I2C Enable Bit 

/*    SPICR bits    */
static bit CES     @0x36@7:rpage 0;//Clock Edge Select Bit 
static bit SPIE    @0x36@6:rpage 0;//SPI Enable Bit 
static bit SRO     @0x36@5:rpage 0;//SPI Read Overflow Bit 
static bit SSE     @0x36@4:rpage 0;//SPI Shift Enable Bit 
static bit SDOC    @0x36@3:rpage 0;//SDO Output Status Control Bit 
static bit SBRS2   @0x36@2:rpage 0;//SPI Baud Rate Select Bits 
static bit SBRS1   @0x36@1:rpage 0;
static bit SBRS0   @0x36@0:rpage 0;
              /*
                  ; |-----|-----------|--------|-------------------|
                  ; |SBRS2|SBRS1|SBRS0|  Mode  |   SPI Baud Rate   |
                  ; |-----|-----------|--------|-------------------|
                  ; |  0  |  0  |  0  | Master |       Fcsc/2      |
                  ; |-----|-----------|--------|-------------------|
                  ; |  0  |  0  |  1  | Master |       Fcsc/4      |
                  ; |-----|-----------|--------|-------------------|
                  ; |  0  |  1  |  0  | Master |       Fcsc/8      |
                  ; |-----|-----------|--------|-------------------|
                  ; |  0  |  1  |  1  | Master |      Fcsc/16      |
                  ; |-----|-----------|--------|-------------------|
                  ; |  1  |  0  |  0  | Master |      Fcsc/32      |
                  ; |-----|-----------|--------|-------------------|
                  ; |  1  |  0  |  1  | Master |      Fcsc/64      |
                  ; |-----|-----------|--------|-------------------|
                  ; |  1  |  1  |  0  | Slave  |     /SS enable    |
                  ; |-----|-----------|--------|-------------------|
                  ; |  1  |  1  |  1  | Slave  |     /SS disable   |
                  ; |-----|-----------|--------|-------------------|
              */

/*    SPIS bits    */
static bit DORD    @0x37@7:rpage 0;//Data Shift of Type Control Bit 
static bit TD1     @0x37@6:rpage 0;//SDO Status Output Delay Times Options
static bit TD0     @0x37@5:rpage 0;//Open drain control bit 
              /*
                  ; |---|---|----------|
                  ; |TD1|TD0|Delay Time|
                  ; |---|---|----------|
                  ; | 0 | 0 |   8 CLK  |
                  ; |---|---|----------|
                  ; | 0 | 1 |  16 CLK  |
                  ; |---|---|----------|
                  ; | 1 | 0 |  24 CLK  |
                  ; |---|---|----------|
                  ; | 1 | 1 |  32 CLK  |
                  ; |---|---|----------|
              */
static bit OD3     @0x37@3:rpage 0;//Open drain control bit
static bit OD4     @0x37@2:rpage 0;//Open drain control bit 
static bit RBF     @0x37@0:rpage 0;//Read Buffer Full Flag 
/*    CMPCR1 bits    */
static bit CRS     @0x3A@7:rpage 0;//Select reference source for inverting terminal of compartor/op
static bit CPOUT   @0x3A@6:rpage 0;//The result of the comparator output
static bit CS1     @0x3A@5:rpage 0;//COmparator select bits
static bit CS0     @0x3A@4:rpage 0;//COmparator select bits
static bit CCS1    @0x3A@2:rpage 0;//COmparator select bits
static bit CCS0    @0x3A@1:rpage 0;//COmparator select bits
static bit SDPWMA  @0x3A@0:rpage 0;//shut down pwma    
/*    CMPCR2 bits    */                                                 
static bit CIRL2   @0x3B@1:rpage 0;//the highh bit of interrnal voltage reference
static bit SDPWMB  @0x3B@0:rpage 0;//shut down pwmb
/*    CMPCR3 bits    */                                                 
static bit CIRL1   @0x3C@2:rpage 0;//the lower two bits of internal boltage reference
static bit CIRL0   @0x3C@1:rpage 0;//the lower two bits of internal boltage reference	
static bit SDPWMC  @0x3C@0:rpage 0;//shut down pwmb
/*    ADCR1 bits    */
static bit CKR2    @0x3E@7:rpage 0;//Clock Rate Selection of ADC 
static bit CKR1    @0x3E@6:rpage 0;
static bit CKR0    @0x3E@5:rpage 0;
static bit ADRUN   @0x3E@4:rpage 0;//ADC Starts to Run 
static bit ADP     @0x3E@3:rpage 0;//ADC Power 
static bit ADOM    @0x3E@2:rpage 0;//ADC Operation Mode Select 
static bit SHS1    @0x3E@1:rpage 0;//Sample and Hold Timing Select 
static bit SHS0    @0x3E@0:rpage 0;//

/*    ADCR2 bits    */                
static bit VPIS2   @0x3F@6:rpage 0;//internal positive reference voltage selection
static bit ADIM    @0x3F@5:rpage 0;//ADC Interrupt Mode 
static bit ADCMS   @0x3F@4:rpage 0;//ADC Compare Mode Select
static bit VPIS1   @0x3F@3:rpage 0;// Internal Positive Reference Voltage Select 
static bit VPIS0   @0x3F@2:rpage 0;//
              /*
                  ; |------|------|------|---------------------|
                  ; | VPIS2| VPIS1| VPIS0|  Reference Voltage  |
                  ; |------|------|------|---------------------|
                  ; |  0   |  0   |   0  |        AVDD         |
                  ; |------|------|------|---------------------|
                  ; |  0   |  0   |   1  |     4.096V          |
                  ; |------|------|------|---------------------|
                  ; |  0   |  1   |   0  |     3.072V          |
                  ; |------|------|------|---------------------|
                  ; |  0   |  1   |   1  |     2.048V          |
                  ; |------|------|------|---------------------| 
                  ; |  1   |  0   |   0  |      2.56V          |
                  ; |------|------|------|---------------------|
                  ; |  1   |  0   |   1  |      2.56V          |
                  ; |------|------|------|---------------------|
                  ; |  1   |  1   |   0 |      2.56V          |
                  ; |------|------|------|---------------------|
                  ; |  1   |  1   |   1  |      2.56V          |
                  ; |------|------|------|---------------------|*/            
static bit VREFP   @0x3F@1:rpage 0;//Positive Reference Voltage Select 
static bit VREFN   @0x3F@0:rpage 0;//negative reference voltage select

/*    ADISR bits    */
static bit ADIS4   @0x40@4:rpage 0;//ADC input channel select bits 
static bit ADIS3   @0x40@3:rpage 0;
static bit ADIS2   @0x40@2:rpage 0;
static bit ADIS1   @0x40@1:rpage 0;
static bit ADIS0   @0x40@0:rpage 0;

/*    ADER1 bits    */
static bit ADE7    @0x41@7:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE6    @0x41@6:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE5    @0x41@5:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE4    @0x41@4:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE3    @0x41@3:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE2    @0x41@2:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE1    @0x41@1:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE0    @0x41@0:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog

/*    ADER2 bits    */
static bit ADE15   @0x42@7:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE14   @0x42@6:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE13   @0x42@5:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE12   @0x42@4:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE11   @0x42@3:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE10   @0x42@2:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE9    @0x42@1:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog
static bit ADE8    @0x42@0:rpage 0;//AD Input Pin Enalbe Control.0//1=>I/O//Analog

	
/*    P5PHCR bits    */
static bit PH57    @0x08@7:rpage 1;//control bit used to enable pull-high of p57
static bit PH56    @0x08@6:rpage 1;//control bit used to enable pull-high of p56
static bit PH55    @0x08@5:rpage 1;//control bit used to enable pull-high of p55
static bit PH54    @0x08@4:rpage 1;//control bit used to enable pull-high of p54
static bit PH53    @0x08@3:rpage 1;//control bit used to enable pull-high of p53
static bit PH52    @0x08@2:rpage 1;//control bit used to enable pull-high of p52
static bit PH51    @0x08@1:rpage 1;//control bit used to enable pull-high of p51
static bit PH50    @0x08@0:rpage 1;//control bit used to enable pull-high of p50
	
/*    P6PHCR bits    */
static bit PH67    @0x09@7:rpage 1;//control bit used to enable pull-high of p67       
static bit PH66    @0x09@6:rpage 1;//control bit used to enable pull-high of p66      
static bit PH65    @0x09@5:rpage 1;//control bit used to enable pull-high of p65      
static bit PH64    @0x09@4:rpage 1;//control bit used to enable pull-high of p64      
static bit PH63    @0x09@3:rpage 1;//control bit used to enable pull-high of p63      
static bit PH62    @0x09@2:rpage 1;//control bit used to enable pull-high of p62      
static bit PH61    @0x09@1:rpage 1;//control bit used to enable pull-high of p61      
static bit PH60    @0x09@0:rpage 1;//control bit used to enable pull-high of p60      	
		
/*    P78PHCR bits    */
static bit P8LPH   @0x0A@2:rpage 1;//control bit used to enable pull-high of port8 low nibble pin
static bit P7HPH   @0x0A@1:rpage 1;//control bit used to enable pull-high of port7 high nibble pin
static bit P7LPH   @0x0A@0:rpage 1;//control bit used to enable pull-high of port7 low nibble pin

/*    P5PLCR bits    */                    
static bit PL57    @0x0B@7:rpage 1;//control bit used to enable pull-low of p57       
static bit PL56    @0x0B@6:rpage 1;//control bit used to enable pull-low of p56         
static bit PL55    @0x0B@5:rpage 1;//control bit used to enable pull-low of p55         
static bit PL54    @0x0B@4:rpage 1;//control bit used to enable pull-low of p54         
static bit PL53    @0x0B@3:rpage 1;//control bit used to enable pull-low of p53         
static bit PL52    @0x0B@2:rpage 1;//control bit used to enable pull-low of p52         
static bit PL51    @0x0B@1:rpage 1;//control bit used to enable pull-low of p51         
static bit PL50    @0x0B@0:rpage 1;//control bit used to enable pull-low of p50 	       
	                                       
/*    P6PLCR bits    */                    
static bit PL67    @0x0C@7:rpage 1;//control bit used to enable pull-low of p67       
static bit PL66    @0x0C@6:rpage 1;//control bit used to enable pull-low of p66         
static bit PL65    @0x0C@5:rpage 1;//control bit used to enable pull-low of p65         
static bit PL64    @0x0C@4:rpage 1;//control bit used to enable pull-low of p64         
static bit PL63    @0x0C@3:rpage 1;//control bit used to enable pull-low of p63         
static bit PL62    @0x0C@2:rpage 1;//control bit used to enable pull-low of p62         
static bit PL61    @0x0C@1:rpage 1;//control bit used to enable pull-low of p61         
static bit PL60    @0x0C@0:rpage 1;//control bit used to enable pull-low of p60 	       
		                                   
/*    P78PLCR bits    */              
static bit P8LPL   @0x0D@2:rpage 1;//control bit used to enable pull-low of port8 low nibble pin                                                                                                                                                                                                                                                                                                                                                                                 
static bit P7HPL   @0x0D@1:rpage 1;//control bit used to enable pull-low of port7 high nibble pin                                                                                                                                                                                                                                                                                                                                                                                
static bit P7LPL   @0x0D@0:rpage 1;//control bit used to enable pull-low of port7 low nibble pin                                                                                                                                                                                                                                                                                                                                                                           	   


/*    P5HDSCR bits    */                    
static bit H57    @0x0E@7:rpage 1;//control bit used to enable high drive/sink of p57      
static bit H56    @0x0E@6:rpage 1;//control bit used to enable high drive/sink of p56        
static bit H55    @0x0E@5:rpage 1;//control bit used to enable high drive/sink of p55        
static bit H54    @0x0E@4:rpage 1;//control bit used to enable high drive/sink of p54        
static bit H53    @0x0E@3:rpage 1;//control bit used to enable high drive/sink of p53        
static bit H52    @0x0E@2:rpage 1;//control bit used to enable high drive/sink of p52        
static bit H51    @0x0E@1:rpage 1;//control bit used to enable high drive/sink of p51        
static bit H50    @0x0E@0:rpage 1;//control bit used to enable high drive/sink of p50	       
	                                       
/*    P6HDSCR bits    */                    
static bit H67    @0x0F@7:rpage 1;//control bit used to enable high drive/sink of p67      
static bit H66    @0x0F@6:rpage 1;//control bit used to enable high drive/sink of p66      
static bit H65    @0x0F@5:rpage 1;//control bit used to enable high drive/sink of p65      
static bit H64    @0x0F@4:rpage 1;//control bit used to enable high drive/sink of p64      
static bit H63    @0x0F@3:rpage 1;//control bit used to enable high drive/sink of p63      
static bit H62    @0x0F@2:rpage 1;//control bit used to enable high drive/sink of p62      
static bit H61    @0x0F@1:rpage 1;//control bit used to enable high drive/sink of p61      
static bit H60    @0x0F@0:rpage 1;//control bit used to enable high drive/sink of p60       
		                                   
/*    P789AHDSCR bits    */           
static bit P8LHDS  @0x10@2:rpage 1;//control bit used to enable high drive/sink of port8 low nibble pin        
static bit P7HHDS  @0x10@1:rpage 1;//control bit used to enable high drive/sink of port7 high nibble pin       
static bit P7LHDS  @0x10@0:rpage 1;//control bit used to enable high drive/sink of port7 low nibble pin  	   


/*    P5ODCR bits    */                    
static bit OD57    @0x11@7:rpage 1;//control bit used to enable open-drain of p57       
static bit OD56    @0x11@6:rpage 1;//control bit used to enable open-drain of p56         
static bit OD55    @0x11@5:rpage 1;//control bit used to enable open-drain of p55         
static bit OD54    @0x11@4:rpage 1;//control bit used to enable open-drain of p54         
static bit OD53    @0x11@3:rpage 1;//control bit used to enable open-drain of p53         
static bit OD52    @0x11@2:rpage 1;//control bit used to enable open-drain of p52         
static bit OD51    @0x11@1:rpage 1;//control bit used to enable open-drain of p51         
static bit OD50    @0x11@0:rpage 1;//control bit used to enable open-drain of p50 	       
	                                       
/*    P6ODCR bits    */                    
static bit OD67    @0x12@7:rpage 1;//control bit used to enable open-drain of p67       
static bit OD66    @0x12@6:rpage 1;//control bit used to enable open-drain of p66         
static bit OD65    @0x12@5:rpage 1;//control bit used to enable open-drain of p65         
static bit OD64    @0x12@4:rpage 1;//control bit used to enable open-drain of p64         
static bit OD63    @0x12@3:rpage 1;//control bit used to enable open-drain of p63         
static bit OD62    @0x12@2:rpage 1;//control bit used to enable open-drain of p62         
static bit OD61    @0x12@1:rpage 1;//control bit used to enable open-drain of p61         
static bit OD60    @0x12@0:rpage 1;//control bit used to enable open-drain of p60 	       
		                                   
/*    P78ODCR bits    */                   
static bit P8LOD   @0x13@2:rpage 1;//control bit used to enable open-drain of port8 low nibble pin                              
static bit P7HOD   @0x13@1:rpage 1;//control bit used to enable open-drain of port7 high nibble pin                             
static bit P7LOD   @0x13@0:rpage 1;//control bit used to enable open-drain of port7 low nibble pin  	                     	  
    
/*    DeadTCR   */
static bit DEADTCE @0x14@4:rpage 1;//Enable dead-time function for pwmc and /pwmc for dual pwm
static bit DEADTBE @0x14@3:rpage 1;//Enable dead-time function for pwmb and /pwmb for dual pwm 
static bit DEADTAE @0x14@2:rpage 1;//Enable dead-time function for pwma and /pwma for dual pwm 
static bit DEADTP1 @0x14@1:rpage 1;//dead time prescaler 
static bit DEADTP0 @0x14@0:rpage 1;//dead time prescaler

    
/*    DeadTR    */   
static bit DEADTR7 @0x15@7:rpage 1;//dead time bit
static bit DEADTR6 @0x15@6:rpage 1;//dead time bit
static bit DEADTR5 @0x15@5:rpage 1;//dead time bit 
static bit DEADTR4 @0x15@4:rpage 1;//dead time bit
static bit DEADTR3 @0x15@3:rpage 1;//dead time bit
static bit DEADTR2 @0x15@2:rpage 1;//dead time bit
static bit DEADTR1 @0x15@1:rpage 1;//dead time bit 
static bit DEADTR0 @0x15@0:rpage 1;//dead time bit	
         
/*    PWMSCR bits    */
static bit DEADS   @0x16@4:rpage 1;//CLOCK selection for dead-time
static bit PWMCS   @0x16@2:rpage 1;//Clock selection for pwmc
static bit PWMBS   @0x16@1:rpage 1;//Clock selection for pwmb
static bit PWMAS   @0x16@0:rpage 1;//Clock selection for pwma
	
/*    PWMACR bits    */
static bit PWMAE   @0x17@7:rpage 1;//PWMA enable bit
static bit IPWMAE  @0x17@6:rpage 1;//inverse¡¡PWMA enable
static bit PWMAA   @0x17@5:rpage 1;//actibe level of PWMA
static bit IPWMAA  @0x17@4:rpage 1;//active level of incerse PWMA	
static bit TAEN    @0x17@3:rpage 1;//TMRA enable bit
static bit TAP2    @0x17@2:rpage 1;//TMRA clock prescaler option bit
static bit TAP1    @0x17@1:rpage 1;//TMRA clock prescaler option bit
static bit TAP0    @0x17@0:rpage 1;//TMRA clock prescaler option bit
/*    PWMBCR bits    */
static bit PWMBE   @0x1E@7:rpage 1;//PWMA enable bit
static bit IPWMBE  @0x1E@6:rpage 1;//inverse¡¡PWMA enable
static bit PWMBA   @0x1E@5:rpage 1;//actibe level of PWMA
static bit IPWMBA  @0x1E@4:rpage 1;//active level of incerse PWMA	
static bit TBEN    @0x1E@3:rpage 1;//TMRB enable bit
static bit TBP2    @0x1E@2:rpage 1;//TMRB clock prescaler option bit
static bit TBP1    @0x1E@1:rpage 1;//TMRB clock prescaler option bit
static bit TBP0    @0x1E@0:rpage 1;//TMRB clock prescaler option bit
/*    PWMCCR bits    */
static bit PWMCE   @0x25@7:rpage 1;//PWMA enable bit
static bit IPWMCE  @0x25@6:rpage 1;//inverse¡¡PWMA enable
static bit PWMCA   @0x25@5:rpage 1;//actibe level of PWMA
static bit IPWMCA  @0x25@4:rpage 1;//active level of incerse PWMA	
static bit TCEN    @0x25@3:rpage 1;//TMRC enable bit
static bit TCP2    @0x25@2:rpage 1;//TMRC clock prescaler option bit
static bit TCP1    @0x25@1:rpage 1;//TMRC clock prescaler option bit
static bit TCP0    @0x25@0:rpage 1;//TMRC clock prescaler option bit
	
		           	
 /*    URCR bits    */
 static bit UINVEN  @0x33@7:rpage 1;//Enable UART TXD and RXD Port Inverse Output Bit
 static bit UMODE1  @0x33@6:rpage 1;//UART mode select bits
 static bit UMODE0  @0x33@5:rpage 1;
               /*
                  ; |------|------|-----------|
                  ; |UMODE1|UMODE0| UART Mode |
                  ; |------|------|-----------|
                  ; |  0   |   0  |Mode1:7-Bit|
                  ; |------|------|-----------|
                  ; |  0   |   1  |Mode1:8-Bit|
                  ; |------|------|-----------|
                  ; |  1   |   0  |Mode1:9-Bit|
                  ; |------|------|-----------|
                  ; |  1   |   1  | Reserved  |
                  ; |------|------|-----------|
              */
static bit BRATE2  @0x33@4:rpage 1;//Transmit Baud rate select 
static bit BRATE1  @0x33@3:rpage 1;
static bit BRATE0  @0x33@2:rpage 1;
              /*
                  ; |------|------|------|-------------|-------------|
                  ; |BRATE2|BRATE1|BRATE0|  Baud Rate  | e.g.FC=8Mhz |
                  ; |------|------|------|-------------|-------------|
                  ; |  0   |  0   |  0   |   Tuart/13  |    38400    |
                  ; |------|------|------|-------------|-------------|
                  ; |  0   |  0   |  1   |   Tuart/26  |    19200    |
                  ; |------|------|------|-------------|-------------|
                  ; |  0   |  1   |  0   |   Tuart/52  |     9600    |
                  ; |------|------|------|-------------|-------------|
                  ; |  0   |  1   |  1   |  Tuart/104  |     4800    |
                  ; |------|------|------|-------------|-------------|
                  ; |  1   |  0   |  0   |  Tuart/208  |     2400    |
                  ; |------|------|------|-------------|-------------|
                  ; |  1   |  0   |  1   |  Tuart/416  |     1200    |
                  ; |------|------|------|-------------|-------------|
                  ; |  1   |  1   |  0   |     TC3     |      -      |
                  ; |------|------|------|---------------------------|
                  ; |  1   |  1   |  1   |           Reserved        |
                  ; |------|------|------|---------------------------|
              */
static bit UTBE    @0x33@1:rpage 1;//UART transfer buffer empty flag
static bit TXE     @0x33@0:rpage 1;//Enable transmission

/*    URS bits    */
static bit URTD8   @0x34@7:rpage 1;//UART Transmit Data Bit 8
static bit EVEN    @0x34@6:rpage 1;//Select parity check
static bit PRE     @0x34@5:rpage 1;//Enable parity addition 
static bit PRERR   @0x34@4:rpage 1;//Parity error flag
static bit OVERR   @0x34@3:rpage 1;//Over running error flag
static bit FMERR   @0x34@2:rpage 1;//Framing error flag
static bit URBF    @0x34@1:rpage 1;//UART read buffer full flag
static bit RXE     @0x34@0:rpage 1;//Enable receiving

/*   URRDH  */
static bit URRD8   @0x37@7:rpage 1;//UART receive data bit 8
static bit URSS    @0x37@0:rpage 1;//UART clock source select bit	

/*   TBPTH   */
static bit HLB     @0x46@7:rpage 1;//Take MLB or LSB at machine code

/*    STKMON bits    */
static bit STOV    @0x47@7:rpage 1;//Stack pointer overflow indication bit

/*    LVDCR bits    */
static bit HLVDEN   @0x49@7:rpage 1;//Low Voltage Detector Enable Bit
static bit IRVSF    @0x49@6:rpage 1;//Internal reference voltage stable flag Bits 	 
static bit VDSB	    @0x49@5:rpage 1;//Voltage detector state bit 
static bit VDM      @0x49@4:rpage 1;//voltage direction magnitude select bit 
static bit LVDS3    @0x49@3:rpage 1;//Low Voltage Detector Level Bits 
static bit LVDS2    @0x49@2:rpage 1;//Low Voltage Detector Level Bits
static bit LVDS1    @0x49@1:rpage 1;//Low Voltage Detector Level Bits
static bit LVDS0    @0x49@0:rpage 1;//Low Voltage Detector Level Bits
    
    
#define	SLEP()	_asm{slep}	//slep
#define	DISI()	_asm{disi}	//½ûÖ¹ÖÐ¶Ï
#define	ENI()	_asm{eni} 	//ÔÊÐíÖÐ¶Ï
#define	WDTC()  _asm{wdtc}	//wdtc
#define	NOP()	_asm{nop}	//¿Õ²Ù×÷


#endif