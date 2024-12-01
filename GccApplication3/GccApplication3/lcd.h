/*
 * IncFile1.h
 *
 * Created: 30/11/2024 03:07:04 p. m.
 *  Author: emili
 */ 


#ifndef LCD_H
#define LCD_H

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "i2c.h"

#define LCD_I2C_ADDR 0x27
#define LCD_EN 2
#define LCD_RW 1
#define LCD_RS 0
#define LCD_BACKLIGHT 3

void LCD_init(void);
void LCD_send_cmd(uint8_t cmd);
void LCD_send_data(uint8_t data);
void LCD_print(const char* str);

#endif
