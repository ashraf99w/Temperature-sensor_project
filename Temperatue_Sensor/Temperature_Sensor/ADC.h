/*
 * ADC.h
 *
 * Created: 28/09/2021 10:49:18
 *  Author: ashraf
 */ 


#ifndef ADC_H_
#define ADC_H_



/*
	Function Name        : ADC_vinit
	Function Returns     : void
	Function Arguments   : unsigned char ref_volt  ,unsigned char enable_interrupt,
	                       unsigned char enable_DIFRENTIAL_MODE
	Function Description : 1-AUTO TRIGGERING WITH EXTERNAL INTERRUPT 0 IF enable_interrupt==1
	                       2-enables diffrential mode if enable_DIFRENTIAL_MODE==1
						   3-ref_volt==0 --->AREF CONFIGURED
						     ref_volt==1 --->AVCC CONFIGURED
							 ref_volt==3 --->internal 2.56 volt CONFIGURED
							4- ENABLE_ADC_INTERRUPT ==1 --->ADC Interrupt enabled
						   
*/
void ADC_vinit(unsigned char ref_volt,unsigned char enable_interrupt_INT0
,unsigned char enable_DIFRENTIAL_MODE,unsigned char ENABLE_ADC_INTERRUPT);






/*
	Function Name        : ADC_u16Read
	Function Returns     : unsigned short
	Function Arguments   : void 
	Function Description : this function makes one conversion and returns the corresponding
	                       10-bits
*/
unsigned short ADC_u16Read(void);




/*
	Function Name        : ADC_u16Read_EXTERNAL_INTERRUPT0
	Function Returns     : unsigned short
	Function Arguments   : void 
	Function Description : this function makes one conversion and returns the corresponding
	                       10-bits but when working with external int0 on its rising edge
*/
unsigned short ADC_u16Read_EXTERNAL_INTERRUPT0(void);



#endif /* ADC_H_ */