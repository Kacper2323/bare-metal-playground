#include "drivemap.h"
#include "irq_handlers.h"


int j = 0;
int main(void){
    SysTick->LOAD = 4000-1;
    SysTick->CTRL |= 7U;

    RCC->AHB2ENR &= ~(1U);
    RCC->AHB2ENR |= 1;

    GPIOA->MODER &= ~(3U<<10);
    GPIOA->MODER |= (1U<<10);

    GPIOA->PUPDR &= ~(3U<<10);
    GPIOA->ODR &= ~(1U<<5);
    // GPIOA->ODR |= (1<<5);

    while(1){

      Delay(500);
      GPIOA->ODR |= (1<<5);
      j = 0;

      Delay(500);
      GPIOA->ODR &= ~(1U<<5);
      j = 0;

    }
    return 0;
}
