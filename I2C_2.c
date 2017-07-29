/*
 * I2C_2.c
 *
 * Created: 2/20/2016 1:21:11 PM
 *  Author: chinkasoni
 */ 


#include <avr/io.h>
#include <util/delay.h>


void com(char x)
{
	PORTD|=0x01;
	PORTB=x;
	PORTD&=~0x02;
	PORTD&=~0x01;
	_delay_ms(100);
	PORTD|=0x01;
	_delay_ms(10);
}
void data(char x)
{   PORTD|=0x01;
	PORTB=x;
	PORTD|=0x02;
	PORTD&=~0x01;
	_delay_ms(100);
	PORTD|=0x01;
	_delay_ms(10);
}

int main(void)
{
	
	
	DDRB=0xff;
	DDRD=0xff;
	while(1)
	{
	data('a');
	_delay_ms(1000);	
	}
	
	}