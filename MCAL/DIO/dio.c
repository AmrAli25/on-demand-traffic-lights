/*
 * dio.c
 *
 * Created: 11/10/2022 9:01:34 PM
 *  Author: AmrAli
 */ 


#include "dio.h"

/* 1. this function initialize the DIO register as CLEAR the bit if INPUT & SET the bit if OUTPUT*/

EN_DIOError_t DIO_init(uint8_t portNum, uint8_t pinNum, uint8_t direction)
{
	
	switch(portNum)
	{
		case PORT_A:
		if (direction == IN)
		{
			DDRA &= ~(1<<pinNum);
		}
		else if (direction == OUT)
		{
			DDRA |= (1<< pinNum);
		}
		else
		{
			// error handling
			return DIO_ERROR;
		}
		break;
		case PORT_B:
		if (direction == IN)
		{
			DDRB &= ~(1<<pinNum);
		}
		else if (direction == OUT)
		{
			DDRB |= (1<< pinNum);
		}
		else
		{
			// error handling
			return DIO_ERROR;
		}
		break;
		case PORT_C:
		if (direction == IN)
		{
			DDRC &= ~(1<<pinNum);
		}
		else if (direction == OUT)
		{
			DDRC |= (1<< pinNum);
		}
		else
		{
			// error handling
			return DIO_ERROR;
		}
		break;
		case PORT_D:
		if (direction == IN)
		{
			DDRD &= ~(1<<pinNum);
		}
		else if (direction == OUT)
		{
			DDRD |= (1<< pinNum);
		}
		else
		{
			// error handling
			return DIO_ERROR;
		}
		break;
	}
	return DIO_OK;
}

/* 2. this function write to the DIO register as CLEAR the bit if LOW & SET the bit if HIGH*/

EN_DIOError_t DIO_write(uint8_t portNum, uint8_t pinNum, uint8_t value)
{
	switch(portNum)
	{
		case PORT_A:
		if (value == LOW)
		{
			PORTA &= ~(1<<pinNum);
		}
		else if (value == HIGH)
		{
			PORTA |= (1<< pinNum);
		}
		else
		{
			// error handling
			return DIO_ERROR;
		}
		break;
		case PORT_B:
		if (value == LOW)
		{
			PORTB &= ~(1<<pinNum);
		}
		else if (value == HIGH)
		{
			PORTB |= (1<< pinNum);
		}
		else
		{
			// error handling
			return DIO_ERROR;
		}
		break;
		case PORT_C:
		if (value == LOW)
		{
			PORTC &= ~(1<<pinNum);
		}
		else if (value == HIGH)
		{
			PORTC |= (1<< pinNum);
		}
		else
		{
			// error handling
			return DIO_ERROR;
		}
		break;
		case PORT_D:
		if (value == LOW)
		{
			PORTD &= ~(1<<pinNum);
		}
		else if (value == HIGH)
		{
			PORTD |= (1<< pinNum);
		}
		else
		{
			// error handling
			return DIO_ERROR;
		}
		break;
	}
	return DIO_OK;
}

/* 3. toggle the bit if the bit is 1 --> 0 if 0 --> 1*/

EN_DIOError_t DIO_toggle(uint8_t portNum, uint8_t pinNum)
{
	switch(portNum)
	{
		case PORT_A:
		PORTA ^= (1<<pinNum);
		break;
		case PORT_B:
		PORTB ^= (1<<pinNum);
		break;
		case PORT_C:
		PORTC ^= (1<<pinNum);
		break;
		case PORT_D:
		PORTD ^= (1<<pinNum);
		break;
	}
	return DIO_OK;
}

/*4. read the bit from the register */
EN_DIOError_t DIO_read(uint8_t portNum, uint8_t pinNum, uint8_t *value)
{
	switch(portNum)
	{
		case PORT_A:
		*value = (PINA & (1<<pinNum)) >> pinNum;
		break;
		case PORT_B:
		*value = (PINB & (1<<pinNum)) >> pinNum;
		break;
		case PORT_C:
		*value = (PINC & (1<<pinNum)) >> pinNum;
		break;
		case PORT_D:
		*value = (PIND & (1<<pinNum)) >> pinNum;
		break;
	}
	return DIO_OK;
}

