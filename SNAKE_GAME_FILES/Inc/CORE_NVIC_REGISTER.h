/*
 * CORE_NVIC_REGISTER.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Karim_Zidan
 */

#ifndef CORE_NVIC_REGISTER_H_
#define CORE_NVIC_REGISTER_H_
/*************************** INCLUDE SECTION START*************************/
/*************************** INCLUDE SECTION END***************************/

/***************************MACRO DECLERATION START************************/
#define NVIC_BASE_ADDRESS (0xE000E100)
/***************************MACRO DECLERATION END**************************/

/***************************MACRO FUNCTIONS  START*************************/

/***************************MACRO FUNCTIONS  END***************************/

/***************************DATA  TYPE START*******************************/
typedef struct
{
volatile u32 NVIC_ISER[8]; 	/* Interrupt Set-enable Registers   */
u32 RES1[24];
volatile u32 NVIC_ICER[8]; 	/*Interrupt Clear-enable Registers  */
u32 RES2[24];
volatile u32 NVIC_ISPR[8];	/*Interrupt Set-pending Registers   */
u32 RES3[24];
volatile u32 NVIC_ICPR[8];	/*Interrupt Clear-pending Registers */
u32 RES4[24];
volatile u32 NVIC_IABR[8];	/* Interrupt Priority Registers     */
u32 RES5[56];
volatile u8 NVIC_IPR[240];	/*Interrupt Priority Registers      */
u32 RES6[643];
volatile u32 STIR;

}NVIC_REGISTERS_T;
#define NVIC_REG          ((volatile NVIC_REGISTERS_T*)(NVIC_BASE_ADDRESS))

/***************************DATA  TYPE END*********************************/

/***************************FUNCTION DECLERATION START*********************/

/***************************FUNCTION DECLERATION END***********************/








#endif /* CORE_NVIC_REGISTER_H_ */
