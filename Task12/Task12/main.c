/*
 * Task12.c
 *
 * Created: 2019-11-25 12:07:31 PM
 * Author : adams
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 10000000
#include <util/delay.h>



/*setup()
{
	SPCR |= (1<<SPE);
}*/

//uint8_t data = 5;
//uint8_t dataReceived;
//uint8_t i = 0;

void loop(uint8_t data)
{
	PORTB &= ~(1<<PB6);
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	data = SPDR;
	PORTB |= (1<<PB6);
	
}

void setup()
{
	SPCR |= (1<<SPE);
	SPCR |= (1<<MSTR);
	SPCR |= (1<<CPOL);
	
	DDRB |= (1<<PB3) | (1<<PB4) | (1<<PB5) | (1<PB6);
	
}


int main()
{
	setup();
	//while(1) loop();
	while(1)
	{
		
	
		for(uint8_t i=0; i>=128; i++)
			{
			loop(i);
			_delay_ms(200);
			}
	}
	
}