/*
 * dot_matrix.c
 *
 * Created: 1/10/2016 6:37:27 PM
 *  Author: chinkasoni
 */ 


#include <avr/io.h>
#include <util/delay.h>
int main(void)
{  DDRC = 0xff;
	DDRD = 0xff;
    while(1)
    {
      
	 int i,k;
	char x[] = {0x10,0x08,0x04,0x02,0x01};
	char y[] = {0x10,0x08,0x7c,0x08,0x10};
	char z[] = {0x08,0x04,0x7e,0x04,0x08};
	char d[] = {0x04,0x02,0x7f,0x02,0x04};
				for(k=0;k<=10;k++)
				{
					
				
				for(i=0;i<=4;i++)
				{
					PORTC = x[i];
					PORTD = ~y[i];
					
					_delay_ms(10);
					PORTC = 0x00;
					PORTD = 0xff;
					
				}	
				}
				
			for (k=0;k<=10;k++)
				{
					for(i=0;i<=4;i++)
					{
					PORTC = x[i];
					PORTD = ~z[i];
					
					_delay_ms(10);
					PORTC = 0x00;
					PORTD = 0xff;
					}
				}
				
				for(k=0;k<=10;k++)
				{
					
					
					for(i=0;i<=4;i++)
					{
						PORTC = x[i];
						PORTD = ~d[i];
						
						_delay_ms(10);
						PORTC = 0x00;
						PORTD = 0xff;
						
					}
				}
				
				
				
			
				
				
				
		
    }
}