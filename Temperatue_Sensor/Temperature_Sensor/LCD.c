/*
 * LCD.c
 *
 * Created: 27/08/2022 01:38:44 م
 *  Author: ashraf
 */ 

#include "LCD.h"

#include <util/delay.h>

void LCD_vInit(void)
{
	_delay_ms(80);
	#if defined eight_bits_mode
	DIO_set_port_direction('A',0xFF); //PORT A OUTPUT
	Dio_vSetPinDir('B',EN,1); //OUTPUT
	Dio_vSetPinDir('B',RW,1); //OUTPUT
	Dio_vSetPinDir('B',RS,1); //OUTPUT
	DIO_vWrite_pin('B',RW,0); //WRITE 0
	
	LCD_vSend_cmd(EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	
	#elif defined four_bits_mode
	Dio_vSetPinDir('A',4,1);
	Dio_vSetPinDir('A',5,1);
	Dio_vSetPinDir('A',6,1);
	Dio_vSetPinDir('A',7,1);
	Dio_vSetPinDir('B',EN,1);
	Dio_vSetPinDir('B',RW,1);
	Dio_vSetPinDir('B',RS,1);
	DIO_vWrite_pin('B',RW,0);
	LCD_vSend_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	LCD_vSend_cmd(FOUR_BITS); //4bit mode
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_OFF_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	#endif
}

static void send_falling_edge(void)
{
	DIO_vWrite_pin('b',EN,1);
	_delay_ms(2);
	DIO_vWrite_pin('b',EN,0);
	_delay_ms(1);
}

void LCD_vSend_cmd(char cmd)
{
	
	#if defined eight_bits_mode
	DIO_write_port('A',cmd);
	DIO_vWrite_pin('B',RS,0);
	send_falling_edge();

	#elif defined four_bits_mode
	write_high_nibble('A',cmd>>4);
	DIO_vWrite_pin('B',RS,0);
	send_falling_edge();
	write_high_nibble('A',cmd);
	DIO_vWrite_pin('B',RS,0);
	send_falling_edge();
	
	#endif
	_delay_ms(1); //the function can't make cmds needs more than a 1ms
}

void LCD_vSend_char(char data)
{
	#if defined eight_bits_mode
	DIO_write_port('A',data);
	DIO_vWrite_pin('B',RS,1);
	send_falling_edge();

	#elif defined four_bits_mode
	write_high_nibble('A',data>>4);
	DIO_vWrite_pin('B',RS,1);
	send_falling_edge();
	write_high_nibble('A',data);
	DIO_vWrite_pin('B',RS,1);
	send_falling_edge();
	
	#endif
    _delay_ms(1);
}

void LCD_vSend_string(char *data)
{
	while((*data)!='\0')
	{
		LCD_vSend_char(*data);
		data++;
	}

}

void LCD_clearscreen()
{
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);

}

void LCD_movecursor(char row,char coloumn)
{
	
	char data=0 ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	LCD_vSend_cmd(data);
	_delay_ms(1);
}