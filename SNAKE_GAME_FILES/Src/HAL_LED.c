/*
 * HAL_LED.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Zidan
 */
/****************************************include section****************************************/
#include"common/STD_TYPES.h"
#include"common/BIT_MATH.h"
#include"DIO/MDIO_INTERFACE.h"
#include"HAL_LED_CNFG.h"
#include"HAL_LED.h"
/****************************************include section****************************************/

/*different Animations for sequental leds*/
u8 Animation_One[7]={0b1000000,0b0100000,0b0010000,0b0001000,0b0000100,0b0000010,0b0000001};
u8 Animation_Two[4]={0b1000001,0b0100010,0b0010100,0b0001000};
u8 Animation_Three[4]={0b0001000,0b0010100,0b0100010,0b1000001};
u8 LED_MATRIX_ROW_PORT[6]={GPIO_PORTB,GPIO_PORTB,GPIO_PORTB,GPIO_PORTB,GPIO_PORTB,GPIO_PORTB};
u8 LED_MATRIX_COLUMN_PORT[8]={GPIO_PORTA,GPIO_PORTA,GPIO_PORTA,GPIO_PORTA,GPIO_PORTA,GPIO_PORTA,GPIO_PORTA,GPIO_PORTA};
u8 ROW_VAL[6]={0b000001,0b000010,0b000100,0b001000,0b010000,0b100000};

/**************************************************************************************************************************************/




/*******************************************************LED MATRIX API's***********************************************/
//snack snack1;
//
//void LEDMATRIX_DISPLAYFRAME(u8 *ptr,u8 row ,u8 column)
//{
//	snack1.Direction_state=Y;
//	snack1.Snack_Length=3;    // snack length
//	snack1.Position.Y_POS=(1<<snack1.Snack_Length)-1; // data on row (snack start data on ORGIN)
//	snack1.Position.X_POS=0b11111110;  // ctrl pin (ORGIN OF X)
//	u8 i=0;
//	u8 shift_y_x=0;
//	while(snack1.Direction_state==Y)
//	{
//		i++;
//		if(i==6)
//		{
//			i=0;
//		}
//		MGPIO_WRITE_NUMBER_OF_BITS(GPIO_PORTA, 0, MASKING_EIGHT_BITS, 0b11111110);// X here is a CTRL
//
//		MGPIO_WRITE_NUMBER_OF_BITS(GPIO_PORTB, 0, MASKING_SIX_BITS,snack1.Position.Y_POS); // Y here is the data(snack length)
//
//		for(int d=0;d<2000;d++)
//		{
//
//			asm("NOP");
//		}
//		MGPIO_WRITE_NUMBER_OF_BITS(LED_MATRIX_ROW_PORT[i], 0, MASKING_EIGHT_BITS, 0x00);
//
//		MGPIO_WRITE_NUMBER_OF_BITS(LED_MATRIX_COLUMN_PORT[i], 0, MASKING_SIX_BITS, 0x00);
//		snack1.Position.Y_POS=CIRCULAR_SHIFTING(snack1.Position.Y_POS,1,6);
//
//
//
//	}
//	while(snack1.Direction_state==X)
//	{
//
//		if(shift_y_x<snack1.Snack_Length-1)
//		{
//			u8 L_temp=0;
//			L_temp=(2<<snack1.Snack_Length);
//			snack1.Position.Y_POS&=~L_temp;
//			snack1.Position.X_POS=(snack1.Position.X_POS<<1);
//			shift_y_x++;
//
//			Display_LED_MATRIX_Frame(snack1.Position.Y_POS, 6, 8);
//
//
//		}
//		i++;
//		if(i==8)
//		{
//			i=0;
//		}
//
//		MGPIO_WRITE_NUMBER_OF_BITS(GPIO_PORTA, 0, MASKING_EIGHT_BITS,0b11111100);// data
////		MGPIO_WRITE_NUMBER_OF_BITS(GPIO_PORTA, 0, MASKING_EIGHT_BITS,snack1.Position.X_POS);// data
//
////		MGPIO_WRITE_NUMBER_OF_BITS(GPIO_PORTB, 0, MASKING_SIX_BITS,0b110000 );//ctrl
////		MGPIO_WRITE_NUMBER_OF_BITS(GPIO_PORTB, 0, MASKING_EIGHT_BITS,snack1.Position.Y_POS<<i );//ctrl
//		MGPIO_voidSetPinValue(GPIO_PORTB, LED_COL1_PIN+i, (snack1.Position.Y_POS>>i)&0x01);
//		for(int d=0;d<2000;d++)
//		{
//
//			asm("NOP");
//		}
//		if(shift_y_x>=snack1.Snack_Length-1)
//		{
//			snack1.Position.X_POS=CIRCULAR_SHIFTING(snack1.Position.X_POS,1,8);
//
//		}
//
//
//
//
//	}
//}
/**************************************************************************************************************************************/

void INIT_LEDMATRIX(void)
{

	MGPIO_voidSetPinOutput(LED_ROW1_PORT, LED_ROW1_PIN, GPIO_OSPEED_VERY_HIGH, GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_DOWN);
	MGPIO_voidSetPinOutput(LED_ROW2_PORT, LED_ROW2_PIN, GPIO_OSPEED_VERY_HIGH, GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_DOWN);
	MGPIO_voidSetPinOutput(LED_ROW3_PORT, LED_ROW3_PIN, GPIO_OSPEED_VERY_HIGH, GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_DOWN);
	MGPIO_voidSetPinOutput(LED_ROW4_PORT, LED_ROW4_PIN, GPIO_OSPEED_VERY_HIGH, GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_DOWN);
	MGPIO_voidSetPinOutput(LED_ROW5_PORT, LED_ROW5_PIN, GPIO_OSPEED_VERY_HIGH, GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_DOWN);
	MGPIO_voidSetPinOutput(LED_ROW6_PORT, LED_ROW6_PIN, GPIO_OSPEED_VERY_HIGH, GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_DOWN);



	MGPIO_voidSetPinOutput(LED_COL1_PORT, LED_COL1_PIN, GPIO_OSPEED_VERY_HIGH,  GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_UP);
	MGPIO_voidSetPinOutput(LED_COL2_PORT, LED_COL2_PIN, GPIO_OSPEED_VERY_HIGH,  GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_UP);
	MGPIO_voidSetPinOutput(LED_COL3_PORT, LED_COL3_PIN, GPIO_OSPEED_VERY_HIGH,  GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_UP);
	MGPIO_voidSetPinOutput(LED_COL4_PORT, LED_COL4_PIN, GPIO_OSPEED_VERY_HIGH,  GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_UP);
	MGPIO_voidSetPinOutput(LED_COL5_PORT, LED_COL5_PIN, GPIO_OSPEED_VERY_HIGH,  GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_UP);
	MGPIO_voidSetPinOutput(LED_COL6_PORT, LED_COL6_PIN, GPIO_OSPEED_VERY_HIGH,  GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_UP);
	MGPIO_voidSetPinOutput(LED_COL7_PORT, LED_COL7_PIN, GPIO_OSPEED_VERY_HIGH,  GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_UP);
	MGPIO_voidSetPinOutput(LED_COL8_PORT, LED_COL8_PIN, GPIO_OSPEED_VERY_HIGH,  GPIO_OTYPE_PUSH_PULL,GPIO_PUPD_PULL_UP);

}

/**************************************************************************************************************************************/

/***
 * @brief this function is used to write on group of sequental leds (same port )
 * @param PortNo -> ENUM TYPE look at EN_GPIO_PORT_NO_T on MGPIO_INTERFACE.h
 * @param Start_Led -> ENUM TYPE look at EN_GPIO_PIN_NO_T on MGPIO_INTERFACE.h -> the first animated led in (pin0 -> pin15)
 * @param Max_Val_of_Leds -> Masking value depend on number of leds for example 3 leds (0b111)
 * @param the total logic we want to set on the whole leds
 */
void Write_Number_Of_Leds(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T Start_Led,u8 Max_Val_of_Leds,u32 Value)
{
	MGPIO_WRITE_NUMBER_OF_BITS(PortNo, Start_Led, Max_Val_of_Leds, Value);
}
/**************************************************************************************************************************************/
/***
 * @brief this function is used to display a three different animations for sequental leds
 */
/***
 * @brief this function is used to write on group of sequental leds (same port )
 * @param PortNo -> ENUM TYPE look at EN_GPIO_PORT_NO_T on MGPIO_INTERFACE.h
 * @param Start_Led -> ENUM TYPE look at EN_GPIO_PIN_NO_T on MGPIO_INTERFACE.h -> the first animated led in (pin0 -> pin15)
 * @param Max_Val_of_Leds -> Masking value depend on number of leds for example 3 leds (0b111)
 * @param the total logic we want to set on the whole leds ->(Animation)
 * @param number of leds-> number of leds in the system
 */
void Display_Animation(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T Start_Led,u8 Max_Val_of_Leds,u32 Animation,u8 number_of_Leds)
{
	switch(Animation)
	{
	case 1 :
		for( int i =0 ; i<number_of_Leds;i++)
		{
			Write_Number_Of_Leds(PortNo, Start_Led,Max_Val_of_Leds  , Animation_One[i]);
			for(long int i =0 ; i<1000 ; i++)
			{
				asm("NOP");
			}
		}
		break;
	case 2 :
		for( int i =0 ; i<4;i++)
		{
			Write_Number_Of_Leds(PortNo, Start_Led, Max_Val_of_Leds, Animation_Two[i]);
			for(long int i =0 ; i<1000 ; i++)
			{
				asm("NOP");
			}
		}
		break;
	case 3 :
		for( int i =0 ; i<4;i++)
		{
			Write_Number_Of_Leds(PortNo, Start_Led, Max_Val_of_Leds, Animation_Three[i]);
			for(long int i =0 ; i<1000 ; i++)
			{
				asm("NOP");
			}
		}
		break;
	}
}
void Display_LED_MATRIX_Frame(u8 *ptr,u8 row ,u8 column)
{
/*Enable CTRL*/
	for(unsigned int i=0;i<row;i++)
	{
		MGPIO_voidSetPinValue(LED_MATRIX_ROW_PORT[i], LED_ROW1_PIN+i, GPIO_LOGIC_LEVEL_HIGH);//ctrl signal
		//data on columns
		MGPIO_WRITE_NUMBER_OF_BITS(LED_MATRIX_COLUMN_PORT[i], 0, MASKING_EIGHT_BITS,ptr[i]);
		//delay

		for(u16 i =0 ; i < 300 ; i++)
		{
			asm("NOP");
		}

		MGPIO_voidSetPinValue(LED_MATRIX_ROW_PORT[i], LED_ROW1_PIN+i, GPIO_LOGIC_LEVEL_LOW);//ctrl signal
	}

}
