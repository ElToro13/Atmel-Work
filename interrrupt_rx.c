/*
 * interrrupt_rx.c
 *
 * Created: 06-Jun-16 12:39:23 PM
 *  Author: chinkasoni
 */ 

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usart.h"
#include "lcd.h"

int main(void)
{	
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0xff;
	DDRD=0xf0;
	lcd_init();
	usart_init();
	sei();
	

	usart_string_transmit("ATE0\r\n");
_delay_ms(400);
	usart_string_transmit("AT\r\n");
_delay_ms(400);
	usart_string_transmit("AT+CMGF=1\r\n");
_delay_ms(400);
	lcd_command_write(0x01);
	usart_string_transmit("AT+CNMI=1,2,0,0,0\r\n");
_delay_ms(400);
	lcd_command_write(0x01);
		while(1)
		{
			
		}
}
 unsigned char x;
ISR(USART_RXC_vect)
{	
	x=usart_data_receive();	
	if( ((x>64) && (x<92)) || ((x>96) && (x <124)) || (x=='>') || (x=='=') )
	lcd_data_write(x);
	if(x=='Z')
	{
		PORTC|=0x01;
	}
	if(x=='X')
	{
		PORTC|=0x02;
	}
	if(x=='C')
	{
		PORTC|=0x04;
	}
	if(x=='V')
	{
		PORTC|=0x08;
	}
	if(x=='A')
	{
		PORTC&=~0x01;
	}
	if(x=='S')
	{
		PORTC&=~0x02;
	}
	if(x=='D')
	{
		PORTC&=~0x04;
	}
	if(x=='F')
	{
		PORTC&=~0x08;
	}
}
	

