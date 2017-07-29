/*
 * usart_2.c
 *
 * Created: 2/7/2016 3:04:22 PM
 *  Author: chinkasoni
 */ 


#include <avr/io.h>
#include <util/delay.h>


	

void com(char i)
{PORTC|=0x01;
	PORTB=i;
	PORTC&=~0x02;
	PORTC&=~0x01;
	_delay_ms(100);
	PORTC|=0x01;
	_delay_ms(10);
}
void data(char i)
{PORTC|=0x01;
	PORTB=i;
	PORTC|=0x02;
	PORTC&=~0x01;
	_delay_ms(100);
	PORTC|=0x01;
	_delay_ms(10);
}



int main(void)
{	
	UCSRB=0x10;
	//UCSRA=0x02;
	UCSRC=0x86;
	//UBRRH=0x00;
	UBRRL=51;
	
	char i=0;
	int p,j=0x80;
	DDRB=0xff;
	DDRC=0xff;
	DDRD=0xff;
		for(p=0;p<=6;p++)
		{
			
		while(!(UCSRA & (1<<RXC)));
		i=UDR;
		_delay_ms(100);
		
		
		//com(0x01);
		com(0x0e);
		com(0x38);
		com(j);
		_delay_ms(100);
		data(i);
		j++;
		p++;
		}
	
			
    

}