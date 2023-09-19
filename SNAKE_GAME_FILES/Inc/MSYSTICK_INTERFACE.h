/*
 * MSYSTICK_INTERFACE.h
 *
 *  Created on: Sep 14, 2023
 *      Author: karim
 */

#ifndef MSYSTICK_INTERFACE_H_
#define MSYSTICK_INTERFACE_H_

#define FLAG_NOT_READY   0

#define SYS_ENABLE       1
#define SYS_DISABLE      0





void MSYSTICK_VoidInit();
void MSYSTICK_VoidSetBusyWaitDelay(u32 Time_Ticks);
void MSYSTICK_VoidIntervalSingle(u32 Time_Ticks,void(*notification)(void));
void MSYSTICK_VoidIntervalPeriodic(u32 Time_Ticks,void(*notification)(void));
void MSYSTICK_VoidTimerStop();
void MSYSTICK_VoidGetElapsedTime(u32 *P_Read_var);
void MSYSTICK_VoidGetRemaningTime(u32 *P_Read_var);

#endif /* MSYSTICK_INTERFACE_H_ */
