/*
 * Temperature_Sensor.c
 *
 * Created: 11/05/2024 11:34:35 م
 * Author : ashraf
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "ADC.h"
#include "LCD.h"



int main(void)
{
    LCD_vInit();
	ADC_vinit(3,0,1,0);
	LCD_clearscreen();
	LCD_vSend_string("temp=");
	unsigned short Volt_mv;
	unsigned char temp;
	
    while (1) 
    {
		Volt_mv=ADC_u16Read()*2.5;
		if (Volt_mv >= 1000)
		{
			temp=(Volt_mv-1000)/10;
			LCD_movecursor(1,6);
			
		}
		else 
		{ 
			temp=(1000-Volt_mv)/10;
			LCD_movecursor(1,6);
			LCD_vSend_char('-');
		
		}
		
		if (temp<10)
		{
			
			LCD_vSend_char((temp)+48);
			LCD_vSend_char(0xDF);//ascii of degree
			LCD_vSend_char('c');
			LCD_vSend_char(0x20);//nothing
			

			
		}
		else if (temp > 10)
		{

			LCD_vSend_char((temp/10)+48);
			LCD_vSend_char((temp%10)+48);
			LCD_vSend_char(0XDF);//ascii of degree
			LCD_vSend_char('c');

		}
		
    }
}

