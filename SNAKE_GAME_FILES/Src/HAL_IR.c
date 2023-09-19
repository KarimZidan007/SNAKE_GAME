/*
 * HAL_IR.c
 *
 *  Created on: Sep 18, 2023
 *      Author: Karim_Zidan
 */
#include"common/STD_TYPES.h"
#include"common/BIT_MATH.h"
#include"MSYSTICK_REGISTERS.h"
#include"MSYSTICK_INTERFACE.h"
u16 IR_FRAME[33];
u8 START_BIT_FLAG=0;
volatile u8 READED_DATA=0;
u8 INDEX=0;
u32 ELAPSED_TIME=0;
u32 READED_FRAME_TIME=0;

void EXTRACT_DATA(void)
{
	for(u8 i =0 ; i<8 ; i++)
	{
		if(IR_FRAME[17+i]<1300)
		{
			CLEAR_BIT(READED_DATA,i);
		}
		else if(IR_FRAME[17+i]>2000)
		{
			SET_BIT(READED_DATA,i);
		}
	}
	START_BIT_FLAG=0;
	INDEX=0;
}

void IR_HANDLER(void)
{
	if(START_BIT_FLAG==0)
	{
		START_BIT_FLAG=1;
		MSYSTICK_VoidIntervalSingle(70000, EXTRACT_DATA);
	}
	else if(START_BIT_FLAG==1)
	{
		if(INDEX<33)
		{
			MSYSTICK_VoidGetElapsedTime(&ELAPSED_TIME);
			IR_FRAME[INDEX]=ELAPSED_TIME-READED_FRAME_TIME;
			READED_FRAME_TIME=0;
			READED_FRAME_TIME=ELAPSED_TIME;
			INDEX++;
		}
		else
		{}
	}
}

