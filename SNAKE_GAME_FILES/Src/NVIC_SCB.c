/*
 * NVIC_SCB.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Karim_Zidan
 */
#include"common/STD_TYPES.h"
#include"common/BIT_MATH.h"
#include"NVIC_SCB.h"

Std_ReturnType SCB_INIT_GROUP_PRIORITY(NVIC_SCB_PRIGROUP_T EnCpy_PRIGROUP )
{
	u32 REG_VALUE=0;
	Std_ReturnType status=E_NOT_OK;
	/*i need to clear the register first*/
	REG_VALUE=SCB_REG->AIRCR;
	REG_VALUE &=~(AIRCR_MASKING);
	/*then set the new value to the register*/
	REG_VALUE|=((VECTKEY<<VECT_KEY_POS)|((u32)EnCpy_PRIGROUP<<PRIGROUP_POS));
	SCB_REG->AIRCR=REG_VALUE;
	status=E_OK;
	return status;
}
u32 SCB_GET_GROUP_PRIORITY(void)
{
	return (((u32)SCB_REG->AIRCR&AIRCR_GET_VAL_MASKING)>>PRIGROUP_POS);
}
