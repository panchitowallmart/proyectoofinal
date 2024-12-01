/*
 * CFile1.c
 *
 * Created: 30/11/2024 03:07:29 p. m.
 *  Author: emili
 */ 


#include "lcd.h"

void LCD_write_nibble(uint8_t nibble, uint8_t mode) {
	uint8_t data = nibble | mode | (1 << LCD_BACKLIGHT);
	I2C_start();
	I2C_write(LCD_I2C_ADDR << 1);
	I2C_write(data | (1 << LCD_EN));
	_delay_us(50);
	I2C_write(data & ~(1 << LCD_EN));
	_delay_us(50);
	I2C_stop();
}

void LCD_send_cmd(uint8_t cmd) {
	uint8_t highnib = cmd & 0xF0;
	uint8_t lownib = (cmd << 4) & 0xF0;
	LCD_write_nibble(highnib, 0);
	LCD_write_nibble(lownib, 0);
	_delay_ms(5);
}

void LCD_send_data(uint8_t data) {
	uint8_t highnib = data & 0xF0;
	uint8_t lownib = (data << 4) & 0xF0;
	LCD_write_nibble(highnib, (1 << LCD_RS));
	LCD_write_nibble(lownib, (1 << LCD_RS));
	_delay_ms(5);
}

void LCD_init(void) {
	_delay_ms(50);
	LCD_write_nibble(0x30, 0);
	_delay_ms(5);
	LCD_write_nibble(0x30, 0);
	_delay_ms(5);
	LCD_write_nibble(0x30, 0);
	_delay_ms(5);
	LCD_write_nibble(0x20, 0);
	_delay_ms(5);
	LCD_send_cmd(0x28);
	LCD_send_cmd(0x0C);
	LCD_send_cmd(0x06);
	LCD_send_cmd(0x01);
	_delay_ms(5);
}

void LCD_print(const char* str) {
	while (*str) {
		LCD_send_data(*str++);
	}
}
