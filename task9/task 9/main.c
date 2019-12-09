/*
 * task 9.c
 *
 * Created: 2019-11-14 10:38:18 AM
 * Author : adams
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


ISR(TIMER0_OVF_vect)
{
	PORTD &= ~(1<<PD1); 
}
ISR(TIMER0_COMPA_vect)
{
	PORTD |= (1<<PD1);
}

void loop()
{
}

void setup()
{
	DDRD |= (1<<PD1); //set to output pin
	
	PORTD &= ~(1<<PD1); //start pin as 0
	TCCR0B = 0x01; //hexadecimal 11, operate in normal counting mode not scaling clock
	//TCCR0A |= (1<<COM0A0);
	//TCCR0A |= (1<<WGM01) | (WGM00);
	//TCCR0B |= (1<<WGM02);
	
	
	TIMSK0 = 3; //enables timer overflow interrupt
	
	OCR0A = 50;
	OCR0B = 250; 
	
	sei(); //start listening to interrupt
}
int main()
{
	setup();
	while(1) loop();
}
