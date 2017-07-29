/*
 * timers.c
 *
 * Created: 1/23/2016 3:24:12 PM
 *  Author: chinkasoni
 */ 


#include <avr/io.h>
#include <util/delay.h>
int count;
sie();
int main(void)
{	
	
	TCCR0 = 0x01;
	TCNT0 = 0;
	TIMSK|=(1<<TOIE0);
	
	DDRD = 0xff;
    while(1);
}
ISR (TIMER0_OVF_vect)
{
	if(count==250)
	{
		PORTD=0xff;
	}
	else
	
	{
		count++;
	}
}