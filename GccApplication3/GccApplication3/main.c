/*
 * GccApplication3.c
 *
 * Created: 30/11/2024 03:00:38 p. m.
 * Author : emili
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "rtc.h"

int main(void) {
	uint8_t segundos, minutos, horas, dia, mes, anio;
	char buffer[20];

	I2C_init();
	LCD_init();

	while (1) {
		segundos = bcd_to_decimal(DS3231_read_byte(0x00));
		minutos = bcd_to_decimal(DS3231_read_byte(0x01));
		horas = bcd_to_decimal(DS3231_read_byte(0x02));
		dia = bcd_to_decimal(DS3231_read_byte(0x04));
		mes = bcd_to_decimal(DS3231_read_byte(0x05));
		anio = bcd_to_decimal(DS3231_read_byte(0x06));

		LCD_send_cmd(0x01);
		_delay_ms(10);

		LCD_send_cmd(0x80);
		snprintf(buffer, sizeof(buffer), "%02d/%02d/20%02d", dia, mes, anio);
		LCD_print(buffer);

		LCD_send_cmd(0xC0);
		snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", horas, minutos, segundos);
		LCD_print(buffer);

		_delay_ms(1000);
	}
}
