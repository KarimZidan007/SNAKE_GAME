/*
 * main.h
 *
 *  Created on: Sep 8, 2023
 *      Author: m
 */

#ifndef MAIN_H_
#define MAIN_H_


void App_Init(void);
void EXTI0_ISR(void);
void EXTI1_ISR(void);
void BUTTON_HANDLER(void);

/***************************************/
typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}Sdirection_state;
typedef struct
{
	s8 R_POS;
	s8 C_POS;
}Snack_Point;

typedef struct
{
	Sdirection_state Direction_state;
	Snack_Point Snack_body[20];
	u8 snake_length;
	Snack_Point snack_feed;


}snack;

#endif /* MAIN_H_ */
