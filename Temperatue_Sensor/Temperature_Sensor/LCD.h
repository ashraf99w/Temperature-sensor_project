/*
 * LCD.h
 *
 * Created: 27/08/2022 01:38:26 م
 *  Author: ashraf
 */ 


#ifndef LCD_H_
#define LCD_H_

	#include "Dio.h"
	#include "LCD_config.h"
	#define CLR_SCREEN 0x01
	#define RETURN_HOME 0x02
	#define CURSOR_ON_DISPLAN_ON 0x0E
	#define CURSOR_OFF_DISPLAN_ON 0x0C
	#define ENTRY_MODE 0x06

	#if defined four_bits_mode
	#define EN 0
	#define RS 1
	#define RW 2
	#define FOUR_BITS 0x28

	#elif defined eight_bits_mode
	#define EN 0
	#define RS 1
	#define RW 2
	#define EIGHT_BITS 0x38

    #endif
/*
	Function Name        : LCD_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize lcd as 8-bit mode or 4-bit mode 
	                       depending on LCD_config.h
*/
	void LCD_vInit(void);
	
/*
	Function Name        : send_falling_edge
	Function Returns     : void
	Function Arguments   : void
	Function Description : sends the needed pulse on E(enable pin) this function 
	                       is used in the LCD.c file only
*/
	static void send_falling_edge(void);
/*
	Function Name        : LCD_vSend_cmd
	Function Returns     : void
	Function Arguments   : char cmd
	Function Description : sends the command weather working in 4-bits mode
	                       or 8-bits mode
*/
	void LCD_vSend_cmd(char cmd);
/*
	Function Name        : LCD_vSend_char
	Function Returns     : void
	Function Arguments   : char data
	Function Description : sends the data weather working in 4-bits mode
	                       or 8-bits mode
*/
	void LCD_vSend_char(char data);
/*
	Function Name        : LCD_vSend_string
	Function Returns     : void
	Function Arguments   : char *data
	Function Description : sends the string to be displayed weather we are 
	                       working 4-bits mode or 8-bits mode 
*/	
	void LCD_vSend_string(char *data);
/*
	Function Name        : LCD_clearscreen
	Function Returns     : void
	Function Arguments   : void
	Function Description : clears the screen
*/	
	void LCD_clearscreen();
/*
	Function Name        : LCD_movecursor
	Function Returns     : void
	Function Arguments   : char row,char coloumn
	Function Description : move the cursor to the position determined by the
	                       row and coloumn values
*/	
	void LCD_movecursor(char row,char coloumn);


#endif /* LCD_H_ */