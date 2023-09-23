#include "main.h"
#include "irq_handlers.h"
#include "gpio.h"

int main(void){


    SysTick_Init();

    uint16_t setup = set_GPIO_INPUT | set_GPIO_NOPULL;
    GPIO_Pin_Init(GPIOC, 13, setup);

    setup = set_GPIO_OUTPUT | set_GPIO_NOPULL;
    GPIO_Pin_Init(GPIOA, 5, setup);

    GPIO_Write_pin(GPIOA, 5, 0);

    while(1){

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
