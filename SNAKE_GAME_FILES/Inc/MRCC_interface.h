#ifndef BIT_INTERFACE_H_
#define BIT_INTERFACE_H_

/************macro decleration*************/
#define RCC_AHB1_BUS 1
#define RCC_AHB2_BUS 2
#define RCC_APB1_BUS 3
#define RCC_APB2_BUS 4
/************macro defenation**************/
/************ data type section***********/
typedef enum
{
	GPIOA_CTRL_PIN,
	GPIOB_CTRL_PIN,
	GPIOC_CTRL_PIN,
	GPIOD_CTRL_PIN,
	GPIOE_CTRL_PIN,
	GPIOH_CTRL_PIN=7,
	CRC_CTRL_PIN=12,
	DMA1_CTRL_PIN=21,
	DMA2_CTRL_PIN=22,
}RCC_AHB1ENR_Pins;

typedef enum
{
	TIMER2_CTRL_PIN=0,
	TIMER3_CTRL_PIN,
	TIMER4_CTRL_PIN,
	TIMER5_CTRL_PIN,
	W_WDGT_CTRL_PIN=11,
	SPI2_CTRL_PIN=14,
	SPI3_CTRL_PIN,
	UART2_CTRL_PIN=17,
	I2C1_CTRL_PIN=21,
	I2C2_CTRL_PIN,
	I2C3_CTRL_PIN,
	POWER_INTERFACE_CTRL_PIN=28,
}RCC_APB1ENR_Pins;
typedef enum
{
	TIMER1_CTRL_PIN=0,
	USART1_CTRL_PIN=4,
	USART6_CTRL_PIN,
	ADC1_CTRL_PIN=8,
	SDIO_CTRL_PIN=11,
	SPI1_CTRL_PIN,
	SPI4_CTRL_PIN,
	SYSCFG_CTRL_PIN,
	TIMER9_CTRL_PIN=16,
	TIMER10_CTRL_PIN,
	TIMER11_CTRL_PIN,
}RCC_APB2ENR_Pins;

typedef union
{
	RCC_AHB1ENR_Pins RCC_AHB1_REG ;
	RCC_APB1ENR_Pins RCC_APB1_REG ;
	RCC_APB2ENR_Pins RCC_APB2_REG ;

}CLOCK_ENABLE_CNFGS;

/************function decleration*********/
void MRCC_VoidInitSystemClock(void);
void MRCC_VoidEnablePeripheral(u8 Bus, u8 bit);
void MRCC_VoidDisablePeripheral(u8 Bus, u8 bit);






#endif //BIT_INTERFACE_H_
