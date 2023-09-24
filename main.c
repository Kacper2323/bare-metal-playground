#include "main.h"
#include "irq_handlers.h"
#include "gpio.h"
#include "usart.h"
#include "stdio.h"

int main(void){

    SysTick_Init();
    Init_Debug_Uart();
    
    char s[25];
    sprintf(s, "Hello World%d\n f", 45);

    //RCC->CCIPR |= 4U;

    uint16_t setup = set_GPIO_INPUT | set_GPIO_NOPULL;
    GPIO_Pin_Init(GPIOC, 13, setup);

    setup = set_GPIO_OUTPUT | set_GPIO_NOPULL;
    GPIO_Pin_Init(GPIOA, 5, setup);

    setup = set_GPIO_ALT | set_GPIO_SPEED_VHIGH;
    GPIO_Pin_Init(GPIOA, 2, setup);
    GPIO_Pin_Init(GPIOA, 3, setup);
    GPIOA->AFRL |= (7 << 12);
    GPIOA->AFRL |= (7 << 8);

    GPIO_Write_pin(GPIOA, 5, 0);

    UART_Tx(UART2, (uint8_t *)s, 14);
    while(1){
      //check for TXE
      //Write buffer
      //repeat
      //at the end check TC1


      if( GPIO_Read_pin(GPIOC, 13) != 0)
        GPIO_Write_pin(GPIOA, 5, 0);
      else
        GPIO_Write_pin(GPIOA, 5, 1);

    }
    return 0;
}


void ERROR_HANDLER(void){
  while(1){};
}

void SysTick_Init(void){
    SysTick->LOAD = 4000-1;
    SysTick->CTRL |= 7U;
}
