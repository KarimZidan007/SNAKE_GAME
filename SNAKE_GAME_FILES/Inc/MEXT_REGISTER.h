/*
 * MEXT_REGISTER.h
 *
 *  Created on: Sep 12, 2023
 *      Author: m
 */

#ifndef MEXT_REGISTER_H_
#define MEXT_REGISTER_H_

/**********************macro decleration section***********************/
#define EXT_INT_BASE_ADDRESS     (0x40013C00)

/*****SYSCNFG ADDRESSES********/
#define SYSCFG_BASE_ADDRESS 	 (0x40013800)
#define SYSCFG_EXTICF_OFFSET     (0x08)

typedef struct
{
u8 EXTI_0:4	;
u8 EXTI_1:4	;
u8 EXTI_2:4	;
u8 EXTI_3:4	;
u16 RESERVED;
}SYSCFG_EXTICR1_T;
typedef struct
{
u8 EXTI_4:4	;
u8 EXTI_5:4	;
u8 EXTI_6:4	;
u8 EXTI_7:4	;
u16 RESERVED;
}SYSCFG_EXTICR2_T;
typedef struct
{
u8 EXTI_8:4	;
u8 EXTI_9:4	;
u8 EXTI_10:4	;
u8 EXTI_11;
u16 RESERVED;
}SYSCFG_EXTICR3_T;
typedef struct
{
u8 EXTI_12:4	;
u8 EXTI_13:4	;
u8 EXTI_14:4	;
u8 EXTI_15:4	;
u16 RESERVED;
}SYSCFG_EXTICR4_T;


typedef struct
{
volatile SYSCFG_EXTICR1_T SYSCFG_EXTICR1 ; /*SYSCFG external interrupt configuration register 1*/
volatile SYSCFG_EXTICR2_T SYSCFG_EXTICR2 ;  /*SYSCFG external interrupt configuration register 2*/
volatile SYSCFG_EXTICR3_T SYSCFG_EXTICR3 ; /*SYSCFG external interrupt configuration register 3*/
volatile SYSCFG_EXTICR4_T SYSCFG_EXTICR4 ; /*SYSCFG external interrupt configuration register 4*/
volatile u32 SYSCFG_CMPCR ;/*Compensation cell control register */
}SYSCFG_EXTICF_REG_T;

#define  SYSCFG_EXTICF_ADDRESS   (SYSCFG_BASE_ADDRESS+SYSCFG_EXTICF_OFFSET)

/**********************data type section***********************/
typedef struct
{
volatile u32 EXTI_IMR ; /* INTERRUPT ENABLE AND DISABLE*/
volatile u32 EXTI_EMR ;  /* Event mask register */
volatile u32 EXTI_RTSR ; /*Rising trigger selection register*/
volatile u32 EXTI_FTSR ; /*Falling trigger selection register*/
volatile u32 EXTI_SWIER ;/*Software interrupt event register*/
volatile u32 EXTI_PR ;   /*Pending register*/
}EXT_INT_REG_T;

#define EXT_INT_REG    ((volatile EXT_INT_REG_T *)(EXT_INT_BASE_ADDRESS))
/****************************************************************************/

#define SYSCFG_EXTICF_REGS    ((volatile u32 *)(SYSCFG_EXTICF_ADDRESS))


/**********************Function decleration section***********************/






#endif /* MEXT_REGISTER_H_ */
