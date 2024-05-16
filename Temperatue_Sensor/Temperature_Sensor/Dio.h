/*
 * Dio.h
 *
 * Created: 15/09/2021 14:24:29
 *  Author: ashraf
 */ 



#ifndef DIO_H_
#define DIO_H_

/*
		>>Tested<<
		Function Name        : DIO_vSetPinDir
		Function Returns     : void
		Function Arguments   : unsigned char portname,unsigned char pin number,unsigned char direction
		Function Description : Set the direction of the given pin in the given port (direction---->( 0 = input : 1 = output))
*/
void Dio_vSetPinDir(unsigned char port,unsigned char pin ,unsigned char direction);

/*
		>>Tested<<
		Function Name        : DIO_vWrite_pin
		Function Returns     : void
		Function Arguments   : unsigned char portname,unsigned char pin number,unsigned char output value
		Function Description : Set the value of the given pin in the given port (output value--->(0 = low : 1 = high))
*/
void DIO_vWrite_pin(unsigned char port,unsigned char pin,unsigned char value);


/*
		>>Tested<<
		Function Name        : DIO_vtoggle_pin
		Function Returns     : void
		Function Arguments   : unsigned char portname,unsigned char pin number
		Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_vToggle_pin(unsigned char port,unsigned char pin);


/*
		>>Tested<<
		Function Name        : DIO_u8read_pin
		Function Returns     : unsigned char
		Function Arguments   : unsigned char portname,unsigned char pin number
		Function Description : Returns 1 if the value of the given pin is high and 0 if the value is low
*/
unsigned char DIO_u8Read_pin(unsigned char port,unsigned char pin);


/*
		>>Tested<<
		Function Name        : DIO_set_port_direction
		Function Returns     : void
		Function Arguments   : unsigned char portname,unsigned char direction
		Function Description : set the direction of whole port .
*/
void DIO_set_port_direction(unsigned char portname,unsigned char direction);


/*
		>>Tested<<
		Function Name        : DIO_write_port
		Function Returns     : void
		Function Arguments   : unsigned char portname,unsigned char port value
		Function Description : Write the value to all port pins.
*/
void DIO_write_port(unsigned char portname,unsigned char value);



/*
		Function Name        : DIO_u8Read_port
		Function Returns     : unsigned char
		Function Arguments   : unsigned char portname
		Function Description : read the value of the port .
*/

unsigned char DIO_u8Read_port(unsigned char portname);




/*
		>>Tested<<
		Function Name        : vToggle_port
		Function Returns     : void
		Function Arguments   : unsigned char portname
		Function Description : toggle the value of the port .
*/
void vToggle_port(unsigned char portname);



/*
		Function Name        : DIO_vEnable_Internal_PULLUP
		Function Returns     : void
		Function Arguments   : char portname ,char pin number, char Enable
		Function Description : Connect and disconnect internal pull up resistor to the given pin at the given port 
*/
void DIO_vEnable_Internal_PULLUP(unsigned char port,unsigned char pin,unsigned char Enable);


/*
        >>>TESTED<<<
		Function Name        : write_low_nibble
		Function Returns     : void
		Function Arguments   : char portname ,char value
		Function Description : write the low nibble of the value on the low nibble of the port 
*/
void write_low_nibble(unsigned char portname,unsigned char value);


/*
        >>>TESTED<<<
		Function Name        : write_high_nibble
		Function Returns     : void
		Function Arguments   : char portname ,char value
		Function Description : write the low nibble of the value on the high nibble of the port 
*/
void write_high_nibble(unsigned char portname,unsigned char value);


#endif /* DIO_H_ */