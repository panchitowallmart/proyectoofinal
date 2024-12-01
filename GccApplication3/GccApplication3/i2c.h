/*
 * IncFile1.h
 *
 * Created: 30/11/2024 03:05:56 p. m.
 *  Author: emili
 */ 


#ifndef I2C_H
#define I2C_H

#include <avr/io.h>
#include <util/delay.h>

void I2C_init(void);
void I2C_start(void);
void I2C_stop(void);
void I2C_write(uint8_t data);

#endif
