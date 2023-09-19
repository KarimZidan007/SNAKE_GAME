#ifndef MRCC_PRIVATE_H
#define MRCC_PRIVATE_H
/*IMPLEMENTATION SPECIFIC*/
#define NOT_READY 0
#define READY     1


/*CONFIGURATION PARAMETERS*/

#define HSI_CLOCK_SOURCE     (0x01)
#define HSE_CLOCK_SOURCE     (0x02)
#define PLL_HSI_CLOCKED_PLL  (0x03)
#define PLL_HSE_CLOCKED_PLL  (0x04)




#define HSE_EXTERNAL_CRYSTAL_CERAMIC_RESENATOR_CLOCK_SIGNAL    (1)
#define HSE_EXTERNAL_USER_CLOCK_SIGNAL 						   (2)

/***************PLL Q DIV FACTOR**************/

#define PLLQ_DIV_2   2
#define PLLQ_DIV_3   3
#define PLLQ_DIV_4	 4
#define PLLQ_DIV_5	 5
#define PLLQ_DIV_6   6
#define PLLQ_DIV_7   7
#define PLLQ_DIV_8   8
#define PLLQ_DIV_9   9
#define PLLQ_DIV_10  10
#define PLLQ_DIV_11  11
#define PLLQ_DIV_12  12
#define PLLQ_DIV_13  13
#define PLLQ_DIV_14  14
#define PLLQ_DIV_15  15
/************PLL P DIV************/
#define PLLP_DIV_2        0b00
#define PLLP_DIV_4        0b01
#define PLLP_DIV_6		  0b10
#define PLLP_DIV_8		  0b11
/************PLL P DIV************/

/***************AHB CNFG**************/
#define SYSTEM_CLOCK_NOT_DIVIDED      0b0000
#define SYSTEM_CLOCK_DIV_002		  0b1000
#define SYSTEM_CLOCK_DIV_004   		  0b1001
#define SYSTEM_CLOCK_DIV_008          0b1010
#define SYSTEM_CLOCK_DIV_016		  0b1011
#define SYSTEM_CLOCK_DIV_064		  0b1100
#define SYSTEM_CLOCK_DIV_128		  0b1101
#define SYSTEM_CLOCK_DIV_256		  0b1110
#define SYSTEM_CLOCK_DIV_512		  0b1111

/*****************APB's CNFGS******************/
#define AHB_CLOCK_NOT_DIVIDED         0b000
#define AHB_CLOCK_DIV_02			  0b100
#define AHB_CLOCK_DIV_04			  0b101
#define AHB_CLOCK_DIV_08			  0b110
#define AHB_CLOCK_DIV_16              0b111

#endif //MRCC_PRIVATE_H
