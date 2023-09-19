#ifndef MRCC_REGISTER_H
#define MRCC_REGISTER_H

/***********include section***********/


/*Register BaseAddress*/
//RCC  0x4002 3800
//AHB1 0x00020000
//PERIPHERAL  0x4000 0000
//FLASH 0x0000 0000
/***************macro decleration*****************/
#define RCC_CR_OFFSET   0x00
#define RCC_PLLCFGR_OFFSET     0x04
#define RCC_CFGR_OFFSET        0x08

#define MRCC_BASE_ADDRESS  	(0x40023800)


//define each register with the corresponding address

/*RCC clock control register*/
#define RCC_CR   	  (*(volatile u32*)(MRCC_BASE_ADDRESS+RCC_CR_OFFSET))
/* Bit 25 PLLRDY: Main PLL (PLL) clock ready flag*/
#define PLLRDY 25
#define RCC_PLL_READ_FLAG()     GET_BIT(RCC_CR,PLLRDY)


/*24 Main PLL (PLL) enable*/




#define PLLON  24
#define RCC_MAIN_PLL_ENABLE()      SET_BIT(RCC_CR,PLLON)
#define RCC_MAIN_PLL_CLEAR() 	   CLEAR_BIT(RCC_CR,PLLON)

/*Bit 18 HSEBYP: HSE clock bypass*/
#define HSEBYP  18
#define RCC_HSE_EXTERNAL_CERAMIC_CLOCK()  CLEAR_BIT(RCC_CR,HSEBYP)
#define RCC_HSE_EXTERNAL_USER_CLOCK_ENABLE()   SET_BIT(RCC_CR,HSEBYP)


/*Bit 17 HSERDY: HSE clock ready flag */
#define HSERDY 17
#define RCC_READ_HSE_STATE()              GET_BIT(RCC_CR,HSERDY)
#define RCC_HSE_NOTREADY  0
#define RCC_HSE_READY     1


/*Bit 16 HSEON: HSE clock enable*/
#define HSEON   16
#define RCC_HSE_DISABLE()   			 CLEAR_BIT(RCC_CR,HSEON)
#define RCC_HSE_ENABLE()   			 	 SET_BIT(RCC_CR,HSEON)


/*Bit 1 HSIRDY: Internal high-speed clock ready flag */
#define HSIRDY  1
#define RCC_READ_HSI_STATE()              GET_BIT(RCC_CR,HSIRDY)
#define RCC_HSI_NOTREADY  0
#define RCC_HSI_READY     1

/*Bit 0 HSION: Internal high-speed clock enable */
#define HSION   0
#define RCC_HSI_DISABLE()   			 CLEAR_BIT(RCC_CR,HSION)
#define RCC_HSI_ENABLE()   			 	 SET_BIT(RCC_CR,HSION)





/*RCC PLL configuration register*/
#define RCC_PLLCFGR   (*(volatile u32*)(MRCC_BASE_ADDRESS+RCC_PLLCFGR_OFFSET))

#define PLLQ_BITS       15
#define PLLQ_BITS_POS   24
#define PLLQ_BIT_MASK   (PLLQ_BITS<<PLLQ_BITS_POS)

#define PLLP_BITS       3
#define PLLP_BITS_POS   16
#define PLLP_BIT_MASK   (PLLP_BITS<<PLLP_BITS_POS)



#define PLLSRC 	 22

#define RCC_ENABLE_HSI_AS_PLL_SOURCE()    CLEAR_BIT(RCC_PLLCFGR,PLLSRC)
#define RCC_ENABLE_HSE_AS_PLL_SOURCE()    SET_BIT(RCC_PLLCFGR,PLLSRC)

/***********PLLN MULTIPLICATION FACTOR*****************/
#define PLLN_BITS       511
#define PLLN_BITS_POS   6
#define PLLN_BIT_MASK   (PLLN_BITS<<PLLN_BITS_POS)
/***********PLL M MULTIPLICATION FACTOR*****************/
#define PLLM_BITS       63
#define PLLM_BITS_POS   0
#define PLLM_BIT_MASK   (PLLN_BITS<<PLLN_BITS_POS)

/*RCC PLL configuration register*/
#define RCC_CFGR      (*(volatile u32*)(MRCC_BASE_ADDRESS+RCC_CFGR_OFFSET))
/*Bits 15:13 PPRE2: APB high-speed prescaler (APB2) */

/*AHB PRESCALER 4:7*/
#define AHB_BITS       15
#define AHB_BITS_POS   4
#define AHB_BIT_MASK   (AHB_BITS<<AHB_BITS_POS)



/*RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)*/
#define RCC_AHB1ENR_OFFSET  0x30
#define RCC_AHB1ENR      (*(volatile u32*)(MRCC_BASE_ADDRESS+RCC_AHB1ENR_OFFSET))


/*RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)*/
#define RCC_AHB2ENR_OFFSET  0x34
#define RCC_AHB2ENR      (*(volatile u32*)(MRCC_BASE_ADDRESS+RCC_AHB2ENR_OFFSET))

/*RCC APB1 peripheral clock enable register (RCC_APB1ENR)*/
#define RCC_APB1ENR_OFFSET 0x40
#define RCC_APB1ENR      (*(volatile u32*)(MRCC_BASE_ADDRESS+RCC_APB1ENR_OFFSET))


/*RCC APB2 peripheral clock enable register*/
#define RCC_APB2ENR_OFFSET  0x44
#define RCC_APB2ENR      (*(volatile u32*)(MRCC_BASE_ADDRESS+RCC_APB2ENR_OFFSET))





#endif //MRCC_REGISTER_H
