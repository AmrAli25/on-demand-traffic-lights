/*
 * interrupts.c
 *
 * Created: 11/10/2022 9:24:22 PM
 *  Author: AmrAli
 */ 


#include "interrupts.h"

EN_INTERRUPTSError_t Ext_interrupt_init(uint8_t interrupt, uint8_t interrupt_sense)
{
	switch(interrupt)
	{
		case INT_0:
		if (interrupt_sense == low_level)
		{
			SREG  &= ~(1<<PIN7);		// disable global interrupt
			GICR  |= (1<<INT0);		// enable INT number 0
			MCUCR &= ~0x00;			// trigger with low level    0000
			SREG  |= (1<<PIN7);		// enable global interrupt
		}
		else if (interrupt_sense == logical_change)
		{
			SREG  &= ~(1<<PIN7);		// disable global interrupt
			GICR  |= (1<<INT0);		// enable INT number 0
			MCUCR |= (1<<ISC00);			// trigger with logical change  0001
			MCUCR &= ~(1<<ISC01);
			SREG  |= (1<<PIN7);		// enable global interrupt
		}
		else if (interrupt_sense == falling_edge)
		{
			SREG &= ~(1<<PIN7);		// disable global interrupt
			GICR |= (1<<INT0);		// enable INT number 0
			MCUCR |= (1<<ISC01);	// trigger with falling edge 0010
			MCUCR &= ~(1<<ISC00);
			SREG |= (1<<PIN7);		// enable global interrupt
		}
		else if (interrupt_sense == rising_edge)
		{
			SREG &= ~(1<<PIN7);		// disable global interrupt
			GICR |= (1<<INT0);		// enable INT number 0
			MCUCR |= 0x03;	// trigger with falling edge 0011
			SREG |= (1<<PIN7);		// enable global interrupt
		}
		return INTERRUPTS_OK;
		break;
		case INT_1:
		if (interrupt_sense == low_level)
		{
			SREG  &= ~(1<<PIN7);		// disable global interrupt
			GICR  |= (1<<INT1);		// enable INT number 0
			MCUCR &= ~0x00;			// trigger with low level    0000
			SREG  |= (1<<PIN7);		// enable global interrupt
		}
		else if (interrupt_sense == logical_change)
		{
			SREG  &= ~(1<<PIN7);		// disable global interrupt
			GICR  |= (1<<INT0);		// enable INT number 0
			MCUCR |= (1<<ISC10);			// trigger with logical change  0100
			MCUCR &= ~(1<<ISC11);
			SREG  |= (1<<PIN7);		// enable global interrupt
		}
		else if (interrupt_sense == falling_edge)
		{
			SREG &= ~(1<<PIN7);		// disable global interrupt
			GICR |= (1<<INT0);		// enable INT number 0
			MCUCR |= (1<<ISC11);	// trigger with falling edge 1000
			MCUCR &= ~(1<<ISC10);
			SREG |= (1<<PIN7);		// enable global interrupt
		}
		else if (interrupt_sense == rising_edge)
		{
			SREG &= ~(1<<PIN7);		// disable global interrupt
			GICR |= (1<<INT0);		// enable INT number 0
			MCUCR |= 0x0C;	// trigger with falling edge 1100
			SREG |= (1<<PIN7);		// enable global interrupt
		}
		return INTERRUPTS_OK;
		break;
	}
}