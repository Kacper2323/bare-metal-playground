#ifndef _GPIO_H
#define _GPIO_H

#include <stdint.h>
#include "main.h"

//########################## GPIO POSSIBLE SETTINGS ####################

// masks for GPIO_Pin_Init(), first byte codes if the user picked a setting, second byte codes the setting itself

#define GPIO_MODE_S             0b10000000
#define set_GPIO_INPUT          0b1000000000000000
#define set_GPIO_OUTPUT         0b1000000000000001
#define set_GPIO_ALT            0b1000000000000010
#define set_GPIO_ANALOG         0b1000000000000011

#define GPIO_OUTPUT_s           0b01000000
#define set_GPIO_PUSHPULL       0b0100000000000000
#define set_GPIO_OPENDRAIN      0b0100000000000100

#define GPIO_SPEED_S            0b00100000
#define set_GPIO_SPEED_LOW      0b0010000000000000
#define set_GPIO_SPEED_MED      0b0010000000001000
#define set_GPIO_SPEED_HIGH     0b0010000000010000
#define set_GPIO_SPEED_VHIGH    0b0010000000011000

#define GPIO_PULL_S             0b00010000
#define set_GPIO_NOPULL         0b0001000000000000
#define set_GPIO_PULLUP         0b0001000000100000
#define set_GPIO_PULLDOWN       0b0001000001000000

#define GPIO_INITIAL_S          0b00001000
#define set_GPIO_LOW            0b0000100000000000
#define set_GPIO_HIGH           0b0000100010000000

void GPIO_Write_pin(GPIO_Access* GPIOx, uint8_t pin, uint8_t val);
uint16_t GPIO_Read_pin(GPIO_Access* GPIOx, uint8_t pin);
void GPIO_Pin_Init(GPIO_Access* GPIOx, uint8_t pin, uint16_t setup);
void GPIOx_CLK_EN(GPIO_Access* GPIOx);

#endif
