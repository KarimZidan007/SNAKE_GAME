/*
 * MEXT_INT.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Karim_Zidan
 */

#ifndef MEXT_INT_H_
#define MEXT_INT_H_


typedef enum
{
	MEXTI_LINE00=0,
	MEXTI_LINE01,
	MEXTI_LINE02,
	MEXTI_LINE03,
	MEXTI_LINE04,
	MEXTI_LINE05,
	MEXTI_LINE06,
	MEXTI_LINE07,
	MEXTI_LINE08,
	MEXTI_LINE09,
	MEXTI_LINE10,
	MEXTI_LINE11,
	MEXTI_LINE12,
	MEXTI_LINE13,
	MEXTI_LINE14,
	MEXTI_LINE15,
	MEXTI_LINE16,
	MEXTI_LINE17,
	MEXTI_LINE18,
	MEXTI_RES1,
	MEXTI_RES2,
	MEXTI_LINE21,
	MEXTI_LINE22,

}MEXTI_LINE_T;

typedef enum
{
	MEXTI_SENSE_FALLING_EDGE=0,
	MEXTI_SENSE_RAISING_EDGE=1,
	MEXTI_SENSE_ONCHANGE_EDGE=2,
}MEXTI_SENSE_T;
/***
 * @brief this data type is used to configure the port line configuration in syscnfg_reg
 */
typedef enum
{
	MEXTI_PORT_LINE_A=0,
	MEXTI_PORT_LINE_B=1,
	MEXTI_PORT_LINE_C=2,
}MEXTI_PORT_CNFG_T;

typedef struct
{




}MEXTI_INIT_CNFG_T;
/**********************Function decleration section***********************/
/***
 * @brief this function is used to enable the interrupt
 * @param  line_number-> is the external interrupt pin i want to use go check 208/847 on data sheet
 */
void MEXTI_voidInterruptEnable(MEXTI_LINE_T line_number);
/***
 * @brief this function is used to disable the interrupt
 * @param  line_number-> is the external interrupt pin i want to use go check 208/847 on data sheet
 */
void MEXTI_voidInterruptDisable(MEXTI_LINE_T line_number);
/***
 * @brief this function is used to set the sense configurations of the external interrupt
 * @param line_number-> is the external interrupt pin i want to use go check 208/847 on data sheet
 * @param SENSE -> the mode of external interrupt (FALLING,RAISING,ONCHANGE)
 */
void MEXTI_voidSetSenseControl(MEXTI_LINE_T line_number,MEXTI_SENSE_T SENSE);
/***
 * @brief this function is used to set the call back function for the 23 lines
 * @param pf -> pointer to function
 * @param line_number-> is the external interrupt pin i want to use go check 208/847 on data sheet
 */

void MEXTI_SETCALLBACK(void(*pf)(void),MEXTI_LINE_T line_number);



void MEXTI_voidSelectPortToLine(MEXTI_LINE_T line_number,MEXTI_PORT_CNFG_T PORT_LINE_N);


void MEXTI_CLEARFLAG(MEXTI_LINE_T line_number);
/******************************HOW TO INIT EXTERNAL INTERRUPT*****************************/




/******************************HOW TO INIT EXTERNAL INTERRUPT*****************************/

#endif /* MEXT_INT_H_ */
