/*
 * timers.c
 *
 * Created: 11/10/2022 9:16:16 PM
 *  Author: AmrAli
 */ 

#include "timers.h"

/*1. initialize the timer0 to be in normal mode and give it the initial value to get accurate ticks */
EN_TIMERSError_t TIMER0_init_normal(uint8_t initial_value)
{
	TCCR0 = 0x00;  // Normal mode
	TCNT0 = initial_value;
	
	return TIMERS_OK;
}

/*2. start the timer by determining the prescaler */
EN_TIMERSError_t TIMER0_start(uint8_t prescaler)
{
	switch(prescaler)
	{
		case no_prescaler:
		TCCR0 |= 0x01;
		break;
		case clk_8:
		TCCR0 |= 0x02;
		break;
		case clk_64:
		TCCR0 |= 0x03;
		break;
		case clk_256:
		TCCR0 |= 0x04;
		break;
		case clk_1024:
		TCCR0 |= 0x05;
		break;
	}
	return TIMERS_OK;
}

EN_TIMERSError_t TIMER0_stop(void)
{
	TCCR0 = 0x00; // stop the timer0
	return TIMERS_OK;
}

EN_TIMERSError_t TIMER0_interrupt_enable(void)
{
	SREG  |=(1<<PIN7);    // enable global interrupt bit
	TIMSK |=(1<<TOIE0);	  // set the TOIE0 bit
	return TIMERS_OK;
}
EN_TIMERSError_t TIMER0_CLR_OVF(void)
{
	TIFR |=(1<<TOV0);   // Clear the flag by Setting the TOV0 bit to 1
	return TIMERS_OK;
}



/* if i want to make a delay i need to check the ovf and clear it by SET the bit OVF*/

/************************************************************************/
/*                         Timer2                                       */
/************************************************************************/

/*1. initialize the timer2 to be in normal mode and give it the initial value to get accurate ticks */
EN_TIMERSError_t TIMER2_init_normal(uint8_t initial_value)
{
	TCCR2 = 0x00;  // Normal mode
	TCNT2 = initial_value;
	
	return TIMERS_OK;
}

/*2. start the timer by determining the prescaler */
EN_TIMERSError_t TIMER2_start(uint8_t prescaler)
{
	switch(prescaler)
	{
		case no_prescaler:
		TCCR2 |= 0x01;
		break;
		case clk_8:
		TCCR2 |= 0x02;
		break;
		case clk_64:
		TCCR2 |= 0x03;
		break;
		case clk_256:
		TCCR2 |= 0x04;
		break;
		case clk_1024:
		TCCR2 |= 0x05;
		break;
	}
	return TIMERS_OK;
}

EN_TIMERSError_t TIMER2_stop(void)
{
	TCCR2 = 0x00; // stop the timer0
	return TIMERS_OK;
}

EN_TIMERSError_t TIMER2_interrupt_enable(void)
{
	SREG  |=(1<<PIN7);    // enable global interrupt bit
	TIMSK |=(1<<TOIE2);	  // set the TOIE2 bit
	return TIMERS_OK;
}

EN_TIMERSError_t TIMER2_CLR_OVF(void)
{
	TIFR |=(1<<TOV2);    // Clear the flag by setting the TOV2 bit
	return TIMERS_OK;
}