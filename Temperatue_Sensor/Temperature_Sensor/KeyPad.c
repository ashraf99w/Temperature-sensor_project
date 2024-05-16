/*
 * KeyPad.c
 *
 * Created: 13/09/2022 08:43:24 م
 *  Author: ashraf
 */ 
#include "Dio.h"
#define NOTPRESSED  0xff

void keypad_vInit(char port)
{
	 DIO_set_port_direction(port,0x0f);
	 DIO_vEnable_Internal_PULLUP(port,4,1);
	 DIO_vEnable_Internal_PULLUP(port,5,1);
	 DIO_vEnable_Internal_PULLUP(port,6,1);
	 DIO_vEnable_Internal_PULLUP(port,7,1);

}
char keypad_u8check_press(char port)
{
	char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	char row,coloumn,x;
	char returnval=NOTPRESSED;
	for(row=0;row<4;row++)
	{
				DIO_vWrite_pin(port,0,1);
				DIO_vWrite_pin(port,1,1);
				DIO_vWrite_pin(port,2,1);
				DIO_vWrite_pin(port,3,1);
				
				DIO_vWrite_pin(port,row,0);
				for(coloumn=0;coloumn<4;coloumn++)
				{
					x=DIO_u8Read_pin(port,(coloumn+4));
					if(x==0)
					{
						returnval=arr[row][coloumn];
						break;// you need to get out the small for loop and the
						      //big for loop here you get out the small for
					}
				}
				if(x==0)
				{
					break;// you get out the big for
				}
			
	}
		 return returnval ;
}