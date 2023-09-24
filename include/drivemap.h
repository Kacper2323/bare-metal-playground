#pragma once

#include <stdint.h>

#define AHB2_GPIO_BASE 0x48000000UL

#define GPIOA_BASE (AHB2_GPIO_BASE + 0x0000UL)
#define GPIOB_BASE (AHB2_GPIO_BASE + 0x0400UL)
#define GPIOC_BASE (AHB2_GPIO_BASE + 0x0800UL)
#define GPIOD_BASE (AHB2_GPIO_BASE + 0x0C00UL)

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
    volatile uint32_t BRR;
    volatile uint32_t ASCR;

} GPIO_Access;

#define GPIOA ((GPIO_Access *) GPIOA_BASE)
#define GPIOB ((GPIO_Access *) GPIOB_BASE)
#define GPIOC ((GPIO_Access *) GPIOC_BASE)
#define GPIOD ((GPIO_Access *) GPIOD_BASE)

// ##########################################     RCC     #########################################
#define RCC_BASE 0x40021000UL

typedef struct
{
    volatile uint32_t CR, ICSCR, CFGR, PLLCFGR, PLLSAI1CFGR, PLLSAI2CFGR, CIER, CIFR, CICR, _NONE1, AHB1RSTR, 
                      AHB2RSTR, AHB3RSTR, _NONE2, APB1RSTR1, APB1RSTR2, APB2RSTR, _NONE3, AHB1ENR, AHB2ENR,
                      AHB3ENR, _NONE4, APB1ENR1, APB1ENR2, APB2ENR, _NONE5, AHB1SMENR, AHB2SMENR, AHB3SMENR, _NONE6,
                      APB1SMENR1, APB1SMENR2, APB2SMENR, _NONE7, CCIPR, _NONE8, BDCR, CSR, CRRCR, CCIPR2;
}RCC_Access;

#define RCC ((RCC_Access *) RCC_BASE)

// ##########################################   SysTick_Map   ##########################################

#define SysTick_base 0xE000E010UL

typedef struct
{
    volatile uint32_t CTRL, LOAD, VAL, CALIB;

}SysTick_Access;

#define SysTick ((SysTick_Access *) SysTick_base)

// ######################################### USART #############################################

#define USART1_BASE 0x40013800UL
#define USART2_BASE 0x40004400UL
#define USART3_BASE 0x40004800UL
#define UART4_BASE  0x40004C00UL
#define UART5_BASE  0x40005000UL

typedef struct
{
    volatile uint32_t CR1, CR2, CR3, BRR, GTPR, RTOR, RQR, ISR, ICR, RDR, TDR;

}UART_Access;

#define UART1 ((UART_Access *) USART1_BASE)
#define UART2 ((UART_Access *) USART2_BASE)
#define UART3 ((UART_Access *) USART3_BASE)
#define UART4 ((UART_Access *) UART4_BASE)
#define UART5 ((UART_Access *) UART5_BASE)
