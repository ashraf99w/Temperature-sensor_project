/*
 * Button.c
 *
 * Created: 17/09/2021 10:17:43
 *  Author: ashraf
 */ 

#include "Dio.h"
void button_vInit(unsigned char portname,unsigned char pinnumber)
{
	Dio_vSetPinDir(portname,pinnumber,0);
}


unsigned char button_u8read_pin(unsigned char portname,unsigned char pinnumber)
{    
	unsigned char x;
	x=DIO_u8Read_pin(portname,pinnumber);
	return x;
}