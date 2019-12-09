/*
 * task7.c
 *
 * Created: 2019-11-07 10:11:36 AM
 * Author : adams
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t keep_going = 1;

void loop()
{
	
	PORTD |= (1 << PD1);//turn on
	_delay_ms(500);//delay half a second

	PORTD &= ~(1 << PD1);//turn off
	_delay_ms(500);//delay half a second


}

void setup()
{
	

}

int main()
{
	
	setup();
	while(keep_going) loop();

	return 0;

}

