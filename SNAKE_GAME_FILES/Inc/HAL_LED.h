/*
 * HAL_LED.h
 *
 *  Created on: Sep 8, 2023
 *      Author: m
 */

#ifndef HAL_LED_H_
#define HAL_LED_H_

void Write_Number_Of_Leds(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T Start_Led,u8 Max_Val_of_Leds,u32 Value);
void Display_Animation(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T Start_Led,u8 Max_Val_of_Leds,u32 Animation,u8 number_of_Leds);
void LEDMATRIX_DISPLAYFRAME(u8 *ptr,u8 row ,u8 column);


#endif /* HAL_LED_H_ */
