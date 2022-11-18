/*
 * led.c
 *
 * Created: 11/10/2022 9:30:39 PM
 *  Author: AmrAli
 */ 

#include "led.h"

 uint8_t stop = 0;

EN_LEDError_t LED_init(uint8_t ledPort, uint8_t ledPin)
{
	DIO_init(ledPort, ledPin, OUT);
	return LED_OK;
}

EN_LEDError_t LED_on(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort, ledPin, HIGH);
	return LED_OK;
}
EN_LEDError_t LED_off(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort, ledPin, LOW);
	return LED_OK;
}
EN_LEDError_t LED_blink_1(uint8_t ledPort, uint8_t ledPin)
{
	for (int i =0; i<9; i++)
	{
		if ( stop == 0)
		{
			DIO_toggle(ledPort, ledPin);
			_delay_ms(500);
		}
		else if (stop == 1)
		{
			break;
		}
		
	}
	
	return LED_OK;
}
EN_LEDError_t LED_blink_2(uint8_t ledPort, uint8_t ledPin)
{
		DIO_toggle(ledPort, ledPin);
		_delay_ms(200);
	
	return LED_OK;
}

EN_LEDError_t LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	DIO_toggle(ledPort, ledPin);
	_delay_ms(100);
	return LED_OK;
}

/* use timer0 for delay in the normal mode */
EN_LEDError_t delay_sec_normal(uint8_t numOfOverflow)
{
	uint8_t OVF_counter= 0;
	TIMER0_init_normal(0x00);
	//TIMER0_interrupt_enable();
	TIMER0_start(clk_1024);
	while(OVF_counter < numOfOverflow)
	{
		while((TIFR &(1<<TOV0)) == 0);    // Loop until an Overflow occur
		TIMER0_CLR_OVF();               // clear the overflow flag
		OVF_counter++;
	}
	TIMER0_stop();
	return LED_OK;
}

/*use timer2 for delay in pedestrian mode*/
EN_LEDError_t delay_sec_pedestrian(uint8_t numOfOverflow)
{
	uint8_t OVF_counter= 0;
	TIMER2_init_normal(0x00);
	//TIMER2_interrupt_enable();
	TIMER2_start(clk_1024);
	while(OVF_counter < numOfOverflow)
	{
		while((TIFR &(1<<TOV2)) == 0);    // Loop until an Overflow occur
		TIMER2_CLR_OVF();               // clear the overflow flag
		OVF_counter++;
	}
	TIMER2_stop();
	LED_off(PORT_B, PIN1);
	LED_off(PORT_A, PIN1);
	return LED_OK;
}

EN_LEDError_t LED_yellow_blink(void)
{
	uint8_t OVF_counter= 0;
	TIMER2_init_normal(0x00);
	TIMER2_start(clk_1024);
	while(OVF_counter < 20)
	{
		while((TIFR &(1<<TOV2)) == 0)
		{
			LED_toggle(PORT_A, PIN1);
			LED_toggle(PORT_B, PIN1);
		}
		TIMER2_CLR_OVF();               // clear the overflow flag
		OVF_counter++;
	}
	TIMER2_stop();
	LED_off(PORT_B, PIN1);
	LED_off(PORT_A, PIN1);
	return LED_OK;
}