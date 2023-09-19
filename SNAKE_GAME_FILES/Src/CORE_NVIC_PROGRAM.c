/**
 ******************************************************************************
 * @file           : CORE_NVIC.c
 * @author         : Karim_Zidan
 * @brief          : Main program body
 ******************************************************************************

 */
#include"common/STD_TYPES.h"
#include"common/BIT_MATH.h"
#include"CORE_NVIC_REGISTER.h"
#include"CORE_NVIC_INTERFACE.h"
#include"NVIC_SCB.h"
#include <math.h>


u8 Group_priority_Bits_N=0;
u8 Sub_priority_Bits_N=0;
u8 Number_of_Subpriority_available=0;
u8 Number_of_Group_priority_available=0;

void NVIC_EnableIRQ(IRQn_Type IRQn)
{
	if((u32)IRQn>0)
	{
		/*what inside the array calculate the register number through
		 * shifting it the 5 bits that represents 31 in decimal*/
		/*the bit postion is calculated through anding the request number
		 * with 31 which filtering the msb bits which represents the reg pos*/
		NVIC_REG->NVIC_ISER[((u32)IRQn>>5)]=(1UL<<(IRQn&0x1F));
	}
	else{}
}
void NVIC_DisableIRQ(IRQn_Type IRQn)
{
	if((u32)IRQn>0)
	{
		/*what inside the array calculate the register number through
		 * shifting it the 5 bits that represents 31 in decimal*/
		/*the bit postion is calculated through anding the request number
		 * with 31 which filtering the msb bits which represents the reg pos*/
		NVIC_REG->NVIC_ICER[((u32)IRQn>>5)]=(1UL<<((u32)IRQn&0x1F));
	}
	else{}

}
void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	if((u32)IRQn>0)
	{
		/*what inside the array calculate the register number through
		 * shifting it the 5 bits that represents 31 in decimal*/
		/*the bit postion is calculated through anding the request number
		 * with 31 which filtering the msb bits which represents the reg pos*/
		(NVIC_REG->NVIC_ISPR[((u32)IRQn>>5)])=(1UL<<((u32)IRQn&0x1F));
		//NVIC_REG->NVIC_ISPR[0] = 1<<13;
	}
	else{}

}
void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	if((u32)IRQn>0)
	{
		/*what inside the array calculate the register number through
		 * shifting it the 5 bits that represents 31 in decimal*/
		/*the bit postion is calculated through anding the request number
		 * with 31 which filtering the msb bits which represents the reg pos*/
		(NVIC_REG->NVIC_ICPR[((u32)IRQn>>5)])=(1UL<<((u32)IRQn&0x1F));
	}
	else{}

}
u32 NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
	if((u32)IRQn>0)
	{
		/*what inside the array calculate the register number through
		 * shifting it the 5 bits that represents 31 in decimal*/
		/*the bit postion is calculated through anding the request number
		 * with 31 which filtering the msb bits which represents the reg pos*/
		return ((NVIC_REG->NVIC_IABR[((u32)IRQn>>5)])&(((u32)1<<(IRQn&0x1F))) ? INTERRUPT_ACTIVE :INTERRUPT_NOT_ACTIVE);
	}
	else{ return 0;}


}

void NVIC_GetPrioritty(IRQn_Type IRQn, u8 * Group_priority , u8 * subpriority)
{
	u32 REG_VALUE;
	u32 REG;
	REG=SCB_GET_GROUP_PRIORITY();
	u8 difference=REG-NVIC_GROUP_PRI_1;
	* Group_priority=NVIC_REG->NVIC_IPR[IRQn]>> (4 + difference);
	* subpriority=((NVIC_REG->NVIC_IPR[IRQn]<<(4 - difference) ) >> (8 - difference));

}
Std_ReturnType NVIC_Set_Priority(IRQn_Type IRQn, u8 Group_priority , u8 subpriority)
{
	Std_ReturnType status =E_NOT_OK;
	Group_priority_Bits_N=(~((u8)SCB_GET_GROUP_PRIORITY()))&0x7;
	Sub_priority_Bits_N=(4-Group_priority_Bits_N);
	Number_of_Group_priority_available=(1<< Group_priority_Bits_N);
	Number_of_Subpriority_available=16/Number_of_Group_priority_available;

	if((Number_of_Group_priority_available<Group_priority)|(Number_of_Subpriority_available<subpriority))
	{
		status =E_NOT_OK;
	}
	else
	{
		NVIC_REG->NVIC_IPR[IRQn]=(((u8)(Group_priority<<(IPR_MAX_SIZE-Group_priority_Bits_N)))|((u8)(subpriority<<(IPR_MAX_SIZE-(Group_priority_Bits_N+Sub_priority_Bits_N)))));
		status=E_OK;
	}

	return status;
}
Std_ReturnType NVIC_GetPriority(IRQn_Type IRQn, u8 * Group_priority , u8 * subpriority)
{
	Std_ReturnType status =E_NOT_OK;
	if((NULL==Group_priority)|(NULL==subpriority))
	{
		 status =E_NOT_OK;
	}
	else
	{
		* Group_priority=(NVIC_REG->NVIC_IPR[IRQn])>>(8-Group_priority_Bits_N);
		* subpriority=((u8)((NVIC_REG->NVIC_IPR[IRQn])<<(Group_priority_Bits_N))>>(8-Sub_priority_Bits_N));
		status =E_NOT_OK;
	}

	return status;
}
