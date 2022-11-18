/*
 * button.h
 *
 * Created: 11/11/2022 12:54:09 AM
 *  Author: AmrAli
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/INTERRUPTS/interrupts.h"
#include "../../MCAL/DIO/dio.h"

typedef enum EN_BUTTONError_t
{
	BUTTON_OK, BUTTON_ERROR
}EN_BUTTONError_t;

EN_BUTTONError_t BUTTON_init(uint8_t portNum, uint8_t pinNum);
EN_BUTTONError_t BUTTON_interruptInit(uint8_t buttonInterrupt, uint8_t buttonInterruptSense);




#endif /* BUTTON_H_ */