
#include "irq_handlers.h"

static volatile uint32_t s_tick = 0;
void SysTick_Handler(void){
    s_tick++;
}

void Delay(uint32_t n){

    uint32_t temp = s_tick;
    while(temp+n > s_tick){
    }
}