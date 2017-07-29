/*
 * I2C.c
 *
 * Created: 2/20/2016 12:06:29 PM
 *  Author: chinkasoni
 */ 


#include <avr/io.h>
#include <util/delay.h>

void TWI_INIT(void)
{
	TWBR=0xff;
}

void TWI_START(void)
{
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
}

void TWI_WRITE(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
}

void TWI_STOP(void)
{
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);

}

int main(void)
{	
	
	
	
		
		TWI_INIT();
		TWI_START();
		TWI_WRITE(0b11110000);
		TWI_WRITE('a');
		TWI_STOP();
	
	while(1);
	return 0;
    
}