#ifndef _USART_IN
#define _USART_IN

#include "main.h"

#define _enable_uart_Tx(UARTx)     ( UARTx->CR1 |= (1U << 3) );
#define _disable_uart_Tx(UARTx)    ( UARTx->CR1 &= ~(1U << 3) );

void UART_Tx(UART_Access* UARTx, uint8_t* buffer, int buff_len);
void Init_Debug_Uart(void);

#endif