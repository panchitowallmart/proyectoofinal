/*
 * IncFile1.h
 *
 * Created: 30/11/2024 03:07:50 p. m.
 *  Author: emili
 */ 


#ifndef RTC_H
#define RTC_H

#include <avr/io.h>
#include "i2c.h"

#define DS3231_ADDR 0x68

uint8_t bcd_to_decimal(uint8_t bcd);
uint8_t DS3231_read_byte(uint8_t reg);

#endif
