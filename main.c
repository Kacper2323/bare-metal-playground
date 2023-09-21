#include "drivemap.h"
//#include "irq_handlers.h"


static void Ddelay(int n){
  volatile int c = 0;
    while(c < n){
      c++;
    }
}


int j = 0;
int main(void){

    RCC->AHB2ENR &= ~(1U);
    RCC->AHB2ENR |= 1;

    GPIOA->MODER &= ~(3U<<10);
    GPIOA->MODER |= (1U<<10);

    GPIOA->PUPDR &= ~(3U<<10);
    GPIOA->ODR &= ~(1U<<5);
    // GPIOA->ODR |= (1<<5);

    while(1){

      Ddelay(99999);
      GPIOA->ODR |= (1<<5);
      j = 0;

      Ddelay(99999);
      GPIOA->ODR &= ~(1U<<5);
      j = 0;

    }
    return 0;
}
