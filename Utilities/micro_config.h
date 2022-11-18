/*
 * micro_config.h
 *
 * Created: 11/10/2022 8:58:55 PM
 *  Author: AmrAli
 */ 


#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_


#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif

#define __AVR_ATmega32__

#define SREG  (*((volatile uint8_t*) 0x5F))

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#endif /* MICRO_CONFIG_H_ */