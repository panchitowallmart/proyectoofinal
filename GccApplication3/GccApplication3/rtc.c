/*
 * CFile1.c
 *
 * Created: 30/11/2024 03:08:12 p. m.
 *  Author: emili
 */ 


#include "rtc.h"

uint8_t bcd_to_decimal(uint8_t bcd) {
	return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

uint8_t DS3231_read_byte(uint8_t reg) {
	uint8_t data;

	I2C_start();
	I2C_write((DS3231_ADDR << 1) | 0);
	I2C_write(reg);
	I2C_start();
	I2C_write((DS3231_ADDR << 1) | 1);
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	data = TWDR;
	I2C_stop();

	return data;
}
