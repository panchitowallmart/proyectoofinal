/*
 * CFile1.c
 *
 * Created: 30/11/2024 03:06:27 p. m.
 *  Author: emili
 */ 


#include "i2c.h"

void I2C_init(void) {
	TWSR = 0x00;
	TWBR = 72;
	TWCR = (1 << TWEN);
}

void I2C_start(void) {
	TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
	while (!(TWCR & (1 << TWINT)));
}

void I2C_stop(void) {
	TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
	_delay_us(10);
}

void I2C_write(uint8_t data) {
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}
