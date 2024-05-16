/*
 * Button.h
 *
 * Created: 17/09/2021 10:17:17
 *  Author: ashraf
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
/*
    >>>TESTED<<<
	Function Name        : button_vInit
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : define the given pin in the given port as input pin
*/
void button_vInit(unsigned char portname,unsigned char pinnumber);



/*
    >>>TESTED<<< 
	Function Name        : button_u8read
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Returns 0 or 1 depend on the status of the button(pressed or not) 
	                       0-----> means not pressed , 1----->means pressed (for pull down connection)
						   1-----> means not pressed , 0----->means pressed (for pull up  connection)
*/
unsigned char button_u8read_pin(unsigned char portname,unsigned char pinnumber);



#endif /* BUTTON_H_ */