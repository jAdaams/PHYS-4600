/*
 * task10.c
 *
 * Created: 2019-11-21 12:00:52 PM
 * Author : adams
 */ 

#include <avr/io.h>
  // ADC bit-shift
  uint16_t lowbyte;
  uint16_t highbyte;
  uint16_t finalvalue;
  
void loop()
{
}

void setup()
{
	ADMUX |= (1 << REFS0) | (1<< MUX0); //Chosing ref source & input ch
	ADCSRA |= (1<<ADEN);         // Start Data aquisition
	
}

int main(void)
{
   setup();
   while(1) loop();
}

