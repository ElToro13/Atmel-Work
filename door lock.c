/*
 * door_lock.c
 *
 * Created: 1/6/2016 9:11:45 PM
 *  Author: chinkasoni
 */ 


#include <avr/io.h>
#include <util/delay.h>
void com(char x)
{PORTC|= 0x04;
	PORTD=x;
	PORTC&=~0x02;
	PORTC&=~0x04;
	_delay_ms(100);
	PORTC|=0x04;
	_delay_ms(10);
}
void data(char x)
{PORTC|=0x04;
	PORTD=x;
	PORTC|=0x02;
	PORTC&=~0x04;
	_delay_ms(100);
	PORTC|=0x04;
	_delay_ms(10);
}


int main(void)
{	DDRB = 0x00;
	DDRC = 0xff;
	DDRD = 0xff;
   
    int i,q,y=0x00,z=0x0f;
		
		int l;
		char x[] = {"enter password"};
		
		
		com(0x01);
		com(0x0e);
		com(0x38);
		com(0x80);
		
		for(l=0;x[l]!='\0';l++)
		{
			data(x[l]);
		}
			
			for(i=0;i<4;i++)
			{
				while(PINB==0)
				{
					
				}				
			
			q=PINB;
			y|=q;
			
			com(0x01);
			com(0x0e);
			com(0x38);
			com(0x80);
			
			
				data('*');
				_delay_ms(800);
			com(0x01);
		
		
		
			}
	
		if(z==y)
		{
			int l;
			char x[] = {"password matched"};
			
			com(0x01);
			com(0x0e);
			com(0x38);
			com(0x80);
			
			for(l=0;x[l]!='\0';l++)
			{
				data(x[l]);
			}
		}
		else
		{
			int l;
			char x[] = {"try again"};
			
			com(0x01);
			com(0x0e);
			com(0x38);
			com(0x80);
			
			for(l=0;x[l]!='\0';l++)
			{
				data(x[l]); 
				
				
			}
			
		}
		return 0;
   }
		
	
	