#include "gpio.h"

//###################################### USAGE ##########################################
void GPIO_Write_pin(GPIO_Access* GPIOx, uint8_t pin, uint8_t val){
    if(pin > 15)
        ERROR_HANDLER();

    GPIOx->BSRR = val ? (1<<pin) : ((1<<pin)<<16);
}

uint16_t GPIO_Read_pin(GPIO_Access* GPIOx, uint8_t pin){
    if(pin > 15)
        ERROR_HANDLER();

    return (uint16_t) GPIOx->IDR & (1<<pin);
}

//###################################### SETTINGS ########################################

void GPIOx_CLK_EN(GPIO_Access* GPIOx){
    uintptr_t GPIO_add = (uintptr_t) GPIOx; // addreses start at 0x48000000
    GPIO_add &= 0xffff;                     // get the last 2 bytes
    GPIO_add /= 1024;                       // each pointer points to a 1024 bytes long block in memory...
                                            // ...so this gets the number of the port passed into the function

    if( (RCC->AHB2ENR & (1 << GPIO_add)) == 0){
        RCC->AHB2ENR |= (1 << GPIO_add);
    }
}



void GPIO_Pin_Init(GPIO_Access* GPIOx, uint8_t pin, uint16_t setup){
    if(pin > 15)
        ERROR_HANDLER();
        
    // Not the most readable way to do this, I just had an idea and wanted to try it.
    // setup is a 16bit code generated from the set options from the header combined with the '|' operator
    // eg. set_GPIO_INPUT | set_GPIO_PULLDOWN

    GPIOx_CLK_EN(GPIOx);    //if clk for used port is not set - enable it

    uint16_t mask_check = setup >> 8; //first byte marks users intent to change value of a setting
    uint16_t base_mask = setup;       

    if(mask_check & GPIO_MODE_S){
        GPIOx->MODER &= ~( 3U << (2*pin) );
        GPIOx->MODER |= ( (base_mask & 3U) << (2*pin) );
    }

    if(mask_check & GPIO_OUTPUT_s){
        GPIOx->OTYPER &= ~(1U << pin);
        base_mask = (setup >> 2) & 1U;
        GPIOx->OTYPER |= ( base_mask << pin );
    }

    if(mask_check & GPIO_SPEED_S){
        GPIOx->OSPEEDR &= ~( 3U << (2*pin) );
        base_mask = (setup >> 3) & 3U;
        GPIOx->OSPEEDR |= ( base_mask << (2*pin));
    }

    if(mask_check & GPIO_PULL_S){
        GPIOx->PUPDR &= ~( 3U << (2*pin) );
        base_mask = (setup >> 5) & 3U;
        GPIOx->PUPDR |= ( base_mask << (2*pin) );
    }

    if(mask_check & GPIO_INITIAL_S){
        GPIOx->ODR &= ~( 1U << pin);
        base_mask = (setup >> 7) & 1U;
        GPIOx->ODR |= ( base_mask << pin);

    }
}