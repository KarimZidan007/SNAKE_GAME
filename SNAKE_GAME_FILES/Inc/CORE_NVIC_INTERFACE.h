/*
 * CORE_NVIC_INTERFACE.h
 *
 *  Created on: Sep 10, 2023
 *  Author: Karim_Zidan
 */

#ifndef CORE_NVIC_INTERFACE_H_
#define CORE_NVIC_INTERFACE_H_
/*************************** INCLUDE SECTION START*************************/
/*************************** INCLUDE SECTION END***************************/
#define IPR_MAX_SIZE   8
/***************************MACRO DECLERATION START************************/

/***************************MACRO DECLERATION END**************************/

/***************************MACRO FUNCTIONS  START*************************/

/***************************MACRO FUNCTIONS  END***************************/

/***************************DATA  TYPE START*******************************/
typedef enum
{
/***************************SYSTEM EXCEPTIONS************************/

/***************************INTERRUPTS ******************************/
 WWDG = 0,                    /*Window Watchdog interrupt*/
 EXTI16,                  /*EXTI Line 16 interrupt / PVD through EXTIline detection interrupt*/
 EXTI21,                  /*EXTI Line 21 interrupt /Tamper and TimeStamp interrupts throughthe EXTI line*/
 EXTI22,                  /*EXTI Line 22 interrupt /RTC Wakeup interrupt through the EXTIline*/
 FLASH,                   /*Flash global interrupt*/
 RCC,                     /*RCC global interrupt*/
 EXTI0,                   /*EXTI Line0 interrupt*/
 EXTI1,                   /*EXTI Line1 interrupt*/
 EXTI2,                   /*EXTI Line2 interrupt*/
 EXTI3,                   /*EXTI Line3 interrupt*/
 EXTI4,                   /*EXTI Line4 interrupt*/
 DMA1_Stream0,            /*DMA1 Stream0 global interrupt*/
 DMA1_Stream1,            /*DMA1 Stream1 global interrupt*/
 DMA1_Stream2,            /*DMA1 Stream2 global interrupt*/
 DMA1_Stream3,            /*DMA1 Stream3 global interrupt*/
 DMA1_Stream4,            /*DMA1 Stream4 global interrupt*/
 DMA1_Stream5,            /*DMA1 Stream5 global interrupt*/
 DMA1_Stream6,            /*DMA1 Stream6 global interrupt*/
 ADC,                     /*ADC1 global interrupts*/
 EXTI9_5=23,                 /*EXTI Line[9:5] interrupts*/
 TIM1_BRK_TIM9,           /*TIM1 Break interrupt and TIM9 globalinterrupt*/
 TIM1_UP_TIM10,           /*TIM1 Update interrupt and TIM10 globalinterrupt*/
 TIM1_TRG_COM_TIM11,      /*TIM1 Trigger and Commutation interruptsand TIM11 global interrupt*/
 TIM1_CC,                 /*TIM1 Capture Compare interrupt*/
 TIM2,                    /*TIM2 global interrupt*/
 TIM3,                    /*TIM3 global interrupt*/
 TIM4,                    /*TIM4 global interrupt*/
 I2C1_EV,                 /*I2C1 event interrupt*/
 I2C1_ER,                 /*I2C1 error interrupt*/
 I2C2_EV,                 /*I2C2 event interrupt*/
 I2C2_ER,                 /*I2C2 error interrupt*/
 SPI1,                    /*SPI1 global interrupt*/
 SPI2,                    /*SPI2 global interrupt*/
 USART1,                  /*USART1 global interrupt*/
 USART2,                  /*USART2 global interrupt*/
 EXTI15_10=40,               /*EXTI Line[15:10] interrupts*/
 EXTI17_RTC_Alarm,        /*EXTI Line 17 interrupt / RTC Alarms (A andB) through EXTI line interrupt*/
 EXTI18_OTG_FS_WKUP,      /*EXTI Line 18 interrupt / USB On-The-GoFS Wakeup through EXTI line interrupt*/
 DMA1_Stream7=47,         /*DMA1 Stream7 global interrupt*/
 SDIO=49,        	          /*SDIO global interrupt*/
 TIM5,                    /*TIM5 global interrupt*/
 SPI3,                    /*SPI3 global interrupt*/
 DMA2_Stream0=56,         /*DMA2 Stream0 global interrupt*/
 DMA2_Stream1,            /*DMA2 Stream1 global interrupt*/
 DMA2_Stream2,            /*DMA2 Stream2 global interrupt*/
 DMA2_Stream3,            /*DMA2 Stream3 global interrupt*/
 DMA2_Stream4,            /*DMA2 Stream4 global interrupt*/
 OTG_FS=67,               /*USB On The Go FS global interrupt*/
 DMA2_Stream5,            /*DMA2 Stream5 global interrupt*/
 DMA2_Stream6,            /*DMA2 Stream6 global interrupt*/
 DMA2_Stream7,            /*DMA2 Stream7 global interrupt*/
 USART6,                  /*USART6 global interrupt*/
 I2C3_EV,                 /*I2C3 event interrupt*/
 I2C3_ER,                 /*I2C3 error interrupt*/
 FPU=81,                     /*FPU global interrupt*/
 SPI4=84,                    /*SPI 4 global interrupt*/
}IRQn_Type;
typedef enum
{
INTERRUPT_NOT_ACTIVE,
INTERRUPT_ACTIVE,
}NVIC_ACTIVE_STATUS_T;
/***************************DATA  TYPE END*********************************/

/***************************FUNCTION DECLERATION START*********************/
void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
u32 NVIC_GetPendingIRQ(IRQn_Type IRQn);
Std_ReturnType NVIC_Set_Priority(IRQn_Type IRQn, u8 Group_priority , u8 subpriority);
Std_ReturnType NVIC_GetPriority(IRQn_Type IRQn, u8 * Group_priority , u8 * subpriority);
/***************************FUNCTION DECLERATION END***********************/
#endif /* CORE_NVIC_INTERFACE_H_ */
