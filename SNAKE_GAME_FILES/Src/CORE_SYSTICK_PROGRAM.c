/*
 * CORESYSTICK_PROGRAM.c
 *
 *  Created on: Sep 14, 2023
 *      Author: karim
 */
#include"common/STD_TYPES.h"
#include"common/BIT_MATH.h"
#include"MSYSTICK_PRIVATE.h"
#include"MSYSTICK_CONFIG.h"
#include"MSYSTICK_REGISTERS.h"
#include"MSYSTICK_INTERFACE.h"
/***************CALL BACK PTR TO FUNCTION******************/
void(*Systick_callback)(void)=NULL;
/***************CALL BACK PTR TO FUNCTION******************/
SYSTICK_INTERVAL_STATE_T G_ENU_INTERVALSTATEFLAG=SYSTICK_INTERVAL_SINGLE;


/***
 * @brief this function is used to init the clock of systick
 */
void MSYSTICK_VoidInit()
{
	SYSTICK_REG->SYST_CTRL.CLK_SOURCE=SYSTICK_CLOCK;
}
/***
 * @brief this function is used to set busy wait
 */
void MSYSTICK_VoidSetBusyWaitDelay(u32 Time_Ticks)
{
	/*Reset Counter Register*/
	SYSTICK_REG->SYST_RELOAD.RELOAD=0;
	/*SET LOAD VALUE With the passed busy wait ticks*/
	SYSTICK_REG->SYST_RELOAD.RELOAD=Time_Ticks;

	SYSTICK_REG->SYST_CTRL.ENABLE=SYS_ENABLE;

	/*Wait Till Flag is Raised*/
	while((SYSTICK_REG->SYST_CTRL.CLK_FLAG)==FLAG_NOT_READY);

	/*Disable Timer*/

	SYSTICK_REG->SYST_CTRL.ENABLE=SYS_DISABLE;
	/*Reset for the next time*/
	SYSTICK_REG->SYST_RELOAD.RELOAD=0;
	SYSTICK_REG->SYST_CURRENT.CURRENT=0;
	/*Enable Timer*/
}
/***
 * @brief this function is used to call interval function with systick once
 * @param Time_Ticks -> the time we want the function to execute after
 * @param notification-> the call back function iwant to execute after time_ticks time
 */
void MSYSTICK_VoidIntervalSingle(u32 Time_Ticks,void(*notification)(void))
{
	G_ENU_INTERVALSTATEFLAG=SYSTICK_INTERVAL_SINGLE;
	/* setup the envirmonet */


	SYSTICK_REG->SYST_RELOAD.RELOAD=0;

	SYSTICK_REG->SYST_CURRENT.CURRENT=0;
	/*Load*/
	SYSTICK_REG->SYST_RELOAD.RELOAD=Time_Ticks;


	/*Clear Flag*/
	/*I HAVE TWO CHOICES INTERRUPT AND POOLING */
	/*Set call back function */
	if(NULL!=notification)
	{
		/*Enable interrupt*/
		SYSTICK_REG->SYST_CTRL.TICK_INTTERRUPT=1;
		Systick_callback=notification;
	}
	else{}
	/*Enable Timer*/
	SYSTICK_REG->SYST_CTRL.ENABLE=SYS_ENABLE;
}
/***
 * @brief this function is used to call interval function with systick periodiclly
 * @param Time_Ticks -> the time we want the function to execute after
 * @param notification-> the call back function iwant to execute after (time_ticks) time
 */
void MSYSTICK_VoidIntervalPeriodic(u32 Time_Ticks,void(*notification)(void))
{
	G_ENU_INTERVALSTATEFLAG=SYSTICK_INTERVAL_PERIODIC;
	/* setup the envirmonet */
	SYSTICK_REG->SYST_RELOAD.RELOAD=0;
	SYSTICK_REG->SYST_CURRENT.CURRENT=0;
	/*Load*/
	SYSTICK_REG->SYST_RELOAD.RELOAD=Time_Ticks;


	/*Clear Flag*/
	/*I HAVE TWO CHOICES INTERRUPT AND POOLING */
	/*Set call back function */
	if(NULL!=notification)
	{
		/*Enable interrupt*/
		SYSTICK_REG->SYST_CTRL.TICK_INTTERRUPT=1;
		Systick_callback=notification;
	}
	else{}
	/*Enable Timer*/
	SYSTICK_REG->SYST_CTRL.ENABLE=SYS_ENABLE;
}
/***
 * @brief this function is used to stop the timer
 *
 */
void MSYSTICK_VoidTimerStop()
{
	/*Disable Timer*/
	SYSTICK_REG->SYST_CTRL.ENABLE=SYS_DISABLE;
	/*Disable Interrupt*/
	SYSTICK_REG->SYST_CTRL.TICK_INTTERRUPT=0;

	/*clear flag*/
	SYSTICK_REG->SYST_CURRENT.CURRENT=0;
	SYSTICK_REG->SYST_RELOAD.RELOAD=0;
}
/***
 * @brief this function is used to get elapsed time
 */
void MSYSTICK_VoidGetElapsedTime(u32 *P_Read_var)
{
	*P_Read_var=SYSTICK_REG->SYST_RELOAD.RELOAD-SYSTICK_REG->SYST_CURRENT.CURRENT;

}
/***
 * @brief this function is used to get remaining time
 */
void MSYSTICK_VoidGetRemaningTime(u32 *P_Read_var)
{
	*P_Read_var=SYSTICK_REG->SYST_CURRENT.CURRENT;

}

/***
 * @brief the call back function
 */
void SysTick_Handler(void)
{
	switch(G_ENU_INTERVALSTATEFLAG)
	{
	case SYSTICK_INTERVAL_PERIODIC:
		if(NULL!=Systick_callback)
		{
			Systick_callback();
		}
		break;
	case SYSTICK_INTERVAL_SINGLE:
		if(NULL!=Systick_callback)
		{
			MSYSTICK_VoidTimerStop();
			Systick_callback();
		}
		/*disable timer*/
		SYSTICK_REG->SYST_CTRL.ENABLE=SYS_DISABLE;
		break;
	default: break;

	}


}

