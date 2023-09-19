#include"common/STD_TYPES.h"
#include"common/BIT_MATH.h"
#include"DIO/MDIO_PRIVATE.h"
#include"DIO/MDIO_CNFG.h"
#include"DIO/MDIO_REGISTER.h"
#include"DIO/MDIO_INTERFACE.h"

volatile GPIO_T * GPIO_REGISTERS[3] ={GPIOA_REGISTERS,GPIOB_REGISTERS,GPIOC_REGISTERS};

/***
 * @brief this function is used to set pin mode (input,out,alternative,analog)
 */
void MGPIO_voidSetPinMode(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T PinNo,EN_GPIO_MODE_T Mode)
{
	MODIFY_REG(GPIO_REGISTERS[PortNo]->GPIO_MODER,(MASKING_TWO_BITS<<(PinNo*2)),Mode,(PinNo*2));
}
/***
 * @brief this function is used to set the output type of a function (PUSHPULL,OPENDRAIN)
 */
void MGPIO_voidSetPinOType(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T PinNo,EN_GPIO_OTYPE_T Otype)
{

	MODIFY_REG(GPIO_REGISTERS[PortNo]->GPIO_OTYPER,(MASKING_ONE_BITS<<PinNo),Otype,PinNo);
}
/**
 *@brief this function is used to set pin output speed
 */
void MGPIO_voidSetPinOSpeed(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T PinNo,EN_GPIO_OSPEED_T OSpeed)
{

	MODIFY_REG(GPIO_REGISTERS[PortNo]->GPIO_OSPEEDR,(MASKING_TWO_BITS<<(PinNo*2)),OSpeed,(PinNo*2));
}
/**
 * @brief this function is used to set the input configuration of pin (pull up or pull down)
 */
void MGPIO_voidSetPinPUPD(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T PinNo,EN_GPIO_PUPD_T PUPD)
{

	MODIFY_REG(GPIO_REGISTERS[PortNo]->GPIO_PUPDR,(MASKING_TWO_BITS<<(PinNo*2)),PUPD,(PinNo*2));
}
/**
 * @brief this function is used to get the pin value
 */
void MGPIO_voidGetPinValue(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T PinNo,EN_GPIO_LOGICLEVEL_T *Value)
{

	*Value=GET_BIT((GPIO_REGISTERS[PortNo]->GPIO_IDR),PinNo);
}
/***
 * @brief this function is used to set the output logic of a function (HIGH,LOW)
 */
void MGPIO_voidSetPinValue(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T PinNo,EN_GPIO_LOGICLEVEL_T Value)
{

	MODIFY_REG(GPIO_REGISTERS[PortNo]->GPIO_ODR,(MASKING_ONE_BITS<<PinNo),Value,PinNo);
}
/***
 * @brief this function is used to set the ouput cnfg of pin Mode(OUTPUT),(PUSHPULL-OPENDRAIN),(OUTSPEED)
 */
void MGPIO_voidSetPinOutput(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T PinNo,EN_GPIO_OSPEED_T OSpeed,EN_GPIO_OTYPE_T Otype,EN_GPIO_PUPD_T PUPD)
{
	MGPIO_voidSetPinMode(PortNo, PinNo, GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinOType(PortNo, PinNo, Otype);
	MGPIO_voidSetPinOSpeed(PortNo, PinNo, OSpeed);
	MGPIO_voidSetPinPUPD(PortNo, PinNo, PUPD);
}
/***
 * @brief this function is used to set the ouput cnfg of pin Mode(INPUT),(PULLUP-PULLDOWN),(SAMPLESPEED)
 *
 */
void MGPIO_voidSetPinInput(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T PinNo,EN_GPIO_OSPEED_T OSpeed,EN_GPIO_MODE_T Mode,EN_GPIO_PUPD_T PUPD)
{
	MGPIO_voidSetPinMode(PortNo, PinNo, Mode);
	MGPIO_voidSetPinPUPD(PortNo, PinNo, PUPD);
	MGPIO_voidSetPinOSpeed(PortNo, PinNo, OSpeed);
}
/**
 * @brief this function is used to set a specific value on a specific number of bits
 */
void MGPIO_WRITE_NUMBER_OF_BITS(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T Start_Bit,u8 Masked_val_of_Bits,u32 Value)
{
	MODIFY_REG(GPIO_REGISTERS[PortNo]->GPIO_ODR,(Masked_val_of_Bits<<Start_Bit),Value,Start_Bit);
}
/***
 * @brief this function is used to toggle bit
 *
 */
void MGPIO_voidTogglePinValue(EN_GPIO_PORT_NO_T PortNo,EN_GPIO_PIN_NO_T PinNo)
{
    TOGGLE_BIT(GPIO_REGISTERS[PortNo]->GPIO_ODR,PinNo);
}
