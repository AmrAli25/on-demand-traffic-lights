/*
 * dio.h
 *
 * Created: 11/10/2022 9:01:23 PM
 *  Author: AmrAli
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/micro_config.h"
#include "../../Utilities/types.h"

// Direction defines
#define  OUT		1     /*As an OUTPUT*/
#define  IN		    0	  /*As an INPUT*/

// Value defines
#define HIGH        1
#define LOW         0

// all driver macros
#define  PORT_A		'A'
#define  PORT_B		'B'
#define  PORT_C		'C'
#define  PORT_D		'D'

// pins definition
#define  PIN0		 0
#define  PIN1		 1
#define  PIN2		 2
#define  PIN3		 3
#define  PIN4		 4
#define  PIN5		 5
#define  PIN6		 6
#define  PIN7		 7


typedef enum EN_DIOError_t
{
	DIO_OK, DIO_ERROR
}EN_DIOError_t;

// all driver functions prototypes

EN_DIOError_t DIO_init(uint8_t portNum, uint8_t pinNum, uint8_t direction);

EN_DIOError_t DIO_write(uint8_t portNum, uint8_t pinNum, uint8_t value);

EN_DIOError_t DIO_toggle(uint8_t portNum, uint8_t pinNum);

EN_DIOError_t DIO_read(uint8_t portNum, uint8_t pinNum, uint8_t *value);



#endif /* DIO_H_ */