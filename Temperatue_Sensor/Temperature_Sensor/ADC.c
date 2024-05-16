/*
 * ADC.c
 *
 * Created: 28/09/2021 10:49:35
 *  Author: ashraf
 */ 
#include "Macros.h"
#include <avr/interrupt.h>

void ADC_vinit(unsigned char ref_volt,unsigned char enable_interrupt_INT0
,unsigned char enable_DIFRENTIAL_MODE,unsigned char ENABLE_ADC_INTERRUPT)
{
	switch (ref_volt)
	{
		case 0:  //configure AREF
		Clear_bit(ADMUX,REFS0);
		Clear_bit(ADMUX,REFS1);
		break;
		
		case 1: //configure AVCC
		Set_bit(ADMUX,REFS0);
		break;
		
		case 3://INTERNAL 2.56 VOLT
		Set_bit(ADMUX,REFS0);
		Set_bit(ADMUX,REFS1);
		
		break;
	}

	Set_bit(ADCSRA,ADEN); // enable ADC
	
	/* adjust ADC clock*/
	Set_bit(ADCSRA,ADPS2);
	Set_bit(ADCSRA,ADPS1);
	
	//EXTERNAL INTERRUPT REQUEST ZERO
	if (1==enable_interrupt_INT0)
	{
		Set_bit(ADCSRA,ADATE);//auto trigger on rising edge of INT0
		Set_bit(SFIOR,ADTS1);
	}
	if(1==enable_DIFRENTIAL_MODE)
	{
		/* diffrential mode */
		Clear_bit(ADMUX,MUX0);
		Clear_bit(ADMUX,MUX1);
		Clear_bit(ADMUX,MUX2);
		Clear_bit(ADMUX,MUX3);
		Set_bit(ADMUX,MUX4);
	}
	if (1==ENABLE_ADC_INTERRUPT)
	{
		sei();
		Set_bit(ADCSRA,ADIE);
		
	}
	
}


unsigned short ADC_u16Read(void)
{
	unsigned short read_val;
	Set_bit(ADCSRA,ADSC);
	while(Read_bit(ADCSRA,ADSC)==1);
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val ;
}

unsigned short ADC_u16Read_EXTERNAL_INTERRUPT0(void)
{
	unsigned short read_val;
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val ;
}