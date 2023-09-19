/*
 * MSYSTICK_REGISTERS.h
 *
 *  Created on: Sep 14, 2023
 *      Author: karim_Zidan
 */

#ifndef MSYSTICK_REGISTERS_H_
#define MSYSTICK_REGISTERS_H_


#define SYSTICK_ADDRESS    (0xE000E010)

typedef struct{
	u8 ENABLE:1;	//enable counting
	u8 TICK_INTTERRUPT:1 ;  //enable interrupt
	u8 CLK_SOURCE:1;
	u16 RESERVED :13;
	u8 CLK_FLAG:1;
	u16 reserved :15;
}SYST_CSR_T;

typedef struct{
	u32 RELOAD:24;	//reload value
	u8 RESERVED:8 ;  //reserved
}SYST_PVR_T;

typedef struct{
	u32 CURRENT:24;	//current value
	u8 RESERVED:8 ;  //reserved
}SYST_CVR_T;


typedef struct{
	u32 TENMS:24;	//Reload value for 10ms (100Hz) timing, subject to system clock skew errors. If the value reads as zero, the calibration value is not known.
	u8 RESERVED:6 ;  //reserved
	u8 SKEW:1;       //
	u8 NOREF:1;
}SYST_CALIB_T;

typedef struct
{
	volatile SYST_CSR_T SYST_CTRL;   /*SSysTick Control and Status Register*/
	volatile SYST_PVR_T SYST_RELOAD;   /*SysTick Reload Value Register*/
	volatile SYST_CVR_T SYST_CURRENT;   /*SysTick Reload Value Register*/
	volatile SYST_CALIB_T SYST_CALIB;   /*SSysTick Calibration  Register*/
}SYSTICK_REG_T;

#define SYSTICK_REG    ((SYSTICK_REG_T*)(SYSTICK_ADDRESS))

#endif /* MSYSTICK_REGISTERS_H_ */
