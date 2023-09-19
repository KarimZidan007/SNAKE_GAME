#ifndef MDIO_REGISTER_H
#define MDIO_REGISTER_H

/*****************base address*********************/
#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOB_BASE_ADDRESS 0x40020400
#define GPIOC_BASE_ADDRESS 0x40020800

/**************************data type section**********************/
typedef struct
{
volatile u32 GPIO_MODER;
volatile u32 GPIO_OTYPER;
volatile u32 GPIO_OSPEEDR;
volatile u32 GPIO_PUPDR;
volatile u32 GPIO_IDR;
volatile u32 GPIO_ODR;
volatile u32 GPIO_BSRR;
volatile u32 GPIO_LCKR;
volatile u32 GPIO_AFRL;
volatile u32 GPIO_AFRH;
}GPIO_T;

#define GPIOA_REGISTERS       ((volatile GPIO_T *)(GPIOA_BASE_ADDRESS))

#define GPIOB_REGISTERS       ((volatile GPIO_T *)(GPIOB_BASE_ADDRESS))

#define GPIOC_REGISTERS       ((volatile GPIO_T *)(GPIOC_BASE_ADDRESS))


#endif //MDIO_REGISTER_H
