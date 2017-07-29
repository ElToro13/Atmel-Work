/*
 * lcd32.c
 *
 * Created: 2/7/2016 3:24:40 PM
 *  Author: chinkasoni
 */ 


#include <avr/io.h>
#include <util/delay.h>

void command(unsigned char x)
{
	PORTD=x;
  PORTC&=~0x01;
   PORTC|=0x02;
   _delay_ms(2);
    PORTC&=~0x02;
}
void ldata(int k)
{
	PORTD=k;
	PORTC|=0x01;
	PORTC|=0x02;
	_delay_ms(2);
	PORTC&=~0x02;
}

void lcd_init()
{	
	command(0x01);
	command(0x38);
	command(0x0e);
	command(0x06);
	command(0x80);
	
}

void name(char *p)
{
	while(*p)
	{
		ldata(*p);
		p++;
	}
}
int main(void)
{
	char x[]="Temp = ";
	char g[]="* C";
	int i=0,k=3;
	DDRC=0xff; 
	DDRA=0x00;
	DDRD=0xff;
	lcd_init();
	 name(x);
	int f=0x89,w=0x88;
    while(1)
    {
		  
         if((PINA&0x01)==1)
		 {
			 command(0x01);
			  
			 
			   name(x);
			  
			  command(f);
			 
			
			 ldata(i+48); 
			 
				command(w);
			 ldata(k+48);
			 command(0x8a);
			 name(g);
			 i++;
			 if(k==10)
			 {
				 k&=0;
			 }
			 if(i==10)
			 {
				 i&=0;
				
				 k++;
			 }
			 
			 while((PINA&0x01)==1); 
		 }
    }
}