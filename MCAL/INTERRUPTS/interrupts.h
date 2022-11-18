/*
 * interrupts.h
 *
 * Created: 11/10/2022 9:25:26 PM
 *  Author: AmrAli
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../Utilities/micro_config.h"

// definitions
#define INT_0				 0
#define INT_1				 1
#define INT_2				 2

// sense definitions

#define low_level			 0
#define logical_change		 1
#define falling_edge		 2
#define rising_edge			 3

typedef enum EN_INTERRUPTSError_t
{
	INTERRUPTS_OK, INTERRUPTS_ERROR
}EN_INTERRUPTSError_t;


EN_INTERRUPTSError_t Ext_interrupt_init(uint8_t interrupt, uint8_t interrupt_sense);





#endif /* INTERRUPTS_H_ */