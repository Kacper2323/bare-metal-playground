#include "usart.h"



void UART_Tx(UART_Access* UARTx, uint8_t* buffer, int buff_len){

    _enable_uart_Tx(UARTx);

    for(int i=0; i<buff_len; i++){
        while( (UARTx->ISR &= (1U << 7)) == 0 ){};

        UARTx->TDR = buffer[i];
    }

    while( (UARTx->ISR &= (1U << 6)) == 0){};

    _disable_uart_Tx(UARTx);
}

void Init_Debug_Uart(void){
    if( (RCC->APB1ENR1 & (1U << 17)) == 0){
        RCC->APB1ENR1 |= (1U << 17);  // turn on clk for APB1
    }

    UART2->CR1 &= ~(1U<<28);          //
    UART2->CR1 &= ~(1U<<12);          // 8 bit data
    UART2->BRR |= 4000000U / 115200U; //4M is clk, make it variable when system_clk_init is done ##################
    UART2->CR2 &= ~(3U << 12);        // 1 stop bit
    UART2->CR1 |= 1U;                 //enable UART2
}