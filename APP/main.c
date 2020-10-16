/*
 * main.c
 *
 *  Created on: Oct 13, 2020
 *      Author: elsay
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/Global Interrupt/GIE_INT.h"
#include "../MCAL/TIMER2/TIMER2_Int.h"
void timer2_func(void);
int main(void)
{
	DIO_VidSetPinDirection(DIO_PORTA, PIN0, OUTPUT);
	TMR2_OF_SetCallBack(timer2_func);

	TIMER2_INIT();
	//TIMER2_Timer_Counter(128);
	TIMER2_OverFlow_Interrupt_Enable();
	GIE_Vid_Enable();
	while(1)
	{

	}
	return 0;
}
void timer2_func(void)
{
	static u16 counter=0;
	counter++;
	if(counter==489)
	{
		DIO_u8TogglePinValue(DIO_PORTA, PIN0);
		counter=0;
	}
}
