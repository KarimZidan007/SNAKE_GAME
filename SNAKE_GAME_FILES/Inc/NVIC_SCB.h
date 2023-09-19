/*
 * NVIC_SCB.h
 *
 *  Created on: Sep 11, 2023
 *      Author: m
 */

#ifndef NVIC_SCB_H_
#define NVIC_SCB_H_
/*************************** INCLUDE SECTION START*************************/

/*************************** INCLUDE SECTION END***************************/

/***************************MACRO DECLERATION START************************/
#define VECTKEY        			  (0x5FA)
#define VECT_KEY_POS  			  (16UL)
#define PRIGROUP_POS  			  (8UL)
#define AIRCR_ADDRESS  			  (0xE000ED0C)
#define AIRCR_MASKING  			  (0xFFFF0700)/*SET MASKING FOR WRITING ON REGISTER*/
#define AIRCR_GET_VAL_MASKING     (0x00000700)/*GET MASKING FOR WRITING ON REGISTER*/
/***************************MACRO DECLERATION END**************************/

/***************************MACRO FUNCTIONS  START*************************/

/***************************MACRO FUNCTIONS  END***************************/

/***************************DATA  TYPE START*******************************/
typedef enum
{
NVIC_GROUP_PRI_1=3,  /*16 group and 0 subgroup*/
NVIC_GROUP_PRI_2=4,  /*8 group and 2 subgroup*/
NVIC_GROUP_PRI_3=5,  /*4 group and 4 subgroup*/
NVIC_GROUP_PRI_4=6,  /*2 group and 8 subgroup*/
NVIC_GROUP_PRI_5=7,  /*0 group and 16 subgroup*/
}NVIC_SCB_PRIGROUP_T;

typedef struct
{
volatile u32 AIRCR;

}SCB_REG_T;
#define SCB_REG ((volatile SCB_REG_T *)(AIRCR_ADDRESS))

/***************************DATA  TYPE END*********************************/

/***************************FUNCTION DECLERATION START*********************/
Std_ReturnType SCB_INIT_GROUP_PRIORITY(NVIC_SCB_PRIGROUP_T EnCpy_PRIGROUP );
u32 SCB_GET_GROUP_PRIORITY(void);

/***************************FUNCTION DECLERATION END***********************/

#endif /* NVIC_SCB_H_ */
