/*
 * USART.c
 *
 * Created: 2/7/2016 1:44:14 PM
 *  Author: chinkasoni
 */ 


#include <avr/io.h>
#include <util/delay.h>

void init()
{
	UCSRB=0x08;
	//UCSRA=0x02;
	UCSRC=0x86;
	//UBRRH=0x00;
	UBRRL=51;
	
}
void usart_send(unsigned char i)
{
	while(!(UCSRA&(1<<UDRE)));
	UDR=i;
	
	
}


int main(void)
{
	init();
	unsigned char s[4]="yash";
	unsigned char l=4;
	unsigned char j=0;
    while(1)
    {
		usart_send(s[j++]);
		if(j>=l)
		{
				j=0;
				
		}
	
    }

}