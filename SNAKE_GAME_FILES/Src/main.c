/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Karim_Zidan
 * @brief          : Main program body
 ******************************************************************************
 */
#include <stdint.h>
#include <string.h>
#include<stdlib.h>
#include"common/STD_TYPES.h"
#include "common/BIT_MATH.h"
#include"CORE_NVIC_INTERFACE.h"
#include"NVIC_SCB.h"
#include"CORE_NVIC_REGISTER.h"
#include"MEXT_INT.h"
#include"DIO/MDIO_INTERFACE.h"
#include"RCC/MRCC_interface.h"
#include"MEXT_REGISTER.h"
#include"HAL_7_SEG.h"
#include"HAL_LED.h"
#include"HAL_IR.h"
#include"main.h"

#define ROW_MAX_NUMBERS  6
#define COLUMN_MAX_NUMBERS 8
#define SNAKE_HEAD  0
/******************flags******************/
u8 GAME_OVER[6]={0x00,0x00,0x00,0x00,0x00,0x00};
/***FEEDING STATE***/
typedef enum
{
	SNAKE_ATE,
	SNAKE_NOT_EAT
}SNAKE_STATE;
SNAKE_STATE SNAKE_FEEDING_STATE=SNAKE_NOT_EAT;
/***FEEDING STATE***/
/***COLLISION STATE***/
typedef enum
{
	COLLSION_HAPPEN,
	NO_COLLISION
}SNAKE_COLLISION_STATE;
SNAKE_COLLISION_STATE snake_collision=NO_COLLISION;
/***COLLISION STATE***/
u8 TobeDisplayed[ROW_MAX_NUMBERS];
snack snake_test;
u8 counter=0;
int main(void)
{
	/***init the rcc***/
	/* Loop forever */
	App_Init();
	snake_init_game();
	while(1)
	{

		check_collision();
		if(snake_collision==NO_COLLISION)
		{
			Update_snack();
			for(u8 i =0 ; i <10 ; i++)
			{
				Display_LED_MATRIX_Frame(TobeDisplayed, ROW_MAX_NUMBERS, COLUMN_MAX_NUMBERS);
			}

			CHECK_SNAKE_FEED();
			if(SNAKE_FEEDING_STATE==SNAKE_ATE)
			{
				generate_feed();
			}
		}
		else if(snake_collision==COLLSION_HAPPEN)
		{
			for(u8 i =0 ; i <15 ; i++)
			{
				Display_GAME_OVER();
			}
			snake_init_game();
		}
	}
}

void Update_snack(void)
{
	Snake_body_Shift();
	memset(TobeDisplayed,0x00,sizeof(TobeDisplayed));
	Direction_Check();
	for(int x=0; x <snake_test.snake_length;x++)
	{
		TobeDisplayed[snake_test.Snack_body[x].R_POS]|=(1<<snake_test.Snack_body[x].C_POS);
		TobeDisplayed[snake_test.snack_feed.R_POS]|=(1<<snake_test.snack_feed.C_POS);
	}
	for (int i = 0; i < ROW_MAX_NUMBERS; i++) {
		TobeDisplayed[i] = ~TobeDisplayed[i];
	}
}

void Direction_Check(void)
{
	if(READED_DATA==0x46)
	{
		snake_test.Direction_state=UP;
	}
	else if(READED_DATA==0x15)
	{
		snake_test.Direction_state=DOWN;
	}
	else if(READED_DATA==0x44)
	{
		snake_test.Direction_state=LEFT;
	}
	else if(READED_DATA==0x43)
	{
		snake_test.Direction_state=RIGHT;
	}
	else
	{

	}

	switch(snake_test.Direction_state)
	{
	case UP :(snake_test.Snack_body[0].R_POS)--;
	if(snake_test.Snack_body[SNAKE_HEAD].R_POS==-1)
	{
		snake_test.Snack_body[SNAKE_HEAD].R_POS=5;
	}
	break;
	case DOWN: (snake_test.Snack_body[SNAKE_HEAD].R_POS)++;
	if(snake_test.Snack_body[SNAKE_HEAD].R_POS==6)
	{
		snake_test.Snack_body[SNAKE_HEAD].R_POS=0;
	}
	break;
	case RIGHT:(snake_test.Snack_body[SNAKE_HEAD].C_POS)++;
	if(snake_test.Snack_body[SNAKE_HEAD].C_POS==8)
	{
		snake_test.Snack_body[SNAKE_HEAD].C_POS=0;
	}
	break;
	case LEFT :(snake_test.Snack_body[SNAKE_HEAD].C_POS)--;
	if(snake_test.Snack_body[SNAKE_HEAD].C_POS==-1)
	{
		snake_test.Snack_body[SNAKE_HEAD].C_POS=7;
	}
	break;
	default :break;
	}
}
void ADD_TAIL(void)
{
	snake_test.snake_length++;
	snake_test.Snack_body[snake_test.snake_length-1].C_POS=snake_test.Snack_body[snake_test.snake_length-2].C_POS;
	snake_test.Snack_body[snake_test.snake_length-1].R_POS=snake_test.Snack_body[snake_test.snake_length-2].R_POS;
}
void Snake_body_Shift(void)
{
	u8 i;
	for( i=snake_test.snake_length-1 ;i>0;i--)
	{
		snake_test.Snack_body[i].C_POS=snake_test.Snack_body[i-1].C_POS;
		snake_test.Snack_body[i].R_POS=snake_test.Snack_body[i-1].R_POS;
	}
}
void generate_feed(void)
{
	snake_test.snack_feed.C_POS=rand()%8;
	snake_test.snack_feed.R_POS=rand()%6;
	for(u8 i =0;i<snake_test.snake_length-1;i++)
	{
		if((snake_test.snack_feed.C_POS==snake_test.Snack_body[i].C_POS)||(snake_test.snack_feed.R_POS==snake_test.Snack_body[i].R_POS))
		{
			generate_feed();
			break;
		}
	}
	SNAKE_FEEDING_STATE=SNAKE_NOT_EAT;

}
void check_collision(void)
{
	for(u8 i =1; i < snake_test.snake_length-1;i++)
	{
		if((snake_test.Snack_body[SNAKE_HEAD].C_POS==snake_test.Snack_body[i].C_POS)&&(snake_test.Snack_body[SNAKE_HEAD].R_POS==snake_test.Snack_body[i].R_POS))
		{
			snake_collision=COLLSION_HAPPEN;
			break;
		}
	}
}
void snake_init_game(void)
{
	snake_test.Direction_state=RIGHT;
	snake_test.Snack_body[SNAKE_HEAD].C_POS=0;
	snake_test.Snack_body[SNAKE_HEAD].R_POS=0;
	snake_test.snack_feed.C_POS=7;
	snake_test.snack_feed.R_POS=5;
	snake_test.snake_length=1;
	snake_collision=NO_COLLISION;
	SNAKE_FEEDING_STATE=SNAKE_NOT_EAT;
}
void CHECK_SNAKE_FEED(void)
{
	if((snake_test.Snack_body[SNAKE_HEAD].C_POS==snake_test.snack_feed.C_POS)&&(snake_test.Snack_body[SNAKE_HEAD].R_POS==snake_test.snack_feed.R_POS))
	{
		SNAKE_FEEDING_STATE=SNAKE_ATE;
		ADD_TAIL();
	}
}
void App_Init(void)
{
	MRCC_VoidInitSystemClock();
	MSYSTICK_VoidInit();
	MRCC_VoidEnablePeripheral(RCC_AHB1_BUS,GPIOB_CTRL_PIN );
	MRCC_VoidEnablePeripheral(RCC_AHB1_BUS,GPIOA_CTRL_PIN );
	MRCC_VoidEnablePeripheral(RCC_APB2_BUS,SYSCFG_CTRL_PIN );

	INIT_LEDMATRIX();
	MGPIO_voidSetPinInput(GPIO_PORTB, GPIO_PIN6, GPIO_OSPEED_LOW, GPIO_MODE_INPUT, GPIO_PUPD_PULL_UP);
	MEXTI_voidSetSenseControl(MEXTI_LINE06, MEXTI_SENSE_FALLING_EDGE);
	MEXTI_voidSelectPortToLine(MEXTI_LINE06, MEXTI_PORT_LINE_B);
	MEXTI_SETCALLBACK(IR_HANDLER, MEXTI_LINE06);
	MEXTI_voidInterruptEnable(MEXTI_LINE06);
	NVIC_EnableIRQ(EXTI9_5);

}
void BUTTON_HANDLER(void)
{
	if(snake_test.Direction_state==RIGHT)
	{
		snake_test.Direction_state=DOWN;
	}
	else if(snake_test.Direction_state==DOWN)
	{
		snake_test.Direction_state=RIGHT;
	}
	else
	{

	}

}
void Display_GAME_OVER(void)
{
	Display_LED_MATRIX_Frame(GAME_OVER, ROW_MAX_NUMBERS, COLUMN_MAX_NUMBERS);

}
