/*
 * MEXT_INT.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Karim_Zidan
 */
#include"common/STD_TYPES.h"
#include"common/BIT_MATH.h"
#include"MEXT_REGISTER.h"
#include"MEXT_INT.h"

/*************************************************************/
void (*MEXTI_CallBacks[23])(void);

/*************************************************************/

/***
 * @brief this function is used to enable the interrupt
 * @param  line_number-> is the external interrupt pin i want to use go check 208/847 on data sheet
 */
void MEXTI_voidInterruptEnable(MEXTI_LINE_T line_number)
{
	SET_BIT(EXT_INT_REG->EXTI_IMR,line_number);

}
/***
 * @brief this function is used to disable the interrupt
 * @param  line_number-> is the external interrupt pin i want to use go check 208/847 on data sheet
 */
void MEXTI_voidInterruptDisable(MEXTI_LINE_T line_number)
{

	CLEAR_BIT(EXT_INT_REG->EXTI_IMR,line_number);
}
/***
 * @brief this function is used to set the sense configurations of the external interrupt
 * @param line_number-> is the external interrupt pin i want to use go check 208/847 on data sheet
 * @param SENSE -> the mode of external interrupt (FALLING,RAISING,ONCHANGE)
 */
void MEXTI_voidSetSenseControl(MEXTI_LINE_T line_number,MEXTI_SENSE_T SENSE)
{
	switch(SENSE)
	{
	case MEXTI_SENSE_FALLING_EDGE:
		//i should clear the raising to prevent going into on change mode
		SET_BIT(EXT_INT_REG->EXTI_FTSR,line_number);
		CLEAR_BIT(EXT_INT_REG->EXTI_RTSR,line_number);
		break;
	case MEXTI_SENSE_RAISING_EDGE:
		//i should clear the failling to prevent going into on change mode
		CLEAR_BIT(EXT_INT_REG->EXTI_FTSR,line_number);
		SET_BIT(EXT_INT_REG->EXTI_RTSR,line_number);
		break;
	case MEXTI_SENSE_ONCHANGE_EDGE:
		//to enable interrupt on change
		SET_BIT(EXT_INT_REG->EXTI_FTSR,line_number);
		SET_BIT(EXT_INT_REG->EXTI_RTSR,line_number);
		break;
	default:break;
	}
}
/***
 * @brief this function is used to set the call back function for the 23 lines
 * @param pf -> pointer to function
 * @param line_number-> is the external interrupt pin i want to use go check 208/847 on data sheet
 */
void MEXTI_SETCALLBACK(void(*pf)(void),MEXTI_LINE_T line_number)
{
/*save the passed pointer into the array with passed index(line_n)*/
	MEXTI_CallBacks[line_number]=pf;
}
/***
 * @brief this function is used to select port to line configurations
 * @param line_number-> is the external interrupt pin i want to use go check 208/847 on data sheet
 * @param  PORT_LINE_N -> ENUM CONTAIN PORT_LINE_CNFG
 */
void MEXTI_voidSelectPortToLine(MEXTI_LINE_T line_number,MEXTI_PORT_CNFG_T PORT_LINE_N)
{
u8 REG_ARRAY_INDEX=line_number/4;
u8 START_BIT=((line_number%4)*4);
MODIFY_REG(SYSCFG_EXTICF_REGS[REG_ARRAY_INDEX],0b1111,PORT_LINE_N,START_BIT);
}

void MEXTI_CLEARFLAG(MEXTI_LINE_T line_number)
{

	SET_BIT(EXT_INT_REG->EXTI_PR,line_number);

}




void EXTI0_IRQHandler(void)
{
	if(NULL!=MEXTI_CallBacks[MEXTI_LINE00])
	{
		MEXTI_CallBacks[MEXTI_LINE00]();//adding invoke operator to pointer to function
	}
}

void EXTI1_IRQHandler(void)
{
	if(NULL!=MEXTI_CallBacks[MEXTI_LINE01])
	{
		MEXTI_CallBacks[MEXTI_LINE01]();//adding invoke operator to pointer to function
	}
}

void EXTI2_IRQHandler(void)
{
	if(NULL!=MEXTI_CallBacks[MEXTI_LINE02])
	{
		MEXTI_CallBacks[MEXTI_LINE02]();//adding invoke operator to pointer to function
	}
}
void EXTI9_5_IRQHandler(void)
{
	if(NULL!=MEXTI_CallBacks[MEXTI_LINE06])
		{
			MEXTI_CallBacks[MEXTI_LINE06]();//adding invoke operator to pointer to function
			MEXTI_CLEARFLAG(MEXTI_LINE06);
		}

}
