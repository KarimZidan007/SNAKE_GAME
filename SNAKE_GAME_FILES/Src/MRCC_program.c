#include"common/STD_TYPES.h"
#include"common/BIT_MATH.h"

#include"RCC/MCC_private.h"
#include"RCC/MRCC_CONFIG.h"
#include"RCC/MCC_Register.h"
#include"RCC/MRCC_interface.h"
/***
 * @brief this function is used to initialize system clock
 */
void MRCC_VoidInitSystemClock(void)
{
	/*CONFIGURE THE SELECTED CLOCK SOURCE*/
#if RCC_CLOCK_SOURCE_TYPE==HSI_CLOCK_SOURCE

	RCC_HSI_ENABLE();
	//wait until HSI CLOCK IS READY
	while(RCC_READ_HSI_STATE()==NOT_READY);


#elif RCC_CLOCK_SOURCE_TYPE==HSE_CLOCK_SOURCE

	switch(HSE_CLOCK_SIGNAL_GENERATOR)
	{
	case HSE_EXTERNAL_CRYSTAL_CERAMIC_RESENATOR_CLOCK_SIGNAL:
		RCC_HSE_EXTERNAL_CERAMIC_CLOCK();
		break;
	case HSE_EXTERNAL_USER_CLOCK_SIGNAL:
		RCC_HSE_EXTERNAL_USER_CLOCK_ENABLE();
		break;
	default:break;
	}
	/*enable HSE CLOCK SOURCE*/
	RCC_HSE_ENABLE();
	//wait until HSI CLOCK IS READY
	while(RCC_READ_HSE_STATE()==NOT_READY);



#elif RCC_CLOCK_SOURCE_TYPE==PLL_HSI_CLOCKED_PLL
	/*PLL CNFGS*/
	/*REGISTER IS -> RCC_PLLCFGR*/

	/*P division factor*/
	//	PLLP_BITS_POS
	//	PLLP_BIT_MASK
	//PLL_P_DIVISION_FACTOR
	MODIFY_REG(RCC_PLLCFGR,PLLP_BIT_MASK,PLL_P_DIVISION_FACTOR,PLLP_BITS_POS);

	/*N division factor*/
	//value -> N_MULTIPLICATION_FACTOR
	//	PLLN_BITS_POS
	//	PLLN_BIT_MASK
	MODIFY_REG(RCC_PLLCFGR,PLLN_BIT_MASK,PLL_N_MULTIPLICATION_FACTOR,PLLN_BITS_POS);

	/*M division factor*/
	//	PLLM_BITS_POS
	//	PLLM_BIT_MASK
	//value -> PLL_M_DIVISION_FACTOR
	MODIFY_REG(RCC_PLLCFGR,PLLM_BIT_MASK,PLL_M_DIVISION_FACTOR,PLLM_BITS_POS);


	RCC_HSI_ENABLE();
	while(RCC_READ_HSI_STATE()==NOT_READY);

	RCC_ENABLE_HSI_AS_PLL_SOURCE();
	RCC_MAIN_PLL_ENABLE();
	while(RCC_PLL_READ_FLAG()==NOT_READY);

#elif RCC_CLOCK_SOURCE_TYPE==PLL_HSE_CLOCKED_PLL
	/*PLL CNFGS*/
	/*REGISTER IS -> RCC_PLLCFG*/

	/*P division factor*/
	//	PLLP_BITS_POS
	//	PLLP_BIT_MASK
	//PLL_P_DIVISION_FACTOR
	MODIFY_REG(RCC_PLLCFGR,PLLP_BIT_MASK,PLL_P_DIVISION_FACTOR,PLLP_BITS_POS);

	/*N division factor*/
	//	value -> N_MULTIPLICATION_FACTOR
	//	PLLN_BITS_POS
	//	PLLN_BIT_MASK
	MODIFY_REG(RCC_PLLCFGR,PLLN_BIT_MASK,PLL_N_MULTIPLICATION_FACTOR,PLLN_BITS_POS);

	/*M division factor*/
	//	PLLM_BITS_POS
	//	PLLM_BIT_MASK
	//value -> PLL_M_DIVISION_FACTOR
	MODIFY_REG(RCC_PLLCFGR,PLLM_BIT_MASK,PLL_M_DIVISION_FACTOR,PLLM_BITS_POS);

	RCC_HSE_ENABLE();
	//wait until HSI CLOCK IS READY
	while(RCC_READ_HSE_STATE()==NOT_READY);
	RCC_ENABLE_HSE_AS_PLL_SOURCE();
	RCC_MAIN_PLL_ENABLE();
	while(RCC_PLL_READ_FLAG()==NOT_READY);

#else
#error "WRONG RCC CLOCK CNFG"
#endif

	/*SELECT PRESCALERS*/
	/* REG -> RCC_CFGR
	 * POS -> AHB_BITS_POS
	 * MASKS->AHB_BIT_MASK
	 * VAL ->RCC_AHB_PRESCALER
	 */
	MODIFY_REG(RCC_CFGR,AHB_BIT_MASK,RCC_AHB_PRESCALER,AHB_BITS_POS);
	/*ENABLE SELECTED CLOCK SOURCE*/
}
void MRCC_VoidEnablePeripheral(u8 Bus, u8 bit)
{
	//ahp1 ,ahp2,apb1,1apb2
	switch(Bus)
	{
	case 1:SET_BIT(RCC_AHB1ENR,bit);
	break;
	case 2:SET_BIT(RCC_AHB2ENR,bit);
	break;
	case 3:SET_BIT(RCC_APB1ENR,bit);
	break;
	case 4:SET_BIT(RCC_APB2ENR,bit);
	break;
	}
}
void MRCC_VoidDisablePeripheral(u8 Bus, u8 bit)
{
	//ahp1 ,ahp2,apb1,1apb2
	switch(Bus)
	{
	case 1:CLEAR_BIT(RCC_AHB1ENR,bit);
	break;
	case 2:CLEAR_BIT(RCC_AHB2ENR,bit);
	break;
	case 3:CLEAR_BIT(RCC_APB1ENR,bit);
	break;
	case 4:CLEAR_BIT(RCC_APB2ENR,bit);
	break;
	}


}