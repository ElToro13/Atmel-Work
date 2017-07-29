/*
 * button.c
 *
 * Created: 1/23/2016 11:46:28 AM
 *  Author: chinkasoni
 */ 


#include <avr/io.h>
#include <util/delay.h>
int main(void)
{DDRB = 0x00;
	DDRD = 0xff;
	DDRC=0xff;
	int i=0;
    while(1)
    { 
     while((PINB&0x01)==0x01)
	 { 
		 PORTD = 0x03;
		 _delay_ms(200);
		 PORTD = 0x00;
		 
	}   

	while((PINB&0x02)==0x02)
	{
		if(i==0)
		{
			
			while((PINB&0x02)==0x02)
			{
				PORTD = 0x01;
			}
		}
		
		i=i+1;
		
		if(i==2)
		{
			while((PINB&0x02)==0x02)
			{
				
			PORTD = 0x02;
			i&=0;
			}
		}
		
	}
	
	
}
	}