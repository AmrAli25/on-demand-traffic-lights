/*
 * button.c
 *
 * Created: 11/11/2022 12:54:21 AM
 *  Author: AmrAli
 */ 

#include "button.h"

EN_BUTTONError_t BUTTON_init(uint8_t portNum, uint8_t pinNum)
{
	DIO_init(portNum, pinNum, IN);
	return BUTTON_OK;
}

EN_BUTTONError_t BUTTON_interruptInit(uint8_t buttonInterrupt, uint8_t buttonInterruptSense)
{
	switch(buttonInterrupt)
	{
		case INT_0:
			Ext_interrupt_init(buttonInterrupt, buttonInterruptSense);
			BUTTON_init(PORT_D, PIN2);
		break;
		case INT_1:
			Ext_interrupt_init(buttonInterrupt, buttonInterruptSense);
			BUTTON_init(PORT_D, PIN3);
		break;
		case INT_2:
			Ext_interrupt_init(buttonInterrupt, buttonInterruptSense);
			BUTTON_init(PORT_B, PIN2);
		break;	
	}
	return BUTTON_OK;
}